//experiment 1: swapping the bits between 2 positions 
#if 0
#include <stdio.h>
extern void showbits (int);

int bit_swap (int n, int s, int d)
{
	int m;
	int l;
	
	m = (n >> d) & 1u;
	l = (n >> s) & 1u;
	if ( m != l ){
		n ^= 1 << s;
		n ^= 1 << d;
	}
	
	return n;
}

int main (void)
{
	int n;
	int s;
	int d;
	int i;
		
	printf ("enter the number : \t");
	scanf ("%d", &n);

    printf ("enter source and destination positions : \t");
	scanf ("%d%d", &s, &d);

	printf ("bits before swapping : \t");

	showbits (n);	                	 // displays binary form of a decimal 

	n = bit_swap (n, s, d);
	
	printf ("after swaping the number is : %d\n", n);
	printf ("bits after swappting : \t");

	showbits (n);				   		 // displays binary form of a decimal  

	return 0;
}

#endif

//experiment 2 : swap bit values between 2 numbers for given positions

#if 0
#include <stdio.h>
extern void showbits (int);

int main(void)
{
	int snum;
	int dnum;
	int s;
	int d;

	printf ("enter snum : \n");
	scanf ("%d",&snum);

	showbits (snum);					 // displays binary form of a decimal

	printf ("enter dnum : \n");
	scanf ("%d",&dnum);

	showbits (dnum); 					 // displays binary form of a decimal

	printf (" enter s position & d position : \n");
	scanf ("%d%d", &s, &d);

	
	int m;
	int n;

	m = (snum >> s) & 1u;
	n = (dnum >> d) & 1u;

	if (m != n){	
		snum ^= 1 << s;
		dnum ^= 1 << d;	
	}

	printf ("after swapping the bit,the snum is : \t");
	
	showbits (snum);					 // displays binary form of a decimal

	printf ("after swapping the bit,the dnum is : \t");

	showbits (dnum); 					 // displays binary form of a decimal

	return 0;
}
#endif


//experiment 3 : implementation of bit_copy function

#if 0
#include <stdio.h>                                                              
extern void showbits (int);

void bit_copy (int snum, int dnum, int n, int s, int d)
{
	int i;
	int j;
	int m;
	int l;

	for (i = s, j = d; i >= s-n+1; i--, j--){
		m = snum >> i & 1u;
		l = dnum >> j & 1u;
		
		if (m != l){
			dnum ^= 1 << j;
		}
	}

	printf ("after copying the bits dnum is : %d \n", dnum);	
	showbits (dnum); 					 // displays binary form of a decimal
}

int main(void)
{
	int snum;
	int dnum;
	int s;
	int d;
	int n;

	printf ("enter snum : \n");
	scanf ("%d",&snum);

	showbits (snum);					 // displays binary form of a decimal
	
	printf ("enter dnum : \n");
	scanf ("%d",&dnum);

	showbits (dnum);					 // displays binary form of a decimal
		
	printf (" enter s position & d position : \n");
	scanf ("%d%d", &s, &d);
	
	printf ("enter no. of bits to copy: \n ");
	scanf ("%d", &n);
		
	bit_copy (snum, dnum, n, s, d);

	return 0;	

}
#endif

//experiment 4 : even and odd bit toggle functions implementations

#if 0
#include <stdio.h>
extern void showbits (int);

int even_bit_toggle (int num)
{
	int key = 1u;
	while(key){
		num = num ^ key;
		key <<= 2;
		}
    return num;
}

int odd_bit_toggle (int num)
{
	int key = 2u;

	while(key){
		num = num ^ key;
		key <<= 2;
	}

    return num;
}

int main(void)
{
	int num;
	int op;


	printf ("enter the number: \n");
	scanf ("%d",&num);
	showbits (num);						 // displays binary form of a decimal
	
	printf (" Enter the option 1)even bit toggle 2) odd bit toggle : \t");
	scanf ("%d", &op);

	switch (op){
 
	case 1 : num = even_bit_toggle (num);
			 showbits(num);				 // displays binary form of a decimal
			 break;	

	case 2 : num = odd_bit_toggle (num);
			 showbits(num);	 			 // displays binary form of a decimal
			 break;

	default : printf ("enter correct option.. \n");

	}	

	return 0;
}
#endif

//experiment 5 : To check whether a particular position in a num is set or not

#if 0
#include <stdio.h>
extern void showbits (int);
#define bit_ts(num, pos) if((num >> pos) & 1)\
							printf ("bit is already set \n");\
						 else \
							num |= (1 << pos);		 
					

int main(void)
{
	int num;
	int pos;

	printf ("enter the number : \n");
	scanf ("%d", &num);
	
	printf ("enter the position : \n");
	scanf ("%d", &pos);

	showbits (num);						 // displays binary form of a decimal

	bit_ts(num, pos) 

	showbits (num);						 // displays binary form of a decimal
	
	return 0;
}
#endif


/*experiment 6 : implementing functionsfor right rotate, left rotate,
left rotate for n bits and right rotate for n bits */

#if 0

#include <stdio.h>
extern void showbits (int);
int temp;

unsigned int right_rotate_bits (unsigned int num)
{
	temp = num & 1u;
	temp <<= (sizeof(int) * 8 - 1);
	num >>= 1;
	num |= temp;
	
	return num;
}

