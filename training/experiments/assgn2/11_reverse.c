#include <stdio.h>
//#include <string.h>
extern int my_strlen (char *);

char *my_reverse(char *str)
{
	int i;
	int j;
	char ch;	

	for (i = 0, j = (my_strlen(str) - 1); i < j; i++, j--){
		ch = str[i];
		str[i] = str[j];
		str[j] = ch;
	
	}

	return str;
}
