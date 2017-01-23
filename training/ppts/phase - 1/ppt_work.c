#include <stdio.h>
#include <stdlib.h>
#define LEN 500
#include <string.h>
#if 0
int main (void)
{
	char *ptr1 = "hello";
	char *ptr2 = "hello";

	if (ptr1 == ptr2)
		printf ("true \n");
	else
		printf ("false \n");

	return 0;
}
#endif

#if 0
int main (void)
{
	char *p = NULL;
	while (1){
		p = (char *)malloc (LEN * 4);
		printf ("p = %u \n", (unsigned)p);
		}	

	return 0;
}
#endif
#if 0
int main (void)
{
	int a = 320;
	char *ptr = (char *)&a;
	printf ("%d \n", *ptr);

	return 0;
}
#endif
#if 0
int main (void)
{
	int a = 320;
	int b = &a;
		
	printf ("&a = %d \t value of b = %d \n", &a, b);

	return 0;
}
#endif
#if 0
int main (void)
{
//	int a[];	//error - size is missing

	int a[] = {1, 2, 3,};

	printf ("%d \n", sizeof (a));	

	return 0;
}
#endif
#if 0
int main (void)
{
	char *ptr1 = NULL;
	char *ptr2 = 0;

	ptr1 = "c";
	ptr2 = "questions";

//	strcpy(ptr1, "c");
//	strcpy(ptr2, "questions");
	
	printf ("%s\n%s\n",ptr1, ptr2);
	
	return 0;
}
#endif
#if 0
int main (void)
{
	int *p = 10;

	printf ("value of(x) p = 0x%x \n", p);	
	printf ("value of(02x) p = 0x%02x \n", p);	
	printf ("value of(04x) p = 0x%04x \n", p);	
	printf ("value of(08x) p = 0x%08x \n", p);	
	printf ("value of(16x) p = 0x%16x \n", p);	
	printf ("value of(0fx) p = 0x%0fx \n", p);	
	printf ("value of p = %u \n", (unsigned)p);	
	
	p++;

	printf ("value of p = 0x%08x\n", p);	
	
	return 0;
}
#endif
#if 0
int main (void)
{
	char arr[10];
//	arr = "string";	//error - because arr is address of arr[0]

//	arr[10] = "string";//warning -> core dumped output
	
//	arr[10] = {"string"};//warning -> core dumped output  

	char ar[10] = {'s', 't', 'r', 'i', 'n', 'g'};
	
	printf ("%s \n",arr);
	printf ("%s \n",ar);

	return 0;
}
#endif
#if 0
int main (void)
{
	char *arr[4] = {"global", "edge", "software", "limited"};

	printf ("arr[1] = %s \n", *(arr + 1));
	printf ("arr = %c \n", **(arr));
	printf ("arr = %c \n", *(*(arr + 1) + 1));
	printf ("arr = %c \n", **(arr + 2));
	printf ("arr = %c \n", **(arr + 3));
	printf ("arr[1] = %u \n", (arr + 1));
	printf ("arr = %u \n", ((arr + 1) + 1));

	return 0;
}
#endif
#if 0
int main (void)
{
	int a = 10;
	int b = 20;

	int *p = &a;
	int *q = &b;

	printf ("&a = %u \n", (unsigned)&a);
	printf ("&b = %u \n", (unsigned)&b);

	printf ("p-q =0x%08x\n", q-p);
//	printf ("p+q =0x%08x\n", p+q);
//	printf ("p/q =0x%08x\n", p/q);

	return 0;
}
#endif
#if 0
int main (void)
{
	int i = 5;
	int *p = NULL;
	p = &i;
	printf ("&i = 0x%08x \n \n", (unsigned)&i);
	printf ("*&p = 0x%08x \n &*p = 0x%08x \n", *&p, &*p);
	
	return 0;
}
#endif
#if 0
int main (void)
{
	char *mess[] = {"monday", "tuesday", "wednesday","thursday"};
	
	printf ("sizeof(mess): %d \tsizeof(mess[1]): %d \n", 
											sizeof(mess), sizeof(mess[1]));	

	return 0;
}
#endif
#if 0
int main (void)
{
	int arr[] = {0, 1, 2, 3, 4};
	int *p;
	for (p = arr + 4; p >= arr; p--){
			printf ("%d \n", arr[p - arr]);
	}	

	return 0;
}
#endif
#if 0
int main (void)
{
	int arr[] = {0, 1, 2, 3, 4};
	int *p;
	int i = 0;
	for (p = arr; (p + i) <= (arr + 4); p++, i++){
			printf ("%d \n", *(p + i));
	}	

	return 0;
}
#endif
#if 0
void fun(int i, int *j)
{
	i = i * i;
	*j = *j * *j;
}
int main (void)
{
	int i = -5, j = -2;
	fun(i, &j);
	printf ("i= %d \n,j = %d \n", i, j);
	
	return 0;
}
#endif
#if 0
int main (void)
{
	static int a[] = {0, 1, 2, 3, 4};
	static int *p[] = {a, a + 1, a + 2, a + 3, a+ 4};
	int **ptr = p;
	printf ("a = 0x%08x, *a = %d \n", a, *a);
	printf ("p = 0x%08x, *p = 0x%08x, **p =%d \n", p, *p, **p);
	printf ("ptr = 0x%08x, *ptr = 0x%08x \n **ptr = %d \n", ptr, *ptr, **ptr);
	
	return 0;
}
#endif
#if 0
int main(void)                                                                  
{                                                                               
    int arr[5] = {37, 28, 61, 12, 100, 42, 12, 45};                             
    int i;                                                                      
                                                                                
    for (i = 0; i <10; i++){                                                    
        printf ("%d \n", arr[i]);                                               
    }                                                                           
                                                                                
    return 0;                                                                   
}
#endif
#if 0
int main(void)                                                                  
{                                                                               
	int arr[] = {1, 2, 3, 4, 5};	//initialization of array

	int *p = arr;    				//pointer to array element

	int (*ptr)[5] = &arr;					//pointer to an array

	int *a[] = {arr, arr + 1, arr + 2, arr + 3, arr + 4};//array of pointers                
	
	printf ("arr = %p, p = %p, ptr = %p,a[0] = %p \n", arr, p, ptr, a[0]);
	printf ("*a[0] = %d \n", *a[0]);	
	p++;
	ptr++;

	printf ("arr + 1 = %p, p = %p, ptr = %p,a[1] = %p \n", arr + 1, p, ptr, a[1]);
                                                            
    return 0;                                                                   
}
#endif
#if 0
int main(void)                                                                  
{                                                                               
    int a = 3;
	float b =3.4;
	void *vp;
	
	vp = &a;

	printf ("value of a = %d \n", *(int *)vp);

	*(int *)vp = 12;

	printf ("value of a = %d \n", *(int *)vp);
	
	vp = &b;	
                                                       
	printf ("value of b = %f \n", *(float *)vp);

    return 0;                                                                   
}
#endif
#if 0
int main(void)                                                                  
{                              
	char ch[] = "A";
                                                 
	printf ("%ld % ld\n", sizeof ("A"), sizeof(ch));

    return 0;                                                                   
}
#endif
#if 0
int main(void)                                                                  
{                              
	int *p = 10;
	printf ("%u \n", (unsigned)p);

	return 0;                                                              
}
#endif
#if 1
int main(void)                                                                  
{                                                                               
    int a = 3;                                                                  
    float b =3.4;                                                               
    void *vp;                                                                                  
    vp = &a;                                                                                                      
    printf ("value of a = %d \n", *(int *)vp);                                         
    *(int *)vp = 12;                                                           
    printf ("value of a = %d \n", *(int *)vp);                                  
	printf ("value of a = %d \n", (int *)*vp);  
    vp = &b;                                                               
    printf ("value of b = %f \n", *(float *)vp);                                         
    return 0;                                                                   
}
#endif
