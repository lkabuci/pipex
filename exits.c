#include "pipex.h"

void	ft_exits(int error, int toExit, int exitStatus)
{
	ft_putstr_fd(2, strerror(error));
	if (toExit == 1)
	{
		exit(exitStatus);
	}
}
