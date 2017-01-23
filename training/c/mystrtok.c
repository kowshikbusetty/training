/* it prints every string after delimiter */

#include "header.h"

char *mystrtok(char *buff,char *delim)
{
	int i = 0;
	int j = 0;	
	

	while(*(buff + j)) {	

		while(*(delim + i)) {
			if(*(buff + j) == *(delim + i)) {
				*(buff + j) = '\n';
				break;
			}

			i++;
		}

		j++;
		i = 0;
	}

	return buff;
}

 
		

