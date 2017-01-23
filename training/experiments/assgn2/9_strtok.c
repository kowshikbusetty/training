#include <stdio.h>
char temp[100];

char * my_strtok(const char *buf, const char *delim)
{
	int i = 0;
	int j;
	int n;

	while (*(buf + i)){
		for (j = 0;delim[j]; j++){
			if (buf[i] == delim[j]){
				n = i;
				break;
			} else {
				continue;
			}
		}
		i++;
	}

	for(i = 0; i < n; i++)
		temp[i] = buf[i];

/*	while (*(buf + i)){
		for (j = 0;delim[j]; j++){
			if (buf[i] != delim[j]){
				temp[i] = buf[i];
				continue;
			} else {
				temp[i] = '\n';
				break;
			}
		}
		i++;
	}
*/	
	return (temp);
}
	
