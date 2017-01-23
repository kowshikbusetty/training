#include <stdio.h>

int g_var = 10;

int main(void)
{
	int a_var = 20, b_var;
	
	b_var = g_var + 15;
	printf ("value of b_var : %d\n", b_var);

	return 0;
}
