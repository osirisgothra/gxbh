#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory.h>
#include <string.h>

int main(void)
{	
	char c  = EOF;
	while (c == EOF)
		c = getchar();
	printf("%c",c);
	return c;
}

