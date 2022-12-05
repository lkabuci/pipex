/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:12:25 by relkabou          #+#    #+#             */
/*   Updated: 2022/12/03 16:46:55 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

pid_t	*get_pids(t_params p)
{
	pid_t	*arr_of_pids;
	int		i;

	i = 0;
	if (!p.cmd)
		return ((pid_t *)0);
	arr_of_pids = (pid_t) malloc(sizeof(pid_t) * (p.main.ac - 1));
	if (!arr_of_pids)
		return ((pid_t *)0);
	while (p.cmd)
	{
		arr_of_pids[i] = i;
		i++;
		p.cmd = p.cmd->next;
	}
	arr_of_pids[i] = 0;
	return (arr_of_pids);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t		*arr_of_pids;
	t_main		main;
	t_params	p;
	int			i;

	main.ac = argc;
	main.av = argv;
	main.envp = envp;
	p.main = main;
	p.cmd = NULL;
	parse(&p);

	i = 0;
	arr_of_pids = get_pids(p);
	while (p.cmd, i)
	{
		arr_of_pids[i] = fork();
		
		if (arr_of_pids[i] == 0)
		{
			//FIXME - HERE
			dup2(p.cmd->fd[0]);
		}
		
		p.cmd = p.cmd->next;
		i++;
	}
	
	/* print params
		* int i = -1;
		* printf("%s\n", p.file.infile);
		* printf("%s\n", p.file.outfile);
		* while (p.cmd != NULL)
		* {
		* 	i = -1;
		* 	printf("cmd: %s\n", p.cmd->cmd);
		* 	while (p.cmd->args[++i] != NULL)
		* 	{
		* 		printf("args: %s\t", p.cmd->args[i]);
		* 	}
		* 	printf("\n");
		* 	printf("path: %s\n", p.cmd->path);
		* 	printf("========================\n");
		* 	p.cmd = p.cmd->next;
		* 	sleep(1);
		* }
	*/
	return 0;
}
