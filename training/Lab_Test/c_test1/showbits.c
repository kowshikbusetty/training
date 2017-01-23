#include <stdio.h>

void showbits (int num)                                                         
{                                                                               
    int i;                                                                      
    for (i = (sizeof(int) * 8 - 1); i >= 0; i--)                                       
        printf ("%d", (num >> i) & 1);                                                                                  
                                                                                
    printf ("\n");                                                              
}      
