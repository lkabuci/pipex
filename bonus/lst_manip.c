/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:38:36 by relkabou          #+#    #+#             */
/*   Updated: 2022/12/03 18:55:19 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_cmd	*lst_new(char **args)
{
	//TODO - Free args
	//TODO - Free cmd_node
	t_cmd	*cmd_node;

	cmd_node = (t_cmd *) malloc(sizeof(t_cmd));
	if (!cmd_node)
		return ((t_cmd *)NULL);
	cmd_node->cmd = *args;
	cmd_node->args = args;
	cmd_node->next = NULL;
	if (pipe(cmd_node->fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	return (cmd_node);	
}

void	lst_add_back(t_params *p, t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = p->cmd;
	if (!p || !cmd)
		return ;
	if (!tmp)
	{
		p->cmd = cmd;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = cmd;
}

//TODO - Create a func that liberate a node and it's sub component
// void	free_nodes(t_params *p);