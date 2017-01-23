#include <stdio.h>
int my_atoi (char *p)
{
	int i;
	int sum = 0;
	for (i = 0; p[i]; i++)
	sum = sum * 10 + p[i] - 48;

	return sum;
}
