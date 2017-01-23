#include <stdio.h>                                                              
#include <stdlib.h>
#include <string.h>          
                                         
#if 0                                                                    
//experiment 1 : what are the strings we are passing as arguments                 

// $: ./a.out * - displays no. of files in the folder

int main (int argc, char *argv[])                                               
{                                                                               
    printf ("no.of arguments : %d \n", argc);      
   
    return 0;                                                                   
}                                                                               
#endif

     
#if 1                                                                           
/*experiment 2 : to count number of C files in a folder by reading the files 
					from the command line*/

// $: ./a.out *.c    -> displays the c files 

int main (int argc, char *argv[])                                               
{       

	int j;
	unsigned int cnt = 0;
                                                                        
    printf ("no.of arguments : %d \n", argc);                                   
	argc = argc - 1;
	
	while (argc){
			
		for (j = 0; argv[argc][j] != 0; j++){
        	                  
        if( (*(*(argv + argc) + j) == '.')
									 && (*(*(argv + argc) + j + 1) == 'c')){
					cnt++;
			}
			                                                                    
     	}
		argc--;                             
	}        

	printf ("no. of c files = %d \n", cnt);                                      
    return 0;                                                                   
}                                                                               
#endif    

#if 0
//experiment 3 : simple calculator implementation using command line arguements
int my_atoi (char *p)                                                           
{                                                                               
    int i;                                                                      
    int sum = 0;                                                                
    for (i = 0; p[i]; i++)                                                      
    sum = sum * 10 + p[i] - 48;                                                 
                                                                                
    return sum;                                                                 
}

int add (int a, int b) { return (a + b); }

int sub (int a, int b) { return (a - b); }

int mul (int a, int b) { return (a * b); }

int divi (int a, int b)
{
	if ( b == 0 )
		printf ("division cannot be performed \n");
	else
		return (a / b);
}

int (*func_ptr) (int, int);

int main(int argc, unsigned char *argv[])
{

	int value;

	if ( argc != 4 ){
		printf("pass correct no. of arguements \n");

	}else{
	
/*		printf ("%s \n", *(argv + 1));	
		printf ("%p \n", (argv + 1));
		printf ("%p \n", &argv[1]);
		printf ("%s \n", argv[1]);		
		printf ("%c \n", *(*(argv + 1)+0));
*/
		if ( !strcmp(argv[1],"add") )
			func_ptr = add;
		else if ( !strcmp(argv[1],"sub") )
			func_ptr = sub;
		else if ( !strcmp(argv[1],"mul") )
			func_ptr = mul;
		else if ( !strcmp(argv[1],"div") )
			func_ptr = divi;

		value = func_ptr (my_atoi((char *)argv[2]), my_atoi((char *)argv[3]));

		printf ("%d \n", value);	

	}


	return 0;
} 
#endif
