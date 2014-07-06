#include <stdio.h>

int main(int argc, char* argv[], char* envp[])
{
  argc--;
	argv++; // re-align

  if (argc > 1)
	{
		printf("Too many arguments");
	}

}
