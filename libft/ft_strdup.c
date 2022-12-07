/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:05:29 by relkabou          #+#    #+#             */
/*   Updated: 2022/10/18 18:57:31 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*buffer;
	size_t	len;
	size_t	index;

	index = 0;
	len = ft_strlen(s1);
	buffer = (char *)malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (0);
	while (index < len)
	{
		*(buffer + index) = *(s1 + index);
		index++;
	}
	*(buffer + index) = '\0';
	return (buffer);
}
