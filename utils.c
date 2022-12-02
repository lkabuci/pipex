/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:41:30 by relkabou          #+#    #+#             */
/*   Updated: 2022/12/02 19:22:23 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr_fd(int fd, char *str)
{
	while (str && *str)
		write(fd, str++, 1);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	index;

	index = -1;
	if (dst == src || !n)
		return (dst);
	while (++index < n)
		*(char *)(dst + index) = *(char *)(src + index);
	return (dst);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	if (!n)
		return (0);
	while (n--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (!*s1 && !*s2)
			return (0);
		s1++;
		s2++;
	}
	return (0);
}
