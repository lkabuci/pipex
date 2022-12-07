/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:02:38 by relkabou          #+#    #+#             */
/*   Updated: 2022/10/18 18:56:14 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	if (dst == src || !len)
		return (dst);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		len += 1;
		while (--len > 0)
			*((char *)dst + len - 1) = *((char *)src + len - 1);
	}
	return (dst);
}
