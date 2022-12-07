/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:06:26 by relkabou          #+#    #+#             */
/*   Updated: 2022/10/18 18:58:16 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	index;
	size_t	src_len;

	index = 0;
	src_len = ft_strlen(src);
	if (!dstsize || !dst)
		return (src_len);
	while (index < dstsize - 1 && *(src + index))
	{
		*(dst + index) = *(src + index);
		index++;
	}
	*(dst + index) = '\0';
	return (src_len);
}
