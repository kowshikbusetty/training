#include <stdio.h>

int my_global = 42;

int my_fun(int a, int b)
{
	my_global += a;

	return (my_global + b);	
}
