# include "pipex_bonus.h"

void	exit_failure(int err, int status)
{
	ft_fprintf(2, "%s", strerror(err));
	exit(status);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	// free(tab);
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

t_cmd	*ft_strdup_cmd(t_cmd *cmd)
{
	t_cmd	*node;
	char	**node_args;
	int		i;

	i = 0;
	node = malloc(sizeof(t_cmd));
	if (!node)
		return (NULL);
	node->cmd = ft_strdup(cmd->cmd);
	node->path = ft_strdup(cmd->path);
	while (cmd->args[i])
		i++;
	node_args = malloc(sizeof(char *) * (i + 1));
	if (!node_args)
		return (NULL);
	i = 0;
	while (cmd->args[i])
	{
		node_args[i] = ft_strdup(cmd->args[i]);
		i++;
	}
	node_args[i] = NULL;
	node->args = node_args;
	return (node);
}

void	free_cmd_node(void	*cmd)
{
	t_cmd	*node = cmd;
	free(node->cmd);
	free(node->path);
	free_tab(node->args);
}