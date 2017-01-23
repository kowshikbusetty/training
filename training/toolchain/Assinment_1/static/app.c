#include<stdio.h>
#include<stdlib.h>
#include<mathops.h>

int main(void)
{
	int c, d, e, f;
	c = sum(9, 4);
	d = dif(9, 4);
	e = mul(9, 4);
	f = divi(9, 4);

	printf ("value of c = %d \n", c);
	printf ("value of d = %d \n", d);
	printf ("value of e = %d \n", e);
	printf ("value of f = %d \n", f);

	
	return 0;
}
