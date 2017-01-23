#include <stdio.h>
//#include <string.h>
extern int my_strlen (char *);

char *sappend(char *str1, char *str2)
{
	int i;
	int len2;

	len2 = my_strlen(str2);

	 for (i = 0; str1[i]; i++){
		str2[len2 + i] = str1[i];
		}

	str2[len2 +i] = '\0';	

	return str2;	
}
