#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 0
int main(void)
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


	printf ("%d \n", sizeof(a));
	printf ("%d \n", sizeof(a[10]));
	printf ("%d \n", sizeof(&a));
	 
	
	printf ("%p \n", a);
	printf ("%p \n", a + 1);
	printf ("%p \n", (&a + 1));

	return 0;
}

#endif

#if 0

int main(void)
{
	int a[10];
	int *p = NULL;
	p = &a;

	printf ("%p \n", a);
	printf ("%p \n", &a);

	return 0;
}
#endif

#if 0
int main(void)
{
	int a[10];
	int (*p)[10] = NULL;
	p = &a;

	printf ("%p \n", a);
	printf ("%p \n", &a);

	return 0;
}
#endif

#if 0
typedef int (*INTARRAY)[10];
typedef int INTARR [10];
INTARRAY a;
INTARR b = {1, 2, 3, 4, 5};

int main(void)
{

	a = &b;
	
	printf ("sizeof a = %d \n", sizeof(a));

	b[5] = 6;

	printf ("b[5] = %d \n", (*a)[5]);


	return 0;
}
#endif


#if 0

int main(void)
{

	int a[5];
	int b[5];
	
	int *pa;
	pa = a;
	
	printf ("%p \n", pa);
	pa++;

	printf ("%p \n", pa);

	return 0;
}
#endif

#if 1
int main (void)
{
	
	char buf[64];
	
	buf[40] = '2';

	int *n;

	n = (int *)buf;

	printf ("%c \n", n[10]);

	return 0;
}
#endif


#if 0
int main(void)
{
	char *p = NULL;
	int n = 0x5042;
	p = (char *) &n;
	
	printf ("%c \n", *p);

	return 0;
}
#endif

#if 0
int main(void)
{
	int n = 512;
	
	char *p = (char *)&n;

//	p += 4;

	printf ("%d", ++*p);

	
	return 0;
}
#endif


#if 0
int main (void)
{

	char buf1[20] = {'g', 'l', 'o', 'b', 'a', 'l'};

	buf1[4] = 'm';
	printf ("%s \n", buf1);

	char buf2[20] = "global";
	buf2[4] = 'm';

	printf ("%s \n", buf2);

	char *ch = "global";
	ch[4] = 'm';
	printf ("%s \n", ch);

	return 0;
}
#endif


#if 0
char *cstr = 'UBIQUITOUS';
char *str;
char *dstr;

int main(void)
{
char *cstr1 = "UBIQUITOUS";

	str = malloc (10);
	printf ("0x%08x \n", str);
	str = "Gamut";
	printf ("0x%08x \n", str);

	printf ("0x%08x \n", cstr1);
	printf ("0x%08x \n", cstr);

	printf ("0x%08x \n", cstr);
	printf ("0x%08x \n", str);
	
	dstr = malloc (10);
	printf ("0x%08x \n", dstr);
	strcpy (dstr, "OBLATION");
	printf ("0x%08x \n", dstr);

	free (str);
	free (dstr);

	return 0;
}

#endif	


#if 0

int main(void)
{

	int a;
 	int b;

	int *ptr[2];
	
	ptr[0] = &a;
	ptr[1] = &b;


	return 0;
}
#endif


#if 0

int main (void)
{

	int i;
	int num;

	int *aint[10];

	printf ("address of aint is \n");
	for (i = 0; i<10; i++)
		printf ("%p \n", (aint+i));

	printf ("\n");

	for (i = 0; i<10; i++){
		aint[i] = (int *)malloc(10 * sizeof(int));
		}	
	printf ("\n");

	printf ("enter the array \n");
	for (i = 0; i<10; i++){
		scanf ("%d", &num);
		*(aint+i) = num;
	}

	for (i = 0; i<10; i++)
		printf ("aint[%d] = %d \n", i, *(aint+i));

	return 0;	


}
#endif

#if 0
#include <stdio.h>

char *p = "Hello";

int main (void)
{
	char *p1 = "hello";
	char *s = p1;

//	s[0] = 45; /segmentation fault , Access illegal 


	return 0;
}
#endif


