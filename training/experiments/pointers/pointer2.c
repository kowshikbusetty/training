#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showbits (int num)
{
	int i;
	for (i = 31; i >= 0; i--)
		printf ("%d ", (num >> i) & 1);
	printf ("\n");
}      

#if 1
int main(void)
{
	char a[4] = {10, 20, 30, 40};
	int b = 0;
/*	b = b + (a[0] );
	b = b * 10 + (a[1]);
	b = b * 10 + (a[2]);
	b = b * 10 + (a[3]);

	printf ("%d\n", b);
*/
	b = (int *)&a;

	printf("%08x\n", b);

	printf("%d \n", *((char*)b));
	printf("%d \n", *(((char*)b) + 1));
	printf("%d \n", *(((char*)b) + 2));
	printf("%d \n", *(((char*)b) + 3));
	
//	printf("%s \n","absv", "%s \n","abcd");
	showbits(b);
	
	return 0;
}
#endif

#if 0
char *s = "char *s = %c%s%c;main(){printf(s,34,s,34);}"; 
main(){printf(s,34,s,34);}
#endif


#if 0
int main(void)
{
	int a = 1234;
	char b[4];
	int i = 0;
//	*b = *(char *)&a;
//	strcpy (b, ((char *)&a));

//	*b = (char *)a;
	for (i = 3; i >= 0; i--) {
		b[i] = a%10;
		a = a/10;
	}

	printf ("%d\n", *(b));
	printf ("%d\n", *(b + 1));
	printf ("%d\n", *(b + 2));
	printf ("%d\n", *(b + 3));
/*	printf("%08x \n", b[0]);
	printf("%08x \n", b[1]);
	printf("%08x \n", b[2]);
	printf("%08x \n", b[3]);

*/
	return 0;
}
#endif
