#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "pipex.h"

int main(int argc, char const *argv[], char *envp[])
{
	char *args[] = {"ls", "-l", "-a", NULL};
	execve("/bin/ls", args, NULL);
	return 0;
}
