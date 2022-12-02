/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:43:51 by relkabou          #+#    #+#             */
/*   Updated: 2022/12/02 19:26:35 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*buffer;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	buffer = (char *) malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, s1, s1_len);
	ft_memcpy(buffer + s1_len, s2, s2_len);
	return (buffer);
}

int	ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	at_exit(t_params *p, pid_t *pid1, pid_t *pid2)
{
	int	exit_status;

	if (close(p->fd[0]) == -1)
		ft_exits(errno, 1, EXIT_FAILURE);
	if (close(p->fd[1]) == -1)
		ft_exits(errno, 1, EXIT_FAILURE);
	if (waitpid(*pid1, NULL, 0) == -1)
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
