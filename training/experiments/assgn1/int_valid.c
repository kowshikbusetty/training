#include <stdio.h>                                                               
#include <string.h>          
#include <stdlib.h>                                                    
#define DEC 10    
#define MAX 256

int  int_valid(char *arr)
{
	int i = 0;
	int value = 0;
	int length;

	length = strlen(arr);

	while( arr[i] != '\0' ){
		
		if( (i == 0) && ((arr[i] == '+') || (arr[i] == '-')) ){                     
                i++;                                                            
        }
		
		if ( (arr[i] == '+') || (arr[i] == '-') ){
				break;	
		}

			else {                                              
              	if(( arr[i] == '.' ) && (arr[i + 1] == 1)){
					if ( arr[i + 1] == 1 ){
						return 0;
					}	
					break;
				} else {
						if(arr[i] <= '9' && arr[i] >= '0'){               
							value *= DEC;                                      
							value += arr[i] - '0';
							i++;
						 } else{
							  if (' ' == arr[i])
									break;
							break;
						 }
						
				}
	
		    }
	}

	if( i != length ) 
		return '$';
	 else 
		return value;

}		

int main(void)
{
	char *sbuf = NULL;
	int value;
	int len1;

	if (NULL ==(sbuf = (char *) malloc (sizeof(char) * MAX))){         
		perror ("malloc for sbuf is failed.. \n");                              
		exit (1);                                                   
    }            	
	
	printf ("enter the array : \t");

	do{

		 if (NULL == (fgets(sbuf, MAX, stdin))){                                      
				 perror ("fgets failed.. \n");                                           
				 exit (1);                                                               
   			 }   

		len1 = strlen(sbuf);      

		 if ((len1 > 0) && (sbuf[len1 -1] == '\n')){
				sbuf[len1 - 1] = '\0';
		 }
			

		value = int_valid(sbuf);

		if ( '$' != value )
			break;
		else
			printf("Invalid input..! Please enter valid input..! \n");

	}while( '$' == value );	

	printf ("int value is : %d \n", value);

	return 0;
}
