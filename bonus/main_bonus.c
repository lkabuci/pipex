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

int		**get_pipes(t_params p)
{
	int	**arr_of_pipes;
	int	i;

	i = 0;
	arr_of_pipes = (int **) malloc(sizeof(int *) * (p.ncmd));
	if (!arr_of_pipes)
		return (NULL);
	while (i < p.ncmd)
	{
		arr_of_pipes[i] = malloc(sizeof(int) * 2);
		if (!arr_of_pipes)
			return (NULL);
			//TODO - Free all nodes inside
		if (pipe(arr_of_pipes[i]) == -1)
		{
			perror("pipe:");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (arr_of_pipes);
}

pid_t	*get_pids(t_params p)
{
	pid_t	*arr_of_pids;

	if (!p.cmd)
		return ((pid_t *)0);
	arr_of_pids = (pid_t *) malloc(sizeof(pid_t) * (p.ncmd));
	if (!arr_of_pids)
		return ((pid_t *)0);
	return (arr_of_pids);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t		*arr_of_pids;
	int			**arr_of_pipes;
	t_params	p;
	int			i;

	p.main.ac = argc;
	p.main.av = argv;
	p.main.envp = envp;
	p.ncmd = argc - 2;
	p.cmd = NULL;
	parse(&p);
	// End of parsing

	i = 0;
	// int status;
	arr_of_pids = get_pids(p);
	arr_of_pipes = get_pipes(p);
	t_cmd	*tmp;

	tmp = p.cmd;

	int is_first = 1;
	int is_last = 0;
	while (tmp)
	{
		if ((arr_of_pids[i] = fork()) == 0)
		{
			fprintf(stderr, "Execute cmd: %s, %i\n", tmp->cmd, i);fflush(stderr);
			if (is_first)
			{
				int inf = open(p.file.infile, O_RDONLY);
				dup2(inf, 0);
				close(inf);
			}
			else
				dup2(arr_of_pipes[i][0], 0);
			if (is_last)
			{
				int outf = open (p.file.outfile, O_WRONLY | O_CREAT, 0644);
				dup2(outf, 1);
				close(outf);
			}
			else
				dup2(arr_of_pipes[i + 1][1], 1);
			close_all_pipes(p, &arr_of_pipes);
			if (execve(tmp->path, tmp->args, p.main.envp) == -1)
				perror("line 89 execve");
		}
		else
		{
			is_first = 0;
			tmp = tmp->next;
			if (tmp->next == NULL)
				is_last = 1;
			i++;
		}
		close_all_pipes(p, &arr_of_pipes);
		for (int j = 0; j < argc - 2; j++)
			wait(NULL);
		fprintf(stderr, "WHAAAAT");fflush(stderr);
	}
	// arr_of_pids[i] = fork();
	// if (arr_of_pids[i] == 0)
	// {
	// 	int fd = open (p.file.infile, O_RDONLY);
	// 	dup2(fd, 0);
	// 	dup2(arr_of_pipes[i][1], 1);
	// 	close(fd);
	// 	close_all_pipes(p, &arr_of_pipes);
	// 	fprintf(stderr, "Execute first: %s\n", tmp->cmd);fflush(stderr);
	// 	if (execve(tmp->path, tmp->args, p.main.envp) == -1)
	// 		perror("first execve");
	// }
	// tmp = tmp->next;
	// while (tmp->next)
	// {
	// 	arr_of_pids[i] = fork();
	// 	if (arr_of_pids[i] == 0)
	// 	{
	// 		dup2(arr_of_pipes[i][0], 0);
	// 		dup2(arr_of_pipes[i + 1][1], 1);
	// 		close_all_pipes(p, &arr_of_pipes);
	// 		fprintf(stderr, "loop: [%i] ==> %s\n", i, tmp->cmd);fflush(stderr);
	// 		if (execve(tmp->path, tmp->args, envp) == -1)
	// 			perror("line 74 in execve");
	// 	}
	// 	tmp = tmp->next;
	// 	i++;
	// }
	// arr_of_pids[i] = fork();
	// if (arr_of_pids[i] == 0)
	// {
	// 	int fd = open (p.file.outfile, O_WRONLY | O_CREAT, 0644);
	// 	dup2(arr_of_pipes[i][0], 0);
	// 	dup2(fd, 1);
	// 	close(fd);
	// 	close_all_pipes(p, &arr_of_pipes);
	// 	if (execve(tmp->path, tmp->args, p.main.envp) == -1)
	// 		perror("first execve");
	// }
	return 0;
}