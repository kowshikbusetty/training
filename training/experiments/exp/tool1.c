#include <stdio.h>
int f;
int g;
int d = 40;
int func(void)
{
	int a;
	printf ("a = %u %d \n", (unsigned)&a, a);
	int b = 10;
	int c = 30;
	printf ("b = %u %d \n", (unsigned)&b, b);
	printf ("c = %u %d \n", (unsigned)&c, c);
	printf ("d = %u %d \n", (unsigned)&d, d);
	printf ("f = %u %d \n", (unsigned)&f, f);
	printf ("g = %u %d \n", (unsigned)&g, g);
	return 0;
}
