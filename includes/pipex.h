/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:40:40 by relkabou          #+#    #+#             */
/*   Updated: 2022/12/03 15:43:17 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct s_cmd
{
	char	*cmd;
	char	*flag;
	char	*path;
	char	**args;
	char	*file;
}	t_cmd;

typedef struct s_main
{
	int		ac;
	char	**av;
	char	**env;
}	t_main;

typedef struct params
{
	t_cmd	cmd1;
	t_cmd	cmd2;
	t_main	main_params;
	char	*env_paths;
	int		fd[2];
}	t_params;

/* **************** utils.c **************** */
void	free_tab(char **tab);
void	at_exit(t_params *p, pid_t *pid1, pid_t *pid2);
char	*join_path(char *s1, char sep, char *s2);
void	ft_exits(int error, int toExit, int exitStatus);

/* **************** parse.c **************** */
int		parsing(t_params *p);

#endif
