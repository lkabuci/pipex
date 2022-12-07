/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:07:06 by relkabou          #+#    #+#             */
/*   Updated: 2022/10/18 18:58:33 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*buffer;
	unsigned int	i;
	size_t			len;

	i = 0;
	if (!s || !f)
		return (0);
	str = (char *)s;
	len = ft_strlen(str);
	buffer = (char *) malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (0);
	while (i < len)
	{
		*(buffer + i) = (f)(i, *(str + i));
		i++;
	}
	*(buffer + i) = '\0';
	return (buffer);
}
