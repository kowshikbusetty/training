#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MB (1024 * 1024)
int main(void)
{
	int *p = NULL;
	int cnt = 0;
	
	printf ("PID = %d \n", getpid());

	do{
		p = (int *)malloc(MB);
		cnt++;
	}while(p != NULL);

	printf("Memory allocated is : %d MB \n", cnt);

	getchar();

	return 0;
}