unsigned int left_rotate_bits (unsigned int num)
{
	temp = (num >> (sizeof(int) * 8 - 1) & 1u);
	num <<= 1;
	num |= temp;

	return num;
}

unsigned int right_rotate_n_bits (unsigned int num, int n)
{	
	while (n){
		temp = num & 1u;
		temp <<= (sizeof(int) * 8 - 1);
		num >>= 1;
		num |= temp;
		n--;
	}
	
	return num;
}

unsigned int left_rotate_n_bits (unsigned int num, int n)
{


	while (n){
		temp = (num >> (sizeof(int) * 8 - 1) & 1u);
		num <<= 1;
		num |= temp;
		n--;
	}

	return num;
}

int main()
{
	unsigned int num;
	int op;
	int n;
	
	printf ("enter number= \t");
	scanf ("%d",&num);

	printf ("before shifting:\n");
	showbits (num);                      // displays binary form of a decimal 

	printf ("enter option: \n");
	printf ("1)left rotate, 2)right rotate, \n");
	printf ("3)left rotate with n bits, 4)right rotate with n bits \n");
	scanf ("%d", &op);

	switch (op) 
	{
	case 1:
    	    num = left_rotate_bits (num);

        	printf ("number after left rotate: %d\n",num);
        	showbits (num);              // displays binary form of a decimal 
        	break;
	case 2:
        	num = right_rotate_bits (num);  

        	printf ("number after right rotate: %d\n",num);
			showbits (num);              // displays binary form of a decimal 		
        	break;

	case 3:
			printf ("enter no. of shifts=\t");
			scanf ("%d", &n);

    	    num = left_rotate_n_bits (num, n);

        	printf ("number left rotate: %d\n",num);
        	showbits (num);              // displays binary form of a decimal 
        	break;
	case 4:
			printf ("enter no. of shifts=\t");
			scanf ("%d", &n);
        	
			num = right_rotate_n_bits (num, n);  

        	printf ("number after right rotate: %d\n",num);
			showbits (num);              // displays binary form of a decimal 		
        	break;

	default: 
			printf ("enter correct option... \n ");

	}

	return 0;
}

#endif

#if 0
#include <stdio.h>
//experiment 7 :to count no. of 1's & count no. of zeros in a number
void count_bit_set (int);
void count_bit_clear (int n);
extern void showbits (int);
int main (void) 
{
	int n;

	printf("enter the number: \n");
	scanf("%d", &n);

	showbits (n);        			    // displays binary form of a decimal

	count_bit_set (n);
	count_bit_clear (n);

	return 0;
}

void count_bit_set (int n)
{
	int s = 0;

	while (n != 0){
		if (( n & (1u << sizeof(int) * 8 -1)) != 0 )
			s++;
		n = n << 1;
	}

	printf ("number of ones-%d \n", s);

}

void count_bit_clear (int n)
{
	int c = 0;
	int i;
	int m;
                                                                                
    for (i =0; i <= (sizeof(int) * 8 - 1); i++){                                
        m = (n >> i) & 1u;                                                    
        if(m == 0)                                                              
            c++; 
	}

	printf ("number of zeros-%d \n", c);

}

# endif

//experiment 8 : counting ones & zeros at leading & tailing ends
#if 1
#include <stdio.h>
extern void showbits (int);
int cnt_leading_cleared_bits (int);
int cnt_leading_set_bits (int);
int cnt_trailing_cleared_bits (int);
int cnt_trailing_set_bits (int);

int num;
int c;
int i;
int m;

int main (void)
{

	int b;

	printf ("enter the number:");
	scanf ("%d", &num);
	showbits (num);         		   // displays binary form of a decimal

//	printf ("enter option to count, 1. leading ones,2. leading zeros \n");
//	printf ("3. tailing zeros, 4. tailing ones \n ");
	
	b = cnt_leading_set_bits (num);
	printf ("no. of leading ones is: %d \n",b);

	b = cnt_leading_cleared_bits (num);
	printf ("no. of leading zeros is: %d \n",b);

	b = cnt_trailing_cleared_bits (num);
	printf ("no. of tailing zeros is: %d \n",b);

	b = cnt_trailing_set_bits (num);
	printf ("no. of tailing ones is: %d \n",b);

	return 0;
}

int cnt_leading_cleared_bits (int num)
{

	int	c = 0;
	int i;

	for (i = (sizeof(int) * 8 -1); i >= 0; i--){
		m = (num >> i) & 1u;
		if(m == 0)	
			c++;
		else
			break;
	}
	 
	return c;

}

int cnt_leading_set_bits (int num)
{
	c = 0;

	for (i = (sizeof(int) * 8 - 1); i >=0; i--){
		m = (num >> i) & 1u;
		if(m == 1)	
			c++;
		else
			break;
	}

	return c;
}

int cnt_trailing_cleared_bits (int num)
{
	c = 0;

	for (i =0; i <= (sizeof(int) * 8 - 1); i++){
		m = (num >> i) & 1u;
		if(m == 0)
			c++;
		else
			break;
	}

	return c;
}

int cnt_trailing_set_bits (int num)
{
	c =0;

	for (i =0; i <= (sizeof(int) * 8 - 1); i++){
		m = (num >> i) & 1u;
		if(m == 1)
			c++;
		else
			break;
	}

	return c;
}
#endif



