#include "pipex.h"

int main(int ac, char **av, char **envp) {
	t_params p;

	p.ac = ac;
	p.av = av;
	p.envp = envp;
	char	**command1;
	char	**command2;

	command1 = ft_split(av[2], ' ');
	command2 = ft_split(av[3], ' ');
	p.cmd1 = command1[0];
	p.cmd2 = command2[0];
	p.cmd1_flags = command1[1];
	p.cmd2_flags = command2[1];
	// parse(&p);
	while (1);
	return 1;
}

