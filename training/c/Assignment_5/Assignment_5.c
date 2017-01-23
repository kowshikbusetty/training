/*Assignment 5*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 80	//used for declaring the array size

extern char *case_conversion (char *);//to convert upper to lower case alphabets
extern int my_strlen (char *);			//tells the string length
extern char* my_strstr(char *, char *);	//search for sub-string

FILE *fp1, *fp2;	//used to point file descriptors in files
char buf[MAX];		//used to store the data from file 

int i, j;			//used in loops

struct EH {
	unsigned char e_ident[16];
	short e_type;
	short e_machine;
	int e_version;
	unsigned int e_entry;
};

struct EH arr[10];

//experiment 1 : change all upper case to lower case in a given text file
int case_convert_file(void)
{
                                                                                
    char *buf2 = NULL;
                                                                                
    if ( NULL == (fp1 = fopen ("file.txt","r+")) ){
            printf ("cannot open the text file \n");
            exit (1);
        }
                                                                                
                                                                                
    if ( NULL == (fp2 = fopen ("file.txt","r+")) ){
            printf ("cannot open the text file \n");
            exit (1); 
        }
                                                                                
                                                                                
    while ( fgets(buf, MAX, fp1) != NULL){
							//accessing a line from file & storing into buffer                                                     

            buf2 = case_conversion (buf);//converts Upper to lower case characters
                                                                                
                fputs (buf2, fp2);//inserting the string into file
    }
                                                                                
	fclose(fp1);
	fclose(fp2);

    return 0;         
}                 

/*experiment 2 : to search for a given string in a file and 
											print the line with line number*/
int search_string (void)                                                                 
{
	int flag = 0;
    int line = 1;
    char sbuf[MAX];
	int len1;
                                                                                
    if ( NULL == (fp1 = fopen ("file.txt","r")) ){
            printf ("cannot open the text file \n");
            exit (1);
    }                                                                           
                                                                                
    printf ("enter the sub-string : \t");                                       
                                                                                
	getchar();                                                     
    if (NULL == (fgets(sbuf, MAX, stdin))){	//accessing the string to be searched                                    
           perror ("fgets failed.. \n");                                       
            exit (1);                                                          
    }                                                                          
                                                                                
    len1 = my_strlen(sbuf);	//finding length of sub-string
                                                                                
    if ((len1 > 0) && (sbuf[len1 -1] == '\n')){	//replacing the  ending newline character with null
            sbuf[len1 - 1] = '\0';
        }
                                               
    while ( fgets(buf, MAX, fp1) != NULL ){
                                                                                
            if ( my_strstr(buf, sbuf) ){//returns address of substring in main string
                printf ("line no. is : %d : %s \n", line, buf);
				flag = 1;
                break;                                                                    
            }
            line++;                                                                         
    }
                                                                                
    if ( 0 == flag)
        printf ("substring not found... \n");
                                                                                
	fclose(fp1);
    return 0;
}

//experiment 3: remove comments from a file
int removecomments(void)
{
	int flag = 0;
                                                                             
    if ( NULL == (fp1 = fopen ("comment.txt","r"))){//opening the file having comments
        printf ("cannot open the text file \n");
        exit (1);
    }
                                                                             
    if ( NULL == (fp2 = fopen ("file.i","w"))){//storing the data after removing comments
        printf ("cannot open the text file \n");
        exit (1);
    }

	if(fp1 == 0)//checking whether the file is empty or not
	{
		printf("file is empty\n");
		return 0;
	}

	while((fgets(buf, MAX, fp1)) != NULL){//accessing a line at a time from file upto EOF

		if( (buf[0] == '/') && (buf[1] == '*') && (!my_strstr(buf, "*/")) ){
												 //removung comments in multilple lines
				while(fgets(buf, MAX, fp1) != NULL){

					if(my_strstr(buf, "*/")){
						flag = 1;
						break;
					}else{
						continue;
					}
				}
			
			if (flag == 0){						//checking whether the comments are terminated or not
				printf ("unterminated comments \n");
				remove("file.i");				//if unterminated , deleting the file
				break;
			}else{
				continue;
			}

		}else if( my_strstr(buf, "//") || my_strstr(buf, "/*") ){//finding for comments in present in a line

				for(i = 0; buf[i]; i++){		//traversing in the line 

					if( (buf[i] == '"') ){		//not to remove comments between quotations 
						fputc(buf[i], fp2);
						i++;
						while (buf[i] != '"'){
							fputc(buf[i], fp2);
							i++;
						}
						fputc(buf[i], fp2);
						continue;
					}	
					if( (buf[i] == '<') ){		//not to remove comments between quotations
						fputc(buf[i], fp2);
						i++;
						while (buf[i] != '>'){
							fputc(buf[i], fp2);
							i++;
						}
						fputc(buf[i], fp2);
						continue;
					}							//not to remove comments between quotations
			
					if( (buf[i] == '/') && (buf[i + 1] == '/') ){
						break;					//comments in line

					}else if( (buf[i] == '/') && (buf[i + 1] == '*') ){
												//terminated comment in a line
							for(j = i + 2; (buf[j] != '*') 
											&& (buf[j + 1] != '/'); j++);

							i = j + 1;

							continue;
					}else
						fputc(buf[i], fp2);
				}
						
		}else
			fputs(buf, fp2);				//if no comments present in line - copying the line into file
	}

	fclose(fp1);
	fclose(fp2);

	return 0;
}

