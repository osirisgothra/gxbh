#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


int main(int argc, char* argv[], char* envp[])
{
	char* endptr = NULL;
	char* num = NULL;
	bool last_unreadable = false;
	int readable_count = 0;
	int unreadable_count = 0;
	double frep = 0;

	if (argc >= 2)
	{
		while (argc > 1)
		{
			num = argv[1];
			if (strlen(num) > 0)
			{
				double frep = strtod(num,&endptr);
				cout << frep << endl;
				// now check and make sure if it was zero, that it was indeed 0 passed through the command line
				// this will be true when hex values like 0x0 are passed since we just need to check the first number
				// if the strlen was > 1 then it fails anyways however
				if ( (strcmp(num,"0x0")) && ( (frep == 0 && strlen(num) > 1) || (frep == 0 && ( num[0] < '1' || num[0] > '9' )) ))
					unreadable_count++;
				else
					readable_count++;
			}
			else
			{
				cout << -1 << endl;
				// unreadable, but next argument may be readable, to keep sync we need to output a -1
				// so the user knows that this value is unreadable
				unreadable_count++;
			}
			argc--;
			argv++;
		}
		if (readable_count == 0)
			return 1;		// none were readable
		else if (unreadable_count > 0)
			return readable_count+1;		// some were unreadable, return count (+1 distingushes it from the usual error code)
		else
			return 0; // success (all items readable!)
	}

	cout << 0 << endl;
	return 1; // failed
}
