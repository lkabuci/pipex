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

static int	check_cmd(t_params *p, char *cmd, int option)
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
			if (option == 1)
				p->path1 = path;
			else if (option == 2)
				p->path2 = path;
			return (1);
		}
		i++;
	}
	// ! I should print an error that the command not found
	//   and exit
	free_tab(paths);
	return (0);
}

int	parse(t_params *p)
{
	char	**command1;
	char	**command2;
	if (p->ac != 5)
	{
		ft_putstr_fd(2, "Invalid arguments. Quiting...\n");
		exit(EXIT_FAILURE);
	}
	command1 = ft_split(p->av[2], ' ');
	command2 = ft_split(p->av[3], ' ');
	p->cmd1 = command1[0];
	p->cmd2 = command2[0];
	p->cmd1_flags = command1[1];
	p->cmd2_flags = command2[1];
	p->file1 = p->av[1];
	p->file2 = p->av[4];
	get_paths(p);
	if ((check_cmd(p, p->cmd1, 1) == -1))
	{
		// Print command not found error
		// keep in mind that youshuld not exit
		// until the next pipe
		printf("command not found error\n");
	}
	if ((check_cmd(p, p->cmd2, 2) == -1))
		printf("Error in cmd 2\n");
	return 1;
}

