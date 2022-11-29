#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

typedef struct cmd
{
	char	*path;
	char	*cmd;
	char	*flag;
};


typedef struct params
{
	int		ac;
	char	**av;
	char	*file1;
	char	*cmd1;
	char	*cmd1_flags;
	char	*cmd2;
	char	*cmd2_flags;
	char	*file2;
	char	*path;
	char	*paths;
	char	*args;
	char	**envp;
}	t_params;


/* **************** UTILS **************** */
char	*join_path(char *s1, char sep, char *s2);
void	free_tab(char **tab);
void	*ft_memcpy(void *dst, void *src, size_t n);
size_t	ft_strlen(char *str);
void	ft_putstr_fd(int fd, char *str);
char	**ft_split(char *str, char sep);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, size_t n);


int		parse(t_params *p);

#endif