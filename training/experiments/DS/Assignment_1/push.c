#include <stdio.h>
#define MAX 5
extern int arr[MAX];
extern int top;

void my_push(int n)                                                                
{                                                                               
    if( top == (MAX - 1) ){                                                     
        printf ("stack is full \n");                                            
    }else{                                                                      
        top++;                                                                  
        arr[top] = n;                                                           
    }                                                                           
}  
