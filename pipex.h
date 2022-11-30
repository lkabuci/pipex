#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

typedef struct s_cmd
{
	char	*cmd;
	char	*flag;
	char	*path;
	char	*file;
} t_cmd;

typedef struct s_main
{
	int		ac;
	char	**av;
	char	**env;
} t_main;


typedef struct params
{
	t_cmd	cmd1;
	t_cmd	cmd2;
	t_main	main_params;
	char	*env_paths;
	int		fd[2];
}	t_params;


/* **************** UTILS **************** */
char	*join_path(char *s1, char sep, char *s2);
int		ft_strchr(char *str, char c);
void	free_tab(char **tab);
void	*ft_memcpy(void *dst, void *src, size_t n);
size_t	ft_strlen(char *str);
void	ft_putstr_fd(int fd, char *str);
char	**ft_split(char *str, char sep);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, size_t n);

int		parsing(t_params *p);

#endif