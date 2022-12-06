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
#include <sys/wait.h>

pid_t	*get_pids(t_params p)
{
	pid_t	*arr_of_pids;
	// int		i;

	// i = 0;
	if (!p.cmd)
		return ((pid_t *)0);
	arr_of_pids = (pid_t *) malloc(sizeof(pid_t) * (p.main.ac - 1));
	if (!arr_of_pids)
		return ((pid_t *)0);
	// while (p.cmd)
	// {
	// 	arr_of_pids[i] = i;
	// 	i++;
	// 	p.cmd = p.cmd->next;
	// }
	// arr_of_pids[i] = 0;
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
	int is_first = 1;
	int is_last = 1;
	// pid_t wpid;
	int status = 0;
	arr_of_pids = get_pids(p);
	t_cmd *tmp;

	tmp = p.cmd;
	while (tmp && i < argc)
	{
		arr_of_pids[i] = fork();
		//FIXME - ONLY WORKS WITH THE FIRST COMMAND	
		if (arr_of_pids[i] == 0)
		{
			is_last = 0;
			if (tmp->next == NULL)
				is_last = 1;
			if (is_first == 1)
				redirect_input(&p);
			else
				dup2(tmp->fd[0], 0);
			if (is_last == 1)
				redirect_output(&p);
			else
				dup2(tmp->fd[1], 1);
			close_all_pipes(&p);
			is_first = 0;
			if (execve(tmp->path, tmp->args, envp) == -1)
				perror("line 74 in execve");
		}
		else
		{
			wait(&status);
			// while ((wpid = wait(&status)) > 0);
			tmp = tmp->next;
			i++;
		}
	}
	close_all_pipes(&p);

	//FIXME - WAITS FOR CHILDS
	for (int i = 1; i < argc - 2; i++)
	{
		wait(&status);
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

//FIXME - Weird bug when trying to execute
//		  ./pipex infile "cat" "grep a" "head -1" "/dev/stdout"
//		  I only get hello, even though the infile is containg another data
//		  It only reads the first line.
/*!SECTION
	The first and the last commands works just fine except for the one in the middile
*/