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

# include "libft.h"

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

typedef struct	s_here_doc
{
	char	*delimiter;
	char	*cmd1;
	char	**args1;
	char	*path1;
	char	*cmd2;
	char	**args2;
	char	*path2;
	char	*outfile;
	char	*tmp_file;
	int		pipeid[2];
}	t_here_doc;

/* ============== utils1.c ============== */
void	exit_failure(int err, int status);
void	free_tab(char **tab);
char	*join_path(char *s1, char sep, char *s2);

/* ============== utils2.c ============== */
char	**get_paths_from_env(char **envp);
char	*get_path(char *cmd, char **paths);
void	at_exit_here_doc(t_here_doc *p, pid_t *pid1, pid_t *pid2);

/* ============== lst_manip.c ============== */
t_cmd	*lst_new(char **args);
void	lst_add_back(t_params *p, t_cmd *cmd);

/* ============== parse_bonus.c ============== */
void	here_doc(int argc, char **argv, char **envp);

/* ============== pipes_bonus.c ============== */
void	redirect_input(t_params *p);
void	redirect_output(t_params *p);
void	close_all_pipes(t_params p, int ***arr_of_pipes);

/* ============== here_doc.c ============== */
void	here_doc(int argc, char **argv, char **envp);

/* ============== parse_bonus.c ============== */
void	parse(t_params *p);



#endif // PIPEX_BONUS_H