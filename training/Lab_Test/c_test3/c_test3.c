#include <stdio.h>
#include <stdlib.h>
#define MAX 80

char buf[MAX];		//used to store the data from file 

int main (void)
{

	FILE *fp1;			//used to point file descriptors in files
	char *s = NULL;
		
	unsigned int count = 0;

	int j;			//used in loops

	s = (char *)malloc(sizeof(char) * MAX);

	if ( NULL == (fp1 = fopen ("file.txt","r"))){
        printf ("cannot open the text file \n");
        exit (1);
    }

	printf ("enter the string : \n");

    if (NULL == (fgets(s, MAX, stdin))){                                    
           perror ("fgets failed.. \n");                                       
            exit (1);                                                          
    }                                                                          
                                                                                
    for (j = 0; s[j] != '\0'; j++);

                                                                                
    if ((j > 0) && (s[j -1] == '\n')){		/*making last character as'\0' */
            s[j - 1] = '\0';
     }

	while (fscanf (fp1, "%s", buf) != EOF){ //getting a word at a time
			for (j = 0; s[j] != '\0'; j++){
					if (buf[j] == s[j]){
						continue;
					}else{
						break;
					}
			}
			if ((s[j] == '\0') && (buf[j] == '\0')){	
				count++;
			}
	}

	printf ("No. of occurances of word : %d \n", count);
	
	return 0;
}


							
			
			




			
