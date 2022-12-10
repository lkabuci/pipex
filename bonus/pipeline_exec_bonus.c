#include "pipex_bonus.h"

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
		if (dup2(fd, 0) == -1)
			exit_failure(errno, 1);
		if (dup2(p->pipelines[1], 1) == -1)
			exit_failure(errno, 1);
		if (close(fd) == -1)
			exit_failure(errno, 1);
		close_piplines(p);
		if (execve(tmp->path, tmp->args, p->main.envp) == -1)
		{
			ft_fprintf(2, "bash: %s: command not found", tmp->cmd);
			exit(127);
		}
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
			if (dup2(p->pipelines[i - 2], 0) == -1)
				exit_failure(errno, 1);
			if (dup2(p->pipelines[i + 1], 1) == -1)
			 	exit_failure(errno, 1);
			close_piplines(p);
			if (execve(tmp->path, tmp->args, p->main.envp) == -1)
			{
				ft_fprintf(2, "bash: %s: command not found", tmp->cmd);
				exit(127);
			}
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
		if (dup2(fd, 1) == -1)
			exit_failure(errno, 1);
		if (dup2(p->pipelines[p->pipes_ports - 2], 0) == -1)
			exit_failure(errno, 1);
		if (close(fd) == -1)
			exit_failure(errno, 1);
		close_piplines(p);
		if (execve(last_cmd->path, last_cmd->args, p->main.envp) == -1)
		{
			ft_fprintf(2, "bash: %s: command not found", last_cmd->cmd);
			exit(127);
		}
	}
}

void	close_piplines(t_params *p)
{
	int	i;

	i = 0;
	while (i < p->pipes_ports)
	{
		if (close(p->pipelines[i]) == -1)
		{
			ft_fprintf(2, "WHAT!!\n");
			exit_failure(errno, 1);
		}
		i++;
	}
}

void	at_exit_pipeline(t_params *p)
{
	int	i;
	// int	status;

	i = 0;
	close_piplines(p);	
	while (i < p->ncmd)
	{
		wait(NULL);
		i++;
	}
	// TODO: start freeing here;
	// exit (WEXITSTATUS(status));	
	exit(0);
}