#include <stdlib.h>
#include <stdio.h>


int main(int argc, char* argv[], char* envp[])
{

	if (argc == 2)
	{
		int retval = atoi(argv[1]);
		return retval;
	}
	else
	{
		printf("WRONG ARG COUNT (%d): Sorry, you need to specify ONE variable (and only one).",argc);
	}
	return -1;

}
