/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:08:07 by relkabou          #+#    #+#             */
/*   Updated: 2022/12/03 18:55:59 by relkabou         ###   ########.fr       */
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

typedef struct s_files
{
	char	*infile;
	char	*outfile;
}	t_files;

typedef struct s_cmd
{
	char			*cmd;
	char			*path;
	char			**args;
	// int				fd[2];
	struct s_cmd	*next;
}	t_cmd;

typedef struct params
{
	t_main		main;
	t_files		file;
	t_cmd		*cmd;
	int			ncmd;
	int			*arr_of_pids;
	int			**arr_of_pipes;
	char		**main_path;
}	t_params;

/* ************* utils1.c ************* */
void	ft_putstr_fd(int fd, char *str);
size_t	ft_strlen(char *str);
void	free_tab(char **tab);
void	*ft_memcpy(void *dst, void *src, size_t n);
int		ft_strncmp(char *s1, char *s2, size_t n);

/* ************* utils2.c ************* */
int		ft_strchr(char *str, char c);
char	*join_path(char *s1, char sep, char *s2);

/* ************* lst_manip.c ************* */
t_cmd	*lst_new(char **args);
void	lst_add_back(t_params *p, t_cmd *cmd);

/* ************* split_b.c ************* */
char	**ft_split(char *str, char sep);

/* ************* pipes_bonus.c ************* */
void	redirect_input(t_params *p);
void	redirect_output(t_params *p);
void	close_all_pipes(t_params p, int ***arr_of_pipes);

/* ************* switcher.c ************* */
/* ************* parse_bonus.c ************* */
void	parse(t_params *p);


#endif // PIPEX_BONUS_H