#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
int main(void)
{
	printf("hellow world \n");
	return 0;
}
*/


# if 0
//experiment 4: to count trailing 0's (bitwise Q.14)
void cnt_end_0(int);
int main()
{
int num;
printf("enter number: \n");
scanf("%d",&num);
cnt_end_0(num);
}

void cnt_end_0(int num)
{
int c=0;
while((num&1) == 0)
{
c++;
num=num>>1;
}
printf("count= %d\n",c);
}
#endif

# if 0
int main(void)
{
	int arr[4] = {1, 2};
	int i;
	for (i = 0; i<10; i++)
		printf ("%d \n", arr[i]);		

	return 0;
}
#endif
# if 0
void fun(){ }
int main(void)
{
	fun();
//	fun(10, "GfG", "GQ");

	return 0;
}
#endif

# if 0
int main()
{
	static int i = 5;
    if (--i){
        printf("%d ", i);
        main(10);
    }

	return 0;
}
#endif
# if 0
/*int fun(int a, int b)
{
	return a#;
	#b;	
}*/
#define merge(a, b) a##b
#define add(a, b) a + b
int main(void)
{
	int a = 10;
	int b = 20;
	
//	int c = fun(a,b);
	int d = add(a, b);
 
	int c = merge(10, 20);
	
	printf ("%d \n", c);
	printf ("%d \n", d);

	return 0;
}
#endif
# if 0
int fun()
{
	{
	int a = 1, b = 2, c = 3; //= 1, 2, 3;
	printf ("%d \n %d \n%d \n", a, b, c);
	return 0;
}

}


int main(void)
{

{
	int a = 1, b = 2, c = 3; //= 1, 2, 3;
//	a, b, c = 1, 2, 3;

	printf ("%d \n %d \n%d \n", a, b, c);
	fun();

	return 0;
}

}
#endif
# if 0
void int(){}

int main(void)
{

	int();
	return 0;
}
#endif
# if 0
int main(void)
{
	struct int1{
		int int1[888888];	
		char ch;
	}a;

	a.int1[0] = 10;

	printf ("%d , %c \n",  a. int1[0],  a. ch);	

	return 0;
}
#endif
# if 0
int a = 10;
//int a = 20;
int main(void)
{
	int b = 30;
//	int b;

	return 0;
}
#endif

# if 0
int main(void)

{
		int i;

        int arr[10] = {6, 5, 3, 8, 10, 2, 4, 7, 9, 1};

        int big = arr[0];

        for(i = 0; i < 10; i++) {    

              if(arr[i] > big);

                     big = arr[i];

       }

       printf("%d\n", big);

       return 0;
}
#endif


# if 0
int main (void)
{
    int a = 2;
    int x = 10;
    if(a == 2){
            if (x == 8)
             printf("a is 2 and x is 8\n");
			}		
    else              
         printf("a is not 2\n");

    return 0;
} 
#endif

# if 0
int main(void)
{
    int i = 2;
    int j = 1;
    int opt = 2;
    switch(opt) {
        case 1: for(i = 0; i < 4; i++){
                    for(j = 0; j < 3; j++){
        case 2: j++;
                }
                printf("%d %d\n", i, j);
                if (i == 3)
                    break;
                }
    }
    return 0;
} 

#endif
#if 0

int main ()
{
	int a = 32;
	int b = 100;

	int *p = &a;
//	int v = &a;
	printf ("&A= %p, &B =%p\n", &a,&b);	
	printf("addr p : %p\n", &p);
	printf("p =%p\n", p);
//	printf("*++p : %x\n", *++p);
	printf("*p++ --- %d\n", *p++);
	printf("addr p : %p\n", &p);
	printf("p --- %p\n", p);
	printf("*p --- %x\n", *p);
	printf("a --- %d\n", a);
//	printf("*++p ----- %p\t%u\t%x\n", a, a, a);
//	printf("++*p ----- %p\t%d\n", p, ++*p);
//	printf("*p++ ----- %d\t%p\t%d\n", *p, p, *p++);
//	printf("*p++ ----- %p\t%p\t%d\t%p\n", (*p)++,  p, *p, p++);
//	*p++;
//	printf("%d\n", *p);
//	printf("*(p++) --- %d\t%p\n", *(p++), p);
//	printf("(*p)++ --- %d\t%d\n", (*p)++, *p);
//	printf("a++ --- %d\t%d\n", a++, a);
//	printf("&a --- %u\t%u\n", (v)++, v);
//	printf("(*p)++ --- %d\t%d\n", a++, a);
	return 0;
}
#endif

#if 0
int main()
{
	int $ = 1;

	printf ("%d\n", $);
	return 0;
}
#endif
#if 0
int main()
{
	int *p = NULL;
	int *q = NULL;
	int  i;
	p = (int *)malloc (4*4);

	for(i = 0; i < 4; i++){
	scanf("%d",(p + i));
	}
	
	printf ("print increment\n");
	for(i = 0; i < 10; i++){
	printf("%d\n",*(p + i));
	}
/*	printf ("print decrement\n");
	for(i = 0; i < 10; i++){
	printf("%d\n",*(p - i));
	}*/
	free(p);
	p = NULL;
	p = (int *)malloc (4*4);
	printf ("after free\n");
	for(i = 0; i < 10; i++){
	printf("%d\n",*(p + i));
	}

	return 0;
}
#endif
#if 0
int main()
{
	printf ("Kowshik");
	printf ("Busetty");

	while(1){
		printf ("At the edge");	
	}

	return 0;
}
#endif
#if 0
int main()
{
//	printf ("PID= %d \n",getpid());
//	getchar();
	int a = 110;
	int b = 20; 


	return 0;
}
#endif
#if 0
int main()
{
	float a = 10.7;
	int i;

	int *f = &a;

	for(i = 31; i >= 0; i--)
		printf("%d ", (*f >> i) & 1);
	
	printf("\n");

	if(a == 10.7)
		printf("true \n");
	else
		printf("false \n");

	return 0;
}
#endif
#if 1
int main(void)
{
    char *c[] = { "ENTNG", "NST", "AMAZI", "FIRBE" };
    char **cp[] = { c+3, c+2, c+1, c };
    char ***cpp = cp;

    printf ( "%s", **++cpp );
    printf ( "%s", *((*++cpp)-1)+3 );
    printf ( "%s",  *cpp[-2]+3 );
    printf ( "%s",  cpp[-1][-1]+1 );

    return 0;

} 
#endif
#if 0
int main(void)
{
//	int a[1.5];
	int a;

//	printf("%d\n", sizeof(a));
	if(-1 == (a = printf('\0'))){
		perror("printf() failed \n");
	}

    return 0;

} 
#endif
