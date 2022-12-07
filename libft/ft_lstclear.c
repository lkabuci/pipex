/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:00:47 by relkabou          #+#    #+#             */
/*   Updated: 2022/10/18 18:54:38 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*temp;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		temp = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = temp;
	}
	(*lst) = NULL;
}
