#include <stdio.h>

void showbits (int);
int main(void)
{

	struct abc{
		int arr[0];
		}str_a;

	unsigned int a = -5;
//	showbits(a);

	a = a >> 1;

//	showbits(a);

	printf("%d\n", sizeof(str_a));

	return 0;
}	
