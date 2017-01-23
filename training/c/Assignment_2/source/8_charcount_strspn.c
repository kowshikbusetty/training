#include <stdio.h>
//#include <string.h>
extern int my_strlen (char *);

int count = 0;

int my_strspn(const char *buf1, const char *buf2)
{
	
	int i;
	int j;
	int len2;
	
	len2 = my_strlen((char *)buf2);

	for (i = 0; buf1[i]; i++){
		for (j = 0; buf2[j]; j++){
			if (buf1[i] == buf2[j]){
				count++;
				break;
			}
		}
			if (len2 == j)
				break;
	}

	return count;
}
