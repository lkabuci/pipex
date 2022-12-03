/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:08:07 by relkabou          #+#    #+#             */
/*   Updated: 2022/12/03 15:44:18 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

typedef struct s_main
{
	int		ac;
	char	**av;
	char	**envp;
}	t_main;

typedef struct s_cmd
{
	char	*cmd;
	char	*path;
	char	**args;
	char	*env_aths;
	char	fd[2];
}	t_cmd;



#endif // PIPEX_BONUS_H