/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 07:45:30 by relkabou          #+#    #+#             */
/*   Updated: 2022/10/25 08:07:58 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_ptr(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		ptr = NULL;
	}
}

char	*merge_line(int nl_position, char **stash)
{
	char	*line;
	char	*tmp;

	tmp = NULL;
	if (nl_position <= 0)
	{
		if (**stash == '\0')
		{
			free(*stash);
			*stash = NULL;
			return (NULL);
		}
		line = *stash;
		*stash = NULL;
		return (line);
	}
	tmp = ft_substr(*stash, nl_position, BUFFER_SIZE);
	line = *stash;
	line[nl_position] = 0;
	*stash = tmp;
	return (line);
}

char	*read_line(int fd, char **stash, char *buffer)
{
	ssize_t	readed;
	char	*tmp;
	char	*nl;

	nl = ft_strchr(*stash, '\n');
	tmp = NULL;
	readed = 0;
	while (!nl)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed <= 0)
			return (merge_line(readed, stash));
		buffer[readed] = 0;
		tmp = ft_strjoin(*stash, buffer);
		free_ptr(stash);
		*stash = tmp;
		nl = ft_strchr(*stash, '\n');
	}
	return (merge_line(nl - *stash + 1, stash));
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;

	if ((fd < 0 && fd > MAX_FD) || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	line = read_line(fd, &stash, buffer);
	free_ptr(&buffer);
	return (line);
}
