#include <stdio.h>
#define offset 32
int my_is_alpha(char);

char my_strcasecmp (char *str1, char *str2)
{
	int i;
	unsigned char m;
	unsigned char n;
	
	for (i = 0; str1[i]; i++){

		if ((str1[i] == str2[i]) || (str1[i] + offset == str2[i]) ||
												 (str1[i] - offset == str2[i])){
		
			m = my_is_alpha(str1[i]);
			n = my_is_alpha(str2[i]);
			if(m != n){	
				if (str1[i] < str2[i])
					return -1;
				else
					return 1;
			}
			else{
				continue;
			}
		 } 
		 else {
				if (str1[i] < str2[i])
					return -1;
				else
					return 1;
			  }
	}
	
	return 0;

}

int my_is_alpha(char a)
{

	if((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
		return 1;
	else
		return 0;

}


