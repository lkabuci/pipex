#include "pipex_bonus.h"

static void	del_cmd(void *content)
{
	free(((t_cmd *)content)->cmd);
	free_tab(((t_cmd *)content)->args);
	free(((t_cmd *)content)->path);
}

void	exec_first_cmd(t_params *p)
{
	t_cmd	*tmp;
	int		fd;
	pid_t	pid;

	tmp = p->cmds->content;
	pid = fork();
	if (pid == -1)
		exit_failure(errno, 1);
	if (pid == 0)
	{
		fd = open(p->file.infile, O_RDONLY);
		if (fd == -1)
			exit_failure(errno, 1);
		ft_dup2(fd, 0);
		ft_dup2(p->pipelines[1], 1);
		ft_close(fd);
		close_piplines(p);
		ft_execve(tmp->path, tmp->args, p->main.envp);
	}
}

void	exec_middle_cmds(t_params *p)
{
	int		i;
	pid_t	pid;
	t_cmd	*tmp;
	t_list	*list_of_cmds;

	i = 2;
	list_of_cmds = p->cmds->next;
	while (list_of_cmds->next)
	{
		tmp = list_of_cmds->content;
		pid = fork();
		if (pid == -1)
			exit_failure(errno, 1);
		if (pid == 0)
		{
			ft_dup2(p->pipelines[i - 2], 0);
			ft_dup2(p->pipelines[i + 1], 1);
			close_piplines(p);
			ft_execve(tmp->path, tmp->args, p->main.envp);
		}
		i += 2;
		list_of_cmds = list_of_cmds->next;
	}
}

void	exec_last_cmd(t_cmd *last_cmd, t_params *p)
{
	int		fd;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_failure(errno, 1);
	if (pid == 0)
	{
		fd = open(p->file.outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd == -1)
			exit_failure(errno, 1);
		ft_dup2(fd, 1);
		ft_dup2(p->pipelines[p->pipes_ports - 2], 0);
		ft_close(fd);
		close_piplines(p);
		ft_execve(last_cmd->path, last_cmd->args, p->main.envp);
	}
}

void	at_exit_pipeline(t_params *p)
{
	int	i;

	i = 0;
	close_piplines(p);	
	while (i < p->ncmd)
	{
		if (wait(NULL) == -1)
			exit_failure(errno, 1);
		i++;
	}
	ft_lstclear(&p->cmds, del_cmd);
	free(p->pipelines);
	exit(0);
}
