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

static char	*get_valid_pahth(t_params *p)
{
	
}

t_cmd	*lst_new(t_params *p, char **args)
{
	t_cmd	*cmd_node;

	cmd_node = (t_cmd *) malloc(sizeof(t_cmd));
	if (!cmd_node)
		return ((t_cmd *)NULL);
	cmd_node->cmd = *args;
	cmd_node->args = args;
	return (cmd_node);	
}