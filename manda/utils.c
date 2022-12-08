/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:41:30 by relkabou          #+#    #+#             */
/*   Updated: 2022/12/03 12:23:50 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	at_exit(t_params *p, pid_t *pid1, pid_t *pid2)
{
	int	exit_status;

	if (close(p->fd[0]) == -1)
		ft_exits(errno, 1, EXIT_FAILURE);
	if (close(p->fd[1]) == -1)
		ft_exits(errno, 1, EXIT_FAILURE);
	if (waitpid(*pid1, &exit_status, 0) == -1)
		ft_exits(errno, 1, EXIT_FAILURE);
	if (waitpid(*pid2, &exit_status, 0) == -1)
		ft_exits(errno, 1, EXIT_FAILURE);
	free_tab(p->cmd1.args);
	free(p->cmd1.path);
	free(p->cmd2.path);
	free_tab(p->cmd2.args);
	exit (WEXITSTATUS(exit_status));
}

char	*join_path(char *s1, char sep, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	idx;
	char	*buffer;

	if (!s1 || !s2)
		return (NULL);
	idx = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	buffer = (char *) malloc(sizeof(char) * (s1_len + s2_len + 2));
	if (!buffer)
		return (NULL);
	while (*s1)
		buffer[idx++] = *s1++;
	buffer[idx++] = sep;
	while (*s2)
		buffer[idx++] = *s2++;
	buffer[idx] = 0;
	return (buffer);
}

void	ft_exits(int error, int toExit, int exitStatus)
{
	ft_fprintf(2, strerror(error));
	if (toExit == 1)
	{
		exit(exitStatus);
	}
}