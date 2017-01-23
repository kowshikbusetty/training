#include <stdio.h>
#include <stdlib.h>
#define offset 32
#define MAX 256

int main (void)
{
	char *str = NULL;
	unsigned int i;

	if (NULL == (str = (char *)malloc(sizeof(char) * MAX))){
		perror ("malloc failed....... \n");
		exit (1);
	}

	do{

	printf ("enter the string str : \n");

	if (NULL == (fgets(str, MAX, stdin))){
		perror ("fgets for str is failed.... \n");
		exit (1);
	}

	
	for (i = 0; str[i]; i++){

		if ((str[i] >= 'A') && (str[i] <= 'Z')){
			str[i] = str[i] + offset;

		} else if ((str[i] >= 'a') && (str[i] <= 'z')){
					str[i] = str[i] - offset;

				} else {
						str[i] = str[i];
				  }
	}

	printf ("after conversion : %s \n",str);
	
	}while (str[0] != '$');

	return 0;
}
