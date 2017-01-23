#include <stdio.h>
extern int top;

void my_pop(void)                                                                  
{                                                                               
    if( top == -1 ){                                                            
        printf ("No pop operation can perform - stack is empty \n");            
    }else {                                                                     
        top--;                                                                  
    }                                                                           
} 
