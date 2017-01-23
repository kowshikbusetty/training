#include <stdio.h>
char my_strcmp (char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] || str2[i]; i++){
		if (str1[i] == str2[i]){
			continue;
		}else {
				if (str1[i] < str2[i])
					return -1;
				else
					return 1;
			  }
	}
	
	return 0;

}