#if 0

const char ch = 'A';//without const data can be modified using pointer

int main (void)
{
	const char c = 66;/*without const here also we can modify the data 
															using pointer*/

	
	char *s = &c;

	char *n = &ch;

	s[0] = 72;

	n[0] = 100;

	printf ("%d \n", ch);
	printf ("%d \n", c);

	return 0;
}

#endif


#if 0
int main (void)
{
	int *p = (int *)malloc(5 * sizeof(int));
	int i;

	for (i = 0; i < 5; i++)
		printf ("%d ", p[i]);

	printf ("\n");	

	for (i = 0; i < 5; i++)
		p[i] = i + 20;

	for (i = 0; i < 5; i++)
		printf ("%d ", *(p+i));
		
	printf ("\n");	


	return 0;
}
#endif
#if 0

int main (void)
{

	int i;
	int j;

	char str[10][15];
	char *aint[10];

	printf ("address of aint is \n");
	for (i = 0; i < 10; i++)
		printf ("%p \n", (aint+i));

	printf ("\n");
	
	for (i = 0; i < 10; i++){
		aint[i] = (char *)malloc(10 * 15);
		}	
	printf ("\n");


	printf ("enter the string\n");
	for (i = 0; i < 10; i++){
		for(j = 0; j < 15; j++)
			scanf ("%s", str[i][j]);
	
		aint[i] = str[i];
	}

	for (i = 0; i < 10; i++)
		printf ("string %d  = %s \n", i, aint[i]);

	return 0;	


}
#endif

#if 0

char a[4][6] = {"head", "art", "sharp", "drive"};
char *b[4] = {"head", "art", "sharp", "drive"};

int main(void)
{
	int i;
	printf ("sizeof \n");
	
	for (i = 0; i < 4; i++)
	printf ("a[%d] = %d, b[%d] = %d \n", i, sizeof(a[i]), i, sizeof(b[i]));

	printf ("strlen \n");
	
	for (i = 0; i < 4; i++)
	printf ("a[%d] = %d, b[%d] = %d \n", i, strlen(a[i]), i, strlen(b[i]));
	


	printf("address \n");
	for (i = 0; i < 4; i++)
	printf ("a[%d] = 0x%08x, b[%d] = 0x%08x \n", i, a[i], i, b[i]);
	
	return 0;

}
#endif
	
#if 0

int main (void)
{
	char hw[20][20] = {"Hellow world"};

//	int b[][2];//compiler throughs an error

//	printf ("%d", sizeof(b));

	return 0;
}
#endif

#if 0

char str2[2][6] = {"Hello world"};
char str3[2][20] = {"Global", "Edge"};
char str4[][10] = {"Hyper Active"};
char str5[][20] = {"idiosyncracy", "vagabond"};

int main(void)
{
	int j;
	char (*p)[20] = str5;
	
//	for (j = 0; j < 6; j++)
//	printf ("%c", p[0][j]);
	p++;
	for (j = 0; j < 20; j++)
	printf ("%c", (*p)[j]);

	return 0;
}
#endif

#if 0
int main(void)
{

	int a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	int (*p)[3][3];

	p = &a;

	printf ("%d \n", (*p)[0][1]);
	printf ("%d \n", *(a[2] + 2));
	printf ("%d \n", (*p)[2][2]);

	printf ("address of a = %p \n", a);
	printf ("address of &a = %p \n", &a);
	printf ("address of *a = %p \n", *a);

	printf ("address of a + 1 = %p \n", a + 1);
	printf ("address of &a + 1 = %p \n", &a + 1);
	printf ("address of *a + 1 = %p \n", *a + 1);

	printf ("address of p = %p \n", p);
	printf ("address of p + 1 = %p \n", p + 1);

	return 0;
}
#endif

#if 0
int main(void)
{
	char s[100];


	printf ("%d \n", sizeof(s));
	char *p = s;
	
	printf ("%p \n",s);
	p++;
	printf ("%p \n", p);

	return 0;
}
#endif


