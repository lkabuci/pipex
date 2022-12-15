/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:42:45 by relkabou          #+#    #+#             */
/*   Updated: 2022/12/15 14:43:11 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_dup2(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
		exit_failure(errno, 1);
}

void	ft_execve(char *path, char **args, char **envp)
{
	if (execve(path, args, envp) == -1)
	{
		ft_fprintf(2, "bash: %s: command not found\n", args[0]);
		exit(127);
	}
}

void	ft_close(int fd)
{
	if (close(fd) == -1)
		exit_failure(errno, 1);
}
