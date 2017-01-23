#include <stdio.h>
#include <stdlib.h>
#define offset 32
#define MAX 256

char *case_conversion (char * str)
{
	unsigned int i;

		for (i = 0; str[i]; i++){

			if ((str[i] >= 'A') && (str[i] <= 'Z')){
				str[i] = str[i] + offset;

			}
		}


	return str;
}
