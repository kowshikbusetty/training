#include <stdio.h>
char *my_squeze(char *str)
{
	int i;
	int j;

	for (i = 0; str[i]; i++){
		
		if (str[i] == str[i + 1]){

			for (j = i; str[j]; j++){
				str[j] = str[j + 1];

			}

		i--;

		}

	}
	
	return str;
}
