#include "pipex.h"

void	at_exit(t_params *p, pid_t *pid1, pid_t *pid2)
{
	if (close(p->fd[0]) == -1)
		ft_exits(errno, 1, EXIT_FAILURE);
	if (close(p->fd[1]) == -1)
		ft_exits(errno, 1, EXIT_FAILURE);
	if (waitpid(*pid1, NULL, 0) == -1)
		ft_exits(errno, 1, EXIT_FAILURE);
	if (waitpid(*pid2, NULL, 0) == -1)
		ft_exits(errno, 1, EXIT_FAILURE);
	free_tab(p->cmd1.args);
	free(p->cmd1.path);
	free(p->cmd2.path);
	free_tab(p->cmd2.args);
}

char	*join_path(char *s1, char sep, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	idx;
	char	*buffer;

	if (!s1 || !s2)
		return (NULL);
	idx = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	buffer = (char *) malloc(sizeof(char) * (s1_len + s2_len + 2));
	if (!buffer)
		return (NULL);
	while (*s1)
		buffer[idx++] = *s1++;
	buffer[idx++] = sep;
	while (*s2)
		buffer[idx++] = *s2++;
	buffer[idx] = 0;
	return (buffer);
}