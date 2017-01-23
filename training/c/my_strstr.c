#include <stdio.h>
#include <stdlib.h>
#define MAX 256
extern int my_strlen (char *);  
char* my_strstr(char *, char *);                                               

char *sbuf = NULL;
char *dbuf = NULL;

int main (void)
{

	int len1, len2;
	char *p = NULL;

	if (NULL == (sbuf = (char *) malloc (sizeof(char) * MAX))){         
		perror ("malloc for sbuf is failed.. \n");                              
		exit (1);                                                   
    }                                                                  

	if (NULL == (dbuf = (char *) malloc (sizeof(char) * MAX))){         
		perror ("malloc for dbuf is failed.. \n");                              
		exit (1);                                                   
    }

    printf ("enter sbufer : \t");
	 if (NULL == (fgets(sbuf, MAX, stdin))){                                      
			 perror ("fgets failed.. \n");                                           
			 exit (1);                                                               
	 }                                                                           
					
	 len1 = my_strlen(sbuf);      

	 if ((len1 > 0) && (sbuf[len1 -1] == '\n')){
			sbuf[len1 - 1] = '\0';
	 }
	

	 printf ("enter the dbuffer string : \t");
	 
	 if (NULL == (fgets(dbuf, MAX, stdin))){                                      
		 perror ("fgets failed.. \n");                                           
		 exit (1);                                                               
	 }                                                                           
									   
	 len2 = my_strlen(dbuf);      

	 if ((len2 > 0) && (dbuf[len2 -1] == '\n')){
			dbuf[len2 - 1] = '\0';
	 }

	p = my_strstr (sbuf, dbuf);

	if (NULL != p)
	printf ("%s \n", p);
	else
	printf ("no substring \n");

	return 0;
}



char* my_strstr(char *p, char *q)                                               
{                  
	int i;
	int j;

	                                                             
    for(i = 0; p[i]; i++){                                                      
        if (p[i] == q[0]){                                                      
                                                                                
            for (j = 1; q[j]; j++){                                             
                if(p[i + j] == q[j])                                            
                    continue;                                                   
                else                                                            
                    break;                                                      
            }                                                                   
			if (q[j] == '\0')                                                           
				return p+i;                                                             
        }                                                                       
    }      
                                                                     
    return 0;
}                                                                               
  
