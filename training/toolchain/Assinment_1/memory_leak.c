#include <stdio.h>
#define MAX 1050
 

int main(void)
{
/*	char a[3] = {'1', '2', '3'};

//	a[4] = 100;	
	a[MAX] = '4';
//	a[100] = 100;

//	a[900] = 100;
//	printf ("a[%d] = %c \n",MAX, a[MAX]);
*/

	int b[3] = {1, 2, 3};

	b[4] = 4;

	b[MAX] = MAX;
	printf ("b[%d] = %d \n",MAX, b[MAX]);

	return 0;
}
