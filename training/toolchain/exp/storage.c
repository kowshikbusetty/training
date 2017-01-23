

# include <stdio.h>

int a;					//stored as common symbols and uninitialized
volatile int b;			//stored as common symbol and uninitialized
const volatile c;		//stored as common symbol and uninitialized
volatile int d = 5;		//initialized data section
const volatile e = 9;	//initialized data section
static const sc;		//uninitialized data section bss
static const sc1 = 66;	//read only data section
const static ex1 = 15;	//ro section
const static ex2;		//bss section
const int i;			//symbol is common and uninitialized
const int j = 10;		//read only data section
static int si;			//uninitialized data section bss
static int sj = 20;		//initialized data section

int main(void)
{
	static int sk;				//uninitialized data section bss
	static int sl = 25;			//initialized data section
	const int k;				
	const int ck = 30;
	const static int csi = 4;
	const static int csi2;
	printf("global a = %d\n", a);
	printf("volatile b = %d\n", b);
	printf("const volatile c = %d\n", c);
	printf("volatile d = %d\n", d);
	printf("const volatile e = %d\n", e);
	printf("static const sc = %d\n", sc);
	printf("static const sc1 = %d\n", sc1);
	printf("const i = %d\n", i);
	printf("const j = %d\n",  j);
	printf("static si = %d\n", si);
	printf("static sj = %d\n", sj);
	printf("static sk = %d\n", sk);
	printf("static sl = %d\n", sl);
	printf("const k = %d\n", k);
	printf("static ck = %d\n", ck);
	printf("Static int csi : %d\n", csi);

	return 0;
}
