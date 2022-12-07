/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:02:07 by relkabou          #+#    #+#             */
/*   Updated: 2022/10/18 18:55:50 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index++ < n)
	{
		if (*(unsigned char *)s++ == (unsigned char)c)
			return ((void *)s - 1);
	}
	return (0);
}
