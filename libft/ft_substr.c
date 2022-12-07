/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:08:21 by relkabou          #+#    #+#             */
/*   Updated: 2022/10/19 15:21:22 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	new_len;
	char	*buffer;

	i = -1;
	new_len = len ;
	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
	{
		buffer = (char *)malloc(sizeof(char));
		*buffer = '\0';
		return (buffer);
	}
	if (len > ft_strlen(s + start))
		new_len = ft_strlen(s + start);
	buffer = (char *) malloc(sizeof(char) * (new_len + 1));
	if (!buffer)
		return (0);
	while (++i < new_len)
		buffer[i] = *((char *)s + i + start);
	buffer[i] = '\0';
	return (buffer);
}
