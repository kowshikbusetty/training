#include <stdio.h>

void showbits (int);

//this experiment is converting the decimal to binary
#if 1
int main(void)
{
	unsigned int num;
	printf("enter the num: \n");
	scanf("%d", &num);

	showbits (num);	

	return (0);
}
	
void showbits (int num)
{
	int i;
	for (i=31; i>=0; i--){
		printf ("%d", (num>>i)&1);
	}
	
	printf ("\n");
}
#endif



