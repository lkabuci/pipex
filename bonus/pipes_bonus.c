#include "pipex_bonus.h"

void	redirect_input(t_params *p)
{
	int	fd;

	fd = open(p->file.infile, O_RDONLY);
	if (fd == -1)
	{
		printf("I don't know why this is not opening\n");
		perror(p->file.infile);
		// print_error("bash", p->cmd1.file, "No such file or directory");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, 0) == -1)
	{
		perror("dup");
	}
	close(fd);
}


void	redirect_output(t_params *p)
{
	int	fd;

	fd = open(p->file.outfile, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, 1) == -1)
	{
		perror("dup");
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void    close_all_pipes(t_params p, int	***arr_of_pipes)
{
	int	**tmp;
	int	i;

	i = 0;
	tmp = *arr_of_pipes;
	if (!tmp)
		return ;
	while (i < p.ncmd)
	{
		close(tmp[i][0]);
		close(tmp[i][1]);
		// tmp++;
		i++;
	}
}