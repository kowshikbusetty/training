#include <stdio.h>
//#include <string.h>
extern int my_strlen (char *);

void string_palindrome(char *str)
{
	int i;
	int j;

	for (i = 0, j = (my_strlen(str) - 1); i <= j; i++, j--){
		
		if (str[i] == str[j])
			continue;
		else
			break;

	}
	
	if (i > j)
		printf ("string pallindrome \n");
	else
		printf ("Not pallindome \n");


}
