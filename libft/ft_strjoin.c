/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 09:56:01 by relkabou          #+#    #+#             */
/*   Updated: 2022/10/18 18:57:50 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill(char	*dst, char	*s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(s1 + i))
	{
		*(dst + j) = *(s1 + i);
		j++;
		i++;
	}
	i = 0;
	while (*(s2 + i))
	{
		*(dst + j) = *(s2 + i);
		j++;
		i++;
	}
	*(dst + j) = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*str1;
	char	*str2;
	char	*buffer;

	if (!s1 || !s2)
		return (0);
	str1 = (char *)s1;
	str2 = (char *)s2;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!str1 && !str2)
	{
		buffer = (char *) malloc(sizeof(char));
		*buffer = '\0';
		return (buffer);
	}
	buffer = (char *)malloc(sizeof(char) * (len + 1));
	if (!(buffer))
		return (0);
	buffer = fill(buffer, str1, str2);
	return (buffer);
}
