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

static void	get_env_path(t_params *p)
{
	while (p->main.envp)
	{
		if (!*p->main.envp || !p->main.envp)
			break ;
		if (!(ft_strncmp("PATH=", *p->main.envp, 5)))
		{
			p->main_path = *p->main.envp;
			return ;
		}
		p->main.envp++;
	}
	p->main_path = NULL;
}

static char	*get_valid_path(t_params *p, t_cmd *cmd)
{
	if (ft_strchr(cmd->cmd, '/') && !access(cmd->cmd, F_OK | X_OK))
	{
		cmd->path = cmd->cmd;
		return ;
	}
}

static void	get_commands(t_params *p)
{
	int		idx;
	char	**args;
	char	*path;
	t_cmd	*cmd;

	idx = 2;
	while (idx < p->main.ac - 1)
	{
		args = ft_split(p->main.av[idx], ' ');
		cmd = lst_new(p, args);
		path = get_valid_path(p, cmd);
		cmd->path = path;
		lst_add_back(p, cmd, path);
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
	p->file.infile = p->main.av[0];
	p->file.outfile = p->main.av[p->main.ac - 1];
	get_commands(p);
}