
#include <stdio.h>
# include <stdlib.h>

void myfree(void *);

int main(void)
{
	int *p;
	p = (int *) malloc (sizeof (int));
	*p = 10;
	printf("*p = %d\n", *p);
	myfree(p);
	printf("after myfree : p = %p\n *p = %d\n",p, *p);
	return 0;
}
void myfree(void *ptr)
{
	free(ptr);
	ptr = NULL;
	return;
}
