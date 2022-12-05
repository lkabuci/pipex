/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:40:20 by relkabou          #+#    #+#             */
/*   Updated: 2022/12/03 18:40:31 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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