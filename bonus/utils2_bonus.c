/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:49:45 by relkabou          #+#    #+#             */
/*   Updated: 2022/12/15 14:49:52 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**get_paths_from_env(char **envp)
{
	while (envp && *envp)
	{
		if (!ft_strncmp(*envp, "PATH=", 5))
			return (ft_split(*envp + 5, ':'));
		envp++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	char	*ret;
	int		is_valid;
	char	**paths;
	char	**ptr;

	paths = get_paths_from_env(envp);
	ptr = paths;
	is_valid = access(cmd, X_OK);
	if (!is_valid && ft_strchr(cmd, '/'))
		return (free_tab(paths), ft_strdup(cmd));
	while (paths && *paths)
	{
		ret = join_path(*paths, '/', cmd);
		is_valid = access(ret, X_OK);
		if (!is_valid)
			return (free_tab(ptr), ret);
		free(ret);
		paths++;
	}
	return (free_tab(ptr), NULL);
}

void	at_exit_here_doc(t_here_doc *p, pid_t *pid1, pid_t *pid2)
{
	int	exit_status;

	if (close(p->pipeid[0]) == -1)
		exit_failure(errno, 1);
	if (close(p->pipeid[1]) == -1)
		exit_failure(errno, 1);
	if (waitpid(*pid1, &exit_status, 0) == -1)
		exit_failure(errno, 1);
	if (waitpid(*pid2, &exit_status, 0) == -1)
		exit_failure(errno, 1);
	free_tab(p->args1);
	free_tab(p->args2);
	free(p->path1);
	free(p->path2);
	free(p);
	exit (WEXITSTATUS(exit_status));
}

void	close_piplines(t_params *p)
{
	int	i;

	i = 0;
	while (i < p->pipes_ports)
	{
		if (close(p->pipelines[i]) == -1)
			exit_failure(errno, 1);
		i++;
	}
}
