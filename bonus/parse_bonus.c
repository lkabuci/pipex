/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:11:31 by relkabou          #+#    #+#             */
/*   Updated: 2022/12/03 18:56:35 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char **get_main_path(t_params *p)
{
	while (p->main.envp)
	{
		if (!*p->main.envp || !p->main.envp)
			break ;
		if (!(ft_strncmp("PATH=", *p->main.envp, 5)))
			return (ft_split(*p->main.envp + 5, ':'));
		p->main.envp++;
	}
	return (NULL);
}

static char	*get_valid_path(t_params *p, t_cmd *cmd)
{
	int		i;
	char	*path;

	i = -1;
	if (ft_strchr(cmd->cmd, '/') && !access(cmd->cmd, F_OK | X_OK))
		return (cmd->cmd);
	while (p->main_path && p->main_path[++i])
	{
		path = join_path(p->main_path[i], '/', cmd->cmd);
		if ((access(path, F_OK | X_OK)) == -1)
			free(path);
		else
		{
			// cmd->path = path;
			// free_tab(p->main_path);
			return (path);
		}
	}
	// free_tab(p->main_path);
	return (NULL);
}

static void	get_commands(t_params *p)
{
	int		idx;
	t_cmd	*cmd;

	idx = 2;
	//TODO - Free p->main_path
	p->main_path = get_main_path(p);
	while (idx < p->main.ac - 1)
	{
		//TODO - Free everything inside the cmd node
		cmd = lst_new(ft_split(p->main.av[idx], ' '));
		cmd->path = get_valid_path(p, cmd);
		lst_add_back(p, cmd);
		idx++;
	}
}

void	parse(t_params *p)
{
	if (p->main.ac < 4)
	{
		ft_putstr_fd(2, "Not enough arguments");
		exit(EXIT_FAILURE);
	}
	p->file.infile = p->main.av[1];
	p->file.outfile = p->main.av[p->main.ac - 1];
	get_commands(p);
}