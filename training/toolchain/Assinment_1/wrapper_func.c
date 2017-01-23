#include<stdio.h>
#include<stdlib.h>

void my_free(void * ptr)
{
	free(ptr);
	ptr = NULL;
}

int main(void)
{
	int *p = NULL;
	int i;
	
	p = (int *)malloc(5 * sizeof(int));
	printf ("P = %p \n", p);

	for(i = 0; i<5; i++){
		p[i] = i + 10;
	}
	printf("printing contents of p: \n");

	for(i = 0; i<5; i++)
		printf ("p[%d] = %d\n", i, p[i]);

	my_free(p);
	printf("\np : %d \n", *p);

	return 0;
}
