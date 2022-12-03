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
	parse(&p);
	printf("%s\n", p.file.infile);
	printf("%s\n", p.file.outfile);
	while (p.cmd->next != NULL)
	{
		printf("cmd: %s\n", p.cmd->cmd);
		printf("args: %s\n", p.cmd->args);
		printf("path: %s\n", p.cmd->path);
		printf("========================\n");
		p.cmd->next++;
	}
	
	return 0;
}
