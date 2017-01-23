#include <stdio.h>
extern int sum (int, int);

int main (void)
{
	int a = 20;
	int b = 20;
	int c;
	
	c = sum(a,b);	

	printf ("the value of c : %d \n", c);	
	return 0;
}
