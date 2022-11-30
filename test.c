#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "pipex.h"

int main(int argc, char const *argv[], char *envp[])
{
	char *av[] = {"ls", NULL};
	int fd = open("outfile", O_WRONLY | O_CREAT, 0777);
	if (fd == -1)
		perror("outfile");
	dup2(fd, STDOUT_FILENO);
	// close(fd);
	execve("/bin/ls", av, NULL);
	return 0;
}
