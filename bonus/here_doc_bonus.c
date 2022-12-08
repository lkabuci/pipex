#include "pipex_bonus.h"

static void	write_here_doc_to_fd(t_here_doc p)
{
	char	*line;
	size_t	delimiter_len;
	int		fd;

	delimiter_len = ft_strlen(p.delimiter);
	fd = open(p.tmp_file, O_TRUNC | O_RDWR | O_CREAT, 0666);
	if (fd == -1)
		exit_failure(errno, 1);
	while (1)
	{
		ft_putstr_fd("> ", 1);
		line = get_next_line(0);
		if (!line)
			return ;
		if (!ft_strncmp(p.delimiter, line, delimiter_len) &&
			*(line + delimiter_len) == '\n')
		{
			if (close(fd) == -1)
				exit_failure(errno, 1);
			return (free(line));
		}
		ft_putstr_fd(line, fd);
		free(line);
	}
}

static t_here_doc	*parse_here_doc(char **argv, char **envp)
{
	t_here_doc	*p;

	//NOTE - free at exit
	p = (t_here_doc *) malloc(sizeof(t_here_doc));
	if (!p)
		exit(EXIT_FAILURE);
	p->delimiter = argv[2];
	p->cmd1 = argv[3];
	p->args1 = ft_split(p->cmd1, ' ');
	p->path1 = get_path(p->args1[0], envp);
	p->cmd2 = argv[4];
	p->args2 = ft_split(p->cmd2, ' ');
	p->path2 = get_path(p->args2[0], envp);
	p->outfile = argv[5];
	p->tmp_file = "._here_doc_";
	if (pipe(p->pipeid) == -1)
		exit_failure(errno, 1);
	return (p);
}

static void	exec_cmd1(t_here_doc *p, char **envp)
{
	int	fd;

	fd = open(p->tmp_file, O_RDONLY);
	if (fd == -1)
	{
		ft_fprintf(2, "%s: can't open the tmp here_doc file", p->tmp_file);
		exit(128);
	}
	if (dup2(fd, 0) == -1)
		exit_failure(errno, 1);
	if (dup2(p->pipeid[1], 1) == -1)
		exit_failure(errno, 1);
	if (close(p->pipeid[0]) == -1)
		exit_failure(errno, 1);
	if (close(p->pipeid[1]) == -1)
		exit_failure(errno, 1);
	if (close(fd) == -1)
		exit_failure(errno, 1);
	if (unlink(p->tmp_file) == -1)
		exit_failure(errno, 1);
	if (execve(p->path1, p->args1, envp) == -1)
	{
		ft_fprintf(2, "bash: %s: command not found", p->cmd1);
		exit_failure(errno, 127);
	}
}

static void	exec_cmd2(t_here_doc *p, char **envp)
{
	int		fd;

	fd = open(p->outfile, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		exit_failure(errno, 1);
	if (dup2(fd, 1) == -1)
		exit_failure(errno, 1);
	if (close(fd) == -1)
		exit_failure(errno, 1);
	if (dup2(p->pipeid[0], 0) == -1)
		exit_failure(errno, 1);
	if (close(p->pipeid[1]) == -1)
		exit_failure(errno, 1);
	if (close(p->pipeid[0]) == -1)
		exit_failure(errno, 1);
	if (execve(p->path2, p->args2, envp) == -1)
	{
		ft_fprintf(2, "bash: %s: command not found", p->cmd2);
		exit_failure(errno, 127);
	}
}

void    here_doc(int argc, char **argv, char **envp)
{
	t_here_doc	*p;
	pid_t		pid1;
	pid_t		pid2;

	if (argc != 6 || ft_strncmp(argv[1], "here_doc", 8))
		return ;
	p = parse_here_doc(argv, envp);

	write_here_doc_to_fd(*p);
	pid1 = fork();
	if (pid1 == -1)
		exit_failure(errno, 1);
	if (pid1 == 0)
		exec_cmd1(p, envp);
	pid2 = fork();
	if (pid2 == -1)
		exit_failure(errno, 1);
	if (pid2 == 0)
		exec_cmd2(p, envp);
	at_exit_here_doc(p, &pid1, &pid2);
}
