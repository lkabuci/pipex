#include "pipex_bonus.h"

void    close_all_pipes(t_params *p)
{
	t_cmd	*tmp;

	tmp = p->cmd;
	if (!tmp)
		return ;
	while (tmp)
	{
		close(tmp->fd[0]);
		close(tmp->fd[1]);
		tmp = tmp->next;
	}
}