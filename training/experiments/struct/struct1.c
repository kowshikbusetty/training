#include <stdio.h>
#if 0
int *p;
int main(void)
{
*p = 45;
	
	return 0;
}
#endif

#if 0
int main(void)
{
	struct abc {
		int a : 4;
		char ch;
		short sh;
		int b : 5;
		int  : 0;
		short d : 2;
		short sh2:5;
		char ch2 : 5;
		int : 0;
		int abc : 1;
				
	
	}a;	
	
	printf("%d \n", sizeof(a));
	
	return 0;
}
#endif

#if 0

int main (void)
{
	struct record {
		char ch;
		int set;
	}rec;

	
	printf("%d \n", sizeof(struct record));
	printf ("%p \n", &rec.ch);
	printf ("%p \n", &rec.set);

	printf("%d \n", sizeof(rec.ch));
	printf("%d \n", sizeof(rec.set));

	return 0;
}
#endif

#if 0
	struct node {
		int a;
		char c;
		int b;
    }no;

struct link {
	char a;
	short i;
      }li;


struct pan {
	char ch;
	int a;
	char p;
     }pa;

 struct can {
	char m;
	char c;
	int n;
      }ca;
struct mms {
	char ch;
	short s;
	int n;
      }mm;

struct nm {
	char c;
    }nm;

struct art {
	short s;
	short vn;
	char ch;
      }ar;
struct quier {
	short s;
	short n;
	int m;
     }qu;
struct covet {
	short s;
	int n;
	short m;
      }co;

	struct{
	short d;
	int a;
	short c;
	short s;
	}my;

int main(void)
{

	printf (" size of node : %d \n", sizeof(struct node));

	printf ("%p \n", &no.a);
	printf ("%p \n", &no.b);
	printf ("%p \n", &no.c);

	printf (" size of link : %d \n", sizeof(struct link));
	printf ("%p \n", &li.a);
	printf ("%p \n", &li.i);
	
	printf (" size of pan : %d \n", sizeof(struct pan));
	printf ("%p \n", &pa.ch);
	printf ("%p \n", &pa.a);
	printf ("%p \n", &pa.p);
	
	printf (" size of can : %d \n", sizeof(struct can));
	printf ("%p \n", &ca.m);
	printf ("%p \n", &ca.c);
	printf ("%p \n", &ca.n);
	
	printf (" size of mms : %d \n", sizeof(struct mms));
	printf ("%p \n", &mm.ch);
	printf ("%p \n", &mm.s);
	printf ("%p \n", &mm.n);
	
	printf (" size of nm : %d \n", sizeof(struct nm));
	printf ("%p \n", &nm.c);
	
	printf (" size of art : %d \n", sizeof(struct art));
	printf ("%p \n", &ar.s);
	printf ("%p \n", &ar.vn);
	printf ("%p \n", &ar.ch);
	
	printf (" size of quier : %d \n", sizeof(struct quier));
	printf ("%p \n", &qu.s);
	printf ("%p \n", &qu.n);
	printf ("%p \n", &qu.m);
	
	printf (" size of covet : %d \n", sizeof(struct covet));
	printf ("%p \n", &co.s);
	printf ("%p \n", &co.n);
	printf ("%p \n", &co.m);
	
	printf (" size of my : %d \n", sizeof(my));
	printf ("%p \n", &my.d);
	printf ("%p \n", &my.a);
	printf ("%p \n", &my.c);
	printf ("%p \n", &my.s);
	return 0;
}
#endif
