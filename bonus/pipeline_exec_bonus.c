#include "pipex_bonus.h"

void	exec_first_cmd(t_params *p)
{
	t_cmd	*tmp;
	int		fd;

	tmp = p->cmds->content;
	p->arr_of_pids[0] = fork();
	if (p->arr_of_pids[0] == -1)
		exit_failure(errno, 1);
	if (p->arr_of_pids[0] == 0)
	{
		fd = open(p->file.infile, O_RDONLY);
		if (fd == -1)
			exit_failure(errno, 1);
		if (dup2(fd, 0) == -1)
			exit_failure(errno, 1);
		if (dup2(p->pipelines[1][1], 1) == -1)
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
	t_cmd	*tmp;
	t_list	*list_of_cmds;

	i = 0;
	list_of_cmds = p->cmds->next;
	while (list_of_cmds->next)
	{
		tmp = p->cmds->content;
		p->arr_of_pids[++i] = fork();
		if (p->arr_of_pids[i] == -1)
			exit_failure(errno, 1);
		if (p->arr_of_pids[i] == 0)
		{
			if (dup2(p->pipelines[i][0], 0) == -1)
				exit_failure(errno, 1);
			if (dup2(p->pipelines[i + 1][1], 1) == -1)
				exit_failure(errno, 1);
			close_piplines(p);
			if (execve(tmp->path, tmp->args, p->main.envp) == -1)
			{
				ft_fprintf(2, "bash: %s: command not found", tmp->cmd);
				exit(127);
			}
		}
		list_of_cmds = list_of_cmds->next;
	}
}

void	exec_last_cmd(t_params *p)
{
	t_cmd	*tmp;
	t_list	*lst_tmp;
	int		fd;

	lst_tmp = ft_lstlast(p->cmds);
	tmp = lst_tmp->content;
	p->arr_of_pids[p->ncmd] = fork();
	if (p->arr_of_pids[p->ncmd] == -1)
		exit_failure(errno, 1);
	if (p->arr_of_pids[0] == 0)
	{
		fd = open(p->file.outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd == -1)
			exit_failure(errno, 1);
		if (dup2(p->file.outfd, 1) == -1)
			exit_failure(errno, 1);
		if (dup2(p->pipelines[p->ncmd][0], 0) == -1)
			exit_failure(errno, 1);
		if (close(p->file.outfd) == -1)
			exit_failure(errno, 1);
		close_piplines(p);
		if (execve(tmp->path, tmp->args, p->main.envp) == -1)
		{
			ft_fprintf(2, "bash: %s: command not found", tmp->cmd);
			exit(127);
		}
	}
}

void	close_piplines(t_params *p)
{
	while (*p->pipelines)
	{
		if (close(p->pipelines[0][0]) == -1)
			exit_failure(errno, 1);
		if (close(p->pipelines[0][1]) == -1)
			exit_failure(errno, 1);
		p->pipelines++;
	}
}

void	at_exit_pipeline(t_params *p)
{
	int	i;
	int	status;

	i = 0;
	close_piplines(p);	
	while (p->arr_of_pids[i])
	{
		waitpid(p->arr_of_pids[i], &status, 0);
		i++;
	}
	// TODO: start freeing here;
	exit (WEXITSTATUS(status));	
}