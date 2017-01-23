#include <stdio.h>

void showbits (int);

//this experiment is converting the decimal to binary
#if 0
int main(void)
{
	int num;
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

#if 1
int main(void)
{
	int num = 0x12345678;
	int mask = (~((~0) << 4));
	int temp = 0;

	printf("Input  : 0x%08x \n", num);
	
	while(mask){

		temp = (num & (mask << 8)) >> 8;
		num = (((num & mask) << 8 ) | ( num = num & (~(mask << 8))));
		num = ((num = num & (~mask)) | temp);

		mask = mask << 16;
	}

	printf("Output : 0x%08x \n", num);

	return (0);
}
#endif
