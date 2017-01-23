#include <stdio.h>
//#include <string.h>
extern int my_strlen (char *);

char *snappend(char *str1, char *str2,int n)
{
	int i;
	int len1;
	int len2;

	len1 = my_strlen(str1);
	len2 = my_strlen(str2);
	
		for (i = 0; (str1[i]) && (i < n); i++)
			str2[len2 + i] = str1[i];
			
		str2[len1 +i] = '\0';	
			
		return str2;	
}

