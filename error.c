/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:39:32 by relkabou          #+#    #+#             */
/*   Updated: 2022/12/02 19:31:13 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *cmd, char *name, char *message)
{
	ft_putstr_fd(2, cmd);
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, name);
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, message);
	ft_putstr_fd(2, "\n");
}

void	ft_exits(int error, int toExit, int exitStatus)
{
	ft_putstr_fd(2, strerror(error));
	if (toExit == 1)
	{
		exit(exitStatus);
	}
}
