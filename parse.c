#include "pipex.h"

static void	get_paths(t_params *p)
{
	while (p->envp)
	{
		if (!(ft_strncmp("PATH=", *p->envp, 5)))
		{
			p->paths = *p->envp;
			break;
		}
		p->envp++;
	}
}

static void	check_cmd(t_params *p, char *cmd)
{
	char **paths;
	char *path;
	int	i;

	i = 0;
	paths = ft_split(p->paths + 5, ':');
	while(paths[i])
	{
		path = join_path(paths[i], '/', cmd);
		if ((access(path, F_OK | X_OK)) == -1)
			free(path);
		else
		{
			p->path = path;
			break;
		}
		i++;
	}
	// ! I should print an error that the command not found
	//   and exit
	free_tab(paths);
}

int	parse(t_params *p)
{
	char	*command1;
	char	*command2;
	if (p->ac != 5)
	{
		ft_putstr_fd(2, "Invalid arguments. Quiting...\n");
		exit(EXIT_FAILURE);
	}
	command1 = ft_split(p->av[2], ' ');
	p->cmd1 = command1[0];
	p->cmd1_flags = command1[1];
	p->file1 = p->av[1];
	command2 = ft_split(p->av[3], ' ');
	p->cmd2 = command2[0];
	p->cmd2_flags = command2[1];
	p->file2 = p->av[4];
	get_paths(p);
	check_cmd(p, p->cmd1);
	check_cmd(p, p->cmd2);
	printf("%s\n", p->path);
	return 1;
}

