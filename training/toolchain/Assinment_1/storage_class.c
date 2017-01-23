#include<stdio.h>

void fun(void){};

static int gsi;				//.bss
int un_gi;					//COM
int gi = 3;					//.data
extern int f;				
int f = 40;					//.data
int e = 10;					//.data
const int gci = 100;		//.rodata
const int un_gci;			//COM
static const int gsci = 1;	//.rodata
static const int un_gsci;	//.bss
volatile int gvi = 500;		//.data
volatile int un_gvi;		//COM
static volatile int gsvi = 500;	//.data
static volatile int un_gsvi;	//.bss
const volatile int gcvi = 100;	//.data
const volatile int un_gcv;		//.bss

int *p = NULL;				//.bss
int *un_q;					//COM
int *in_q = &gi;			//.data

int main(void)
{
	int i;	
	static int si;		//.bss
	register int r;
	extern e;

	fun();
	
	const int ci;
	volatile int vi;

	return 0;
}