//experiment 4: count no. of words in a files
int cnt_words(void)
{
	unsigned int count = 0;
	char ch;

	if ( NULL == (fp1 = fopen ("file.txt","r"))){
		printf ("cannot open the text file \n");
		exit (1);
	}
 
/*	while ( fscanf(fp1, "%s", buf ) != EOF){
		count++;
	}
*/
	while ( (ch = fgetc(fp1)) != EOF ){
		if ( (ch == ' ') || (ch == '\t') || (ch == '\n') ){			//not to count wide spaces
			while((ch = fgetc(fp1)) == ' ' || ch == '\t' || ch == '\n' ){
					continue;
			}
		count++;
		}
	}

	printf("No. of words in a file = %d\n",count);
	fclose(fp1);

	return 0;
}

//experiment 5 : to create a array of 10 elements of structure
int write_structarray(void)
{
	if ( NULL == (fp1 = fopen ("info.db","w"))){	//opening the file to store the structure data
		printf ("cannot open the text file \n");
		exit (1);
	}
 
	printf ("enter the members.... : \n");

	for (i = 0; i <= 2; i++){
		printf ("enter the element %d details : \n", i + 1);
		printf ("enter e_ident \n");
		scanf ("%s", (arr[i].e_ident));
		printf ("enter e_type & e_machine \n");
		scanf ("%hi%hi", &(arr[i].e_type), &(arr[i].e_machine));
		printf ("enter e_version & e_entry \n");
		scanf ("%d%u", &(arr[i].e_version), &(arr[i].e_entry));

		fwrite (&arr[i], sizeof(arr[i]), 1, fp1);
	}	
	fclose(fp1);

	return 0;
}

/*experiment 6 :to read info.db which contains the information written in the
				experiment 5 and print the content of the file */

int read_structarray (void)
{
	fp2 = fopen ("info.db", "r");
	
	while (1 == fread(&arr[i], sizeof(arr[i]), 1, fp2)){
			
			printf ("Name of employee : %s \n", arr[i].e_ident);
			printf ("e_type : %hi \n", arr[i].e_type);
			printf ("e_machine : %hi \n", arr[i].e_machine);
			printf ("e_version : %d \n", arr[i].e_version);
			printf ("e_entry : %u \n", arr[i].e_entry);

	}

	fclose(fp2);
	return 0;
}
	
int main (void)
{
	unsigned int choice;

	printf ("1.change all upper case to lower case in a given text file \n");
	printf ("2.to search the string in a file \n");
	printf ("3.to remove comments from a file \n");
	printf ("4.count no. of words in a textfile \n");	
	printf ("5.to create an structure array of 10 elements \n");
	printf ("6.to read the contents of experiment 5 & printing the contents \n");
	printf ("\n");                                                          

	do {

		printf ("\nEnter the choice to select the progrm & 0 for exit : \t");		
		scanf ("%d", &choice);

		switch ( choice ){		//to select the program

		case 0 : break;			//to come out of the program

		case 1 :
				case_convert_file();	//to convert Upper to lower case alphabets
				break;

		case 2 :
				search_string();		//to search string in a file
				break;

		case 3 :
				removecomments();		//remove comments from file
				break;

		case 4 : 
				cnt_words();			//count no. of words in a file
				break;
		
		case 5 : 
				write_structarray();	//to store structure array into file
				break;

		case 6: 
				read_structarray();	//to read and display the structure data from a file
				break;
		
		default : 
				printf ("enter correct option \n");
				break;
		}

	}while (choice != 0);   //untill use has to terminate by passing 0
	return 0;
}

