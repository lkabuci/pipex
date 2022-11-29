#include "pipex.h"

int main(int ac, char **av, char **envp) {
	t_params p;

	p.ac = ac;
	p.av = av;
	p.envp = envp;
	parse(&p);
	// while (1);
	return 1;
}

