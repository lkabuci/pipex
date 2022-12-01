#include "pipex.h"

static void	execFirst(t_params *p)
{
	close(p->fd[0]);
	dup2(p->fd[1], STDOUT_FILENO);
	close(p->fd[1]);
	char **args;

	args = malloc(sizeof(char *) * ft_strlen(p->cmd1.cmd) +
		ft_strlen(p->cmd1.flag) + 1);
	args[0]	= p->cmd1.cmd;
	args[1]	= p->cmd1.flag;
	args[2]	= NULL;
	if (execve(p->cmd1.path, args, p->main_params.env) == -1)
	{
		perror(p->cmd1.cmd);
		free_tab(args);
		exit(0);
	}
}

static void	execSecond(t_params *p)
{
	char	**args;
	int		fd;

	args = malloc(sizeof(char *) * ft_strlen(p->cmd2.cmd) +
		ft_strlen(p->cmd2.flag) + 1);
	args[0]	= p->cmd2.cmd;
	args[1]	= p->cmd2.flag;
	args[2]	= NULL;
	fd = open(p->cmd2.file, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		perror(p->cmd2.file);
	dup2(fd, 1);
	close(fd);
	dup2(p->fd[0],0);
	close(p->fd[1]);
	close(p->fd[0]);
	if (execve(p->cmd2.path, args, p->main_params.env) == -1)
	{
		free_tab(args);
		fprintf(stderr, "ERROR in command 1 %s\n, %i", args[0], 5);
		perror(p->cmd2.cmd);
		exit(127);
	}
}

int main(int ac, char **av, char **env) 
{
	t_params	p;
	int			pid1;
	int			pid2;

	p.main_params.ac = ac;
	p.main_params.av = av;
	p.main_params.env = env;
	parsing(&p);
	if (pipe(p.fd) == -1)
	{
		perror("");
		exit(1);
	}
	pid1 = fork();
	if (!pid1)
		execFirst(&p);
	pid2 = fork();
	if (!pid2)
		execSecond(&p);
	close(p.fd[0]);
	close(p.fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (1);
}

