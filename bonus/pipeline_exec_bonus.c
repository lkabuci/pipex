#include "pipex_bonus.h"

void	exec_first_cmd(t_params *p)
{
	if (dup2(p->file.infd, 0) == -1)
		exit_failure(errno, 1);
	if (dup2(p->pipelines[1][1], 1) == -1)
		exit_failure(errno, 1);
	if (close(p->file.infd) == -1)
		exit_failure(errno, 1);
	close_piplines(p);
}

void	exec_first_cmds(int i, t_params *p)
{
	t_cmd	*tmp;

	tmp = p->cmds->content;
	p->arr_of_pids[0] = fork();
	if (p->arr_of_pids[0] == -1)
		exit_failure(errno, 1);
	if (p->arr_of_pids[0] == 0)
	{
		if (dup2(p->file.infd, 0) == -1)
			exit_failure(errno, 1);
		if (dup2(p->pipelines[1][1], 1) == -1)
			exit_failure(errno, 1);
		if (close(p->file.infd) == -1)
			exit_failure(errno, 1);
		close_piplines(p);
		if (execve(tmp->path, tmp->args, p->main.envp) == -1)
			exit_failure(errno, 127);
	}
}

void	exec_middle_cmds(t_params *p)
{
	int	i;
	t_cmd	*tmp;
	t_list	*list_of_cmds;

	i = 1;
	list_of_cmds = p->cmds->next;
	while (list_of_cmds->next)
	{
		tmp = p->cmds;
		p->arr_of_pids[i] = fork();
		if (p)
		i++;
		list_of_cmds = list_of_cmds->next;
	}
}

void	exec_last_cmd(t_params *p)
{
	t_cmd	*tmp;

	tmp = ft_lstlast(p->cmds);
	p->arr_of_pids[p->ncmd] = fork();
	if (p->arr_of_pids[p->ncmd] == -1)
		exit_failure(errno, 1);
	if (p->arr_of_pids[0] == 0)
	{
		if (dup2(p->file.outfd, 1) == -1)
			exit_failure(errno, 1);
		if (dup2(p->pipelines[p->ncmd][0], 0) == -1)
			exit_failure(errno, 1);
		if (close(p->file.outfd) == -1)
			exit_failure(errno, 1);
		close_piplines(p);
		if (execve(tmp->path, tmp->args, p->main.envp) == -1)
			exit_failure(errno, 127);
	}
}

void	execute_pipeline(void *content)
{
	t_params *p;

	p = content;
}

void	close_piplines(t_params *p)
{
	while (*p->pipelines)
	{
		if (close(p->pipelines[0]) == -1)
			exit_failure(errno, 1);
		if (close(p->pipelines[1]) == -1)
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