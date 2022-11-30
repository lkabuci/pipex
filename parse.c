#include "pipex.h"

static void	get_env_path(t_params *p)
{
	while (p->main_params.env)
	{
		if (!(ft_strncmp("PATH=", *p->main_params.env, 5)))
		{
			p->env_paths = *p->main_params.env;
			break;
		}
		p->main_params.env++;
	}
}

static int	get_path(t_params *p, t_cmd *cmd)
{
	char	**paths;
	char	*path;
	int		i;

	i = 0;
	if (ft_strchr(cmd->cmd, '/') && !access(cmd->cmd, F_OK | X_OK))
	{
		cmd->path = cmd->cmd;
		return (1);
	}
	paths = ft_split(p->env_paths + 5, ':');
	while(paths[i])
	{
		path = join_path(paths[i], '/', cmd->cmd);
		if ((access(path, F_OK | X_OK)) == -1)
			free(path);
		else
		{
			cmd->path = path;
			return (1);
		}
		i++;
	}
	// ! I should print an error that the command not found
	//   and exit
	free_tab(paths);
	cmd->path = NULL;
	return (-1);
}

int	parsing(t_params *p)
{
	char	**part1;
	char	**part2;
	if (p->main_params.ac != 5)
	{
		ft_putstr_fd(2, "Invalid arguments. Quiting...\n");
		exit(EXIT_FAILURE);
	}
	part1 = ft_split(p->main_params.av[2], ' ');
	part2 = ft_split(p->main_params.av[3], ' ');
	p->cmd1.file = p->main_params.av[1];
	p->cmd1.cmd = part1[0];
	p->cmd1.flag = part1[1];
	p->cmd2.cmd = part2[0];
	p->cmd2.flag = part2[1];
	p->cmd2.file = p->main_params.av[4];
	get_env_path(p);
	if ((get_path(p, &p->cmd1) == -1))
	{
		perror(p->cmd1.cmd);
		// Print command not found error
		// keep in mind that youshuld not exit
		// until the next pipe
		printf("command not found error\n");
	}
	if ((get_path(p, &p->cmd2) == -1))
		printf("Error in cmd 2\n");
	return 1;
}

