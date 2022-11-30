#include "pipex.h"

int main(int ac, char **av, char **env) 
{
	t_params	p;

	p.main_params.ac = ac;
	p.main_params.av = av;
	p.main_params.env = env;
	parsing(&p);
	pipex(&p);
	return 1;
}

