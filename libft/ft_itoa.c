/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:18:07 by relkabou          #+#    #+#             */
/*   Updated: 2022/10/18 18:53:51 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int		len;
	long	i;

	len = 0;
	i = n;
	if (!i)
		return (1);
	if (i < 0)
	{
		i *= -1;
		len++;
	}
	while (i > 0)
	{
		i /= 10;
		len++;
	}
	return (len);
}

static long	get_dec(int len)
{
	long	res;

	res = 1;
	while (len > 1)
	{
		res *= 10;
		len--;
	}
	return (res);
}

static char	*fill(char *buffer, long nbr, long decimal, int index)
{
	while (decimal > 0)
	{
		*(buffer + index) = ((nbr / decimal) % 10) + '0';
		decimal /= 10;
		index++;
	}
	*(buffer + index) = '\0';
	return (buffer);
}

char	*ft_itoa(int n)
{
	char	*buffer;
	int		len;
	int		i;
	long	nbr;
	long	dec;

	i = 0;
	nbr = n;
	len = get_len(n);
	dec = get_dec(len);
	buffer = (char *) malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (0);
	if (nbr < 0)
	{
		nbr *= -1;
		*buffer = '-';
		dec /= 10;
		i++;
	}
	buffer = fill(buffer, nbr, dec, i);
	return (buffer);
}
