#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i = 2;
	while (i < argc - 1)
	{
		printf("%s\n", argv[i++]);
	}
	return 0;
}