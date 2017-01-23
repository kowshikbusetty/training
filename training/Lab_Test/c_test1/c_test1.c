#include <stdio.h>

extern void showbits (int);

void left_n_rotate (int num, int n)
{
	num = ((unsigned)num << n) | ((unsigned)num >> (sizeof(int) * 8 - n));	

	showbits (num);		//converts decimal into binary and displays the bits 
}

void right_n_rotate (int num, int n)
{
	num = ((unsigned)num >> n) | ((unsigned)num << (sizeof(int) * 8 - n));	

	showbits (num);		//converts decimal into binary and displays the bits 
}

int main(void)
{
	int num;
	int n;
	int op;

	printf ("enter the number : \t");
	scanf ("%d", &num);

	showbits (num);		//converts decimal into binary and displays the bits 
	
	printf ("enter number of rotations : \t");
	scanf ("%d", &n);

	printf ("enter the option 1. left rotate 2. right rotate : \t");
	scanf ("%d",&op);

	switch (op){

	case 1 : left_n_rotate (num, n);
			 break;

	case 2 : right_n_rotate (num, n);
			 break;

	default : printf ("enter correct option \n");

	}

	return 0;
}
