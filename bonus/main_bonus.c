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

int	main(int argc, char **argv, char **envp)
{
	t_main		main;
	t_params	p;

	main.ac = argc;
	main.av = argv;
	main.envp = envp;
	p.main = main;
	p.cmd = NULL;
	parse(&p);
	printf("%s\n", p.file.infile);
	printf("%s\n", p.file.outfile);
	int i = -1;
	while (p.cmd != NULL)
	{
		i = -1;
		printf("cmd: %s\n", p.cmd->cmd);
		while (p.cmd->args[++i] != NULL)
		{
			printf("args: %s\t", p.cmd->args[i]);
		}
		printf("\n");
		printf("path: %s\n", p.cmd->path);
		printf("========================\n");
		p.cmd = p.cmd->next;
		sleep(1);
	}
	
	return 0;
}
