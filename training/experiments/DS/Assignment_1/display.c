#include <stdio.h>
#define MAX 5 
extern int arr[MAX];
extern int top;

void my_display(void)                                                              
{                                                                               
    int i;                                                                      
                                                                                
    if (-1 == top){                                                             
        printf ("stack is empty \n");                                           
    }else {                                                                     
                                                                                
        for (i = 0; i <= top; i++){                                             
            printf ("%d ", arr[i]);                                             
        }                                                                       
        printf ("\n");                                                          
    }                                                                           
}
