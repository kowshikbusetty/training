#include <stdio.h>
//#include <string.h>
extern int my_strlen (char *);

char temp[100];

char *remstr(char *str, const char *sstr)
{
	int len2;
	int i;
	int j;
	int k;

	len2 = my_strlen ((char *)sstr);
	
	for (i = 0; str[i]; i++){

		if (str[i] == sstr[0]){

			for (j = 1; sstr[j]; j++){
				if (str[i + j] == sstr[j])
					continue;
				else
					break;
			}
	
			if (sstr[j] == '\0'){	
				break;
			}

		}
	}

	if (str[i] != '\0'){
		for (k = 0; str[k]; k++){
			if(k < i)
				temp[k] = str[k];
			else
				temp[k] = str[k + len2];
		}
		return temp;
	}
	else
		return 0;

}

