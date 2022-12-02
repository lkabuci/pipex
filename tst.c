#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	pid_t pid = fork();
	if (!pid)
	{
		printf("Hello\n");
		exit(1);
	}
	wait(NULL);
	printf("HERE\n");
}