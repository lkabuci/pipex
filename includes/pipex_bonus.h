/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:08:07 by relkabou          #+#    #+#             */
/*   Updated: 2022/12/15 19:30:39 by relkabou         ###   ########.fr       */
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
}	t_cmd;

typedef struct params
{
	t_main		main;
	t_files		file;
	t_list		*cmds;
	int			ncmd;
	int			*pipelines;
	int			pipes_ports;
	char		**main_path;
}	t_params;

/* **** Here doc structure **** */
typedef struct s_here_doc
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
t_cmd	*ft_strdup_cmd(t_cmd *cmd);
void	free_cmd_node(void	*cmd);

/* ============== utils2.c ============== */
char	**get_paths_from_env(char **envp);
char	*get_path(char *cmd, char **envp);
void	at_exit_here_doc(t_here_doc *p, pid_t *pid1, pid_t *pid2);

/* ============== ft_checks.c ============== */
void	ft_close(int fd);
void	ft_dup2(int oldfd, int newfd);
void	ft_execve(char *path, char **args, char **envp);

/* ============== pipeline_exec_bonus.c ============== */
void	exec_first_cmd(t_params *p);
void	exec_middle_cmds(t_params *p);
void	exec_last_cmd(t_cmd *last_cmd, t_params *p);
void	close_piplines(t_params *p);
void	at_exit_pipeline(t_params *p);

/* ============== here_doc.c ============== */
void	here_doc(int argc, char **argv, char **envp);

/* ============== pipeline.c ============== */
void	pipeline(int argc, char **argv, char **envp);

/* ============== parse_bonus.c ============== */
void	here_doc(int argc, char **argv, char **envp);

#endif // PIPEX_BONUS_H