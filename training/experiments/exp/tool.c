#include <stdio.h>
int a = 10;
static int b = 5;
void func(void)
{
	a++;
	b++;
	printf ("in func \n");
	printf ("%u , %d \n", (unsigned)&a, a);
	printf ("%u , %d \n", (unsigned)&b, b);


}
int main(void)
{
	func();
	a++;
	b++;
	printf ("in main \n");
	printf ("%u , %d \n", (unsigned)&a, a);
	printf ("%u , %d \n", (unsigned)&b, b);
	
	func();
	return 0;
}
