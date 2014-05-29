#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

using namespace std;

int main(void) 
{
	printf( "login: " );
	char* login_name = new char[255];
	memset(login_name,0,255);

	char nextbyte = 0;
	unsigned int i = 0;
	while (nextbyte != 10 && i < 255)
	{
		nextbyte = getchar(); // enter new item
		if (nextbyte != 10)
			login_name[i] = nextbyte;
		else
			login_name[i] = '\0';
		i++;
	}

   char *newargv[] = { "/bin/login", "-f", NULL, NULL };
   char *newenviron[] = { NULL };

   newargv[2] = login_name;

   execve(newargv[0], newargv, newenviron);
   perror("execve");   /* execve() only returns on error */	 
  
	 printf("returned with an error");
	 delete[] login_name; 
	 return 0;
}

