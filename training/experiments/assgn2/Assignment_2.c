#include <stdio.h>
#include <stdlib.h>
#include "my_header.h"
#define MAX 256

int len1;
int len2;
char *p = NULL;
int n;
int m;
int i;
int j;
int k;
char ch;
char temp[100];
unsigned int pos;

int main (void)
{
	char *sbuf = NULL;
	char *dbuf = NULL;

	char delim[MAX] = {'*', ' ', '/', '{', '}'}; 

	int choice;

	if (NULL ==(sbuf = (char *) malloc (sizeof(char) * MAX))){         
		perror ("malloc for sbuf is failed.. \n");                              
		exit (1);                                                   
    }                                                                  

	if (NULL ==(dbuf = (char *) malloc (sizeof(char) * MAX))){         
		perror ("malloc for dbuf is failed.. \n");                              
		exit (1);                                                   
    }
                                                                  
	printf ("Enter the choice of program: \n");
	
	printf ("1.strcpy 2.strncpy 3.first occurance of character in string \n");
	printf ("4.sappend 5.snappend 6.strcpm 7.strcasecmp \n");
	printf ("8. str_spn which returns initial charecters count \n");
	printf ("9.strtok 10.palindrome 11.reverse the string \n");
	printf ("12.sueze 13.strrot whether strings are rotated version or not \n");
	printf ("14.remove the substring 15.insert a character \n");

	scanf ("%d" ,&choice);

	switch (choice){	//to select the program

	case 1 : //experiment 1 : string copy 
			 printf ("enter the sbuffer string : \t");
 
			 getchar();           
                  
   			 if (NULL == (fgets(sbuf, MAX, stdin))){                                      
				 perror ("fgets failed.. \n");                                           
				 exit (1);                                                               
   			 }                                                                           
                                               
			 my_strcpy (dbuf, sbuf);

			 printf ("string after copying is : %s \n" ,dbuf);

			 break;

	case 2 : //experiment 2 : strncpy which copies n characters 
			 printf ("enter the sbuffer string : \t");
 
			 getchar();           
                  
   			 if (NULL == (fgets(sbuf, MAX, stdin))){                                      
				 perror ("fgets failed.. \n");                                           
				 exit (1);                                                               
   			 }                                                                           
                                               			
			 label1 : printf ("enter no. of characters : \t");
					 scanf ("%d", &n);
			 
			 if (n <= my_strlen(sbuf))
				 my_strncpy (dbuf, sbuf, n);
			 else{
				 printf ("n value is greater than string length of sbuf \n");
				 goto label1;
			 }
				
			 printf ("string after copying : %s \n" ,dbuf);
			 
			 break;


	case 3 : /*experiment 3 : It returns the first occurance of character
																 in a string */
			
//			 printf ("enter the character to search: \n");
//			 getc(ch);			

			 printf ("enter the sbuffer string : \n");
			 
			 getchar();           
                  
   			 if (NULL == (fgets(sbuf, MAX, stdin))){                                      
				 perror ("fgets failed.. \n");                                           
				 exit (1);                                                               
   			 }                                                                           
                                               
//			 getchar(ch);

			 ch = 'a';

			 p = char_add_instr (sbuf, ch);
			
			 if (p == NULL)
				printf("character not found \n");
			 else
				printf ("%s \n", p);

			 break;
			

	case 4 : /* experiment 4 : to append the dbuf string with s buffer string*/

			 printf ("enter the sbuffer string : \t");
			 
			 getchar();           
                  
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


			 p = sappend (dbuf,sbuf);

			 printf ("after appending : %s \n", p);


			 break;		

	case 5 : /* experiment 5 : to append the dbuf string with first n 
												characters of s buffer string*/ 
			 printf ("enter the sbuffer string : \t");
			 
			 getchar();           
                  
   			 if (NULL == (fgets(sbuf, MAX, stdin))){                                      
				 perror ("fgets for sbuf is failed.. \n");                                           
				 exit (1);                                                               
   			 }                                                                           
                                               
			 len1 = my_strlen(sbuf);      

			 if ((len1 > 0) && (sbuf[len1 -1] == '\n')){
					sbuf[len1 - 1] = '\0';
			 }
			
			 printf ("enter the dbuffer string : \t");
                  
   			 if (NULL == (fgets(dbuf, MAX, stdin))){                                      
				 perror ("fgets for dbuf is failed.. \n");                                           
				 exit (1);                                                               
   			 }                                                                           
                                               
			 len2 = my_strlen(dbuf);      

			 if ((len2 > 0) && (dbuf[len2 -1] == '\n')){
					dbuf[len2 - 1] = '\0';
			 }

			 label2 : printf ("enter no. of characters : \t");
					 scanf ("%d", &n);
			 
			 if (n <= my_strlen(sbuf))
			 	p = snappend (dbuf,sbuf,n);
			 else{
				 printf ("n value is greater than string length of sbuf \n");
				 goto label2;
			 }
				

			 printf ("after appending : %s \n", p);

			 break;		

	case 6 :/* function char strcmp (char *str1, char * str2) to compare 
													two stringsstr1 and str2*/

			 printf ("enter the sbuffer string : \t");
			 
			 getchar();           
                  
   			 if (NULL == (fgets(sbuf, MAX, stdin))){                                      
				 perror ("fgets for sbuf is failed.. \n");                                           
				 exit (1);                                                               
   			 }                                                                           
                                               
			 len1 = my_strlen(sbuf);      

			 if ((len1 > 0) && (sbuf[len1 -1] == '\n')){
					sbuf[len1 - 1] = '\0';
			 }
			

			 printf ("enter the dbuffer string : \t");

   			 if (NULL == (fgets(dbuf, MAX, stdin))){                                      
				 perror ("fgets for dbuf is failed.. \n");                                           
				 exit (1);                                                               
   			 }                                                                           
                                               
			 len2 = my_strlen(dbuf);      

			 if ((len2 > 0) && (dbuf[len2 -1] == '\n')){
					dbuf[len2 - 1] = '\0';
			 }

			 ch = my_strcmp (sbuf,dbuf);

			 if (ch == 0){
				printf ("two strings are equal \n");
			 }else if(ch == 1){
				printf ("%s : string is greater \n", sbuf);
			 }else 
				printf ("%s : string is greater \n", dbuf);

			 break;
	
	case 7 : /*function int strcasecmp(char *str1, char *str2) which compares 
			 two strings str1 and str2 by ignoring the case (lower or upper)*/

			 printf ("enter the sbuffer string : \t");
 
			 getchar();           
                  
   			 if (NULL == (fgets(sbuf, MAX, stdin))){                                      
				 perror ("fgets for sbuf is failed.. \n");                                           
				 exit (1);                                                               
   			 }                                                                           
                                               
			 len1 = my_strlen(sbuf);      

			 if ((len1 > 0) && (sbuf[len1 -1] == '\n')){
					sbuf[len1 - 1] = '\0';
			 }
			

			 printf ("enter the dbuffer string : \t");

   			 if (NULL == (fgets(dbuf, MAX, stdin))){                                      
				 perror ("fgets for dbuf is failed.. \n");                                           
				 exit (1);                                                               
   			 }                                                                           
                                               
			 len2 = my_strlen(dbuf);      

			 if ((len2 > 0) && (dbuf[len2 -1] == '\n')){
					dbuf[len2 - 1] = '\0';
			 }

			 ch = my_strcasecmp (sbuf,dbuf);

			 if (ch == 0){
				printf ("two strings are equal \n");
			 }else if(ch == 1){
				printf ("%s : string is greater \n", sbuf);
			 }else 
				printf ("%s : string is greater \n", dbuf);

			 break;

	case 8 : /*size_t strspn(const char *buf1, const char *buf2) to count 
			 the initial set of characters in buf1, which matches any of the
			 characters in buf2*/

			 printf ("enter the sbuffer string : \t");
 
			 getchar();           
                  
   			 if (NULL == (fgets(sbuf, MAX, stdin))){                                      
				 perror ("fgets for sbuf is failed.. \n");                                           
				 exit (1);                                                               
   			 }                                                                           
                                               
			 len1 = my_strlen(sbuf);      

			 if ((len1 > 0) && (sbuf[len1 -1] == '\n')){
					sbuf[len1 - 1] = '\0';
			 }
			

			 printf ("enter the dbuffer string : \t");

   			 if (NULL == (fgets(dbuf, MAX, stdin))){                                      
				 perror ("fgets for dbuf is failed.. \n");                                           
				 exit (1);                                                               
   			 }                                                                           
                                               
			 len2 = my_strlen(dbuf);      

			 if ((len2 > 0) && (dbuf[len2 -1] == '\n')){
					dbuf[len2 - 1] = '\0';
			 }

			 n = my_strspn(sbuf,dbuf);

			 printf ("Counting the characters in sbuffer \n");			 
			 printf ("No. of characters present : %d \n", n);
			
			 break;

	case 9 : /*A function char * strtok(const char *buf, const char *delim) 
			which parses buf until it encounters any of the delimiter in delim*/
		
			 
			 printf ("enter the buffer string : \t");
 
			 getchar();           
                  
   			 if (NULL == (fgets(sbuf, MAX, stdin))){                                      
				 perror ("fgets for sbuf is failed.. \n");                                           
				 exit (1);                                                               
   			 }                                                                           
                                               
			 len1 = my_strlen(sbuf);      

			 if ((len1 > 0) && (sbuf[len1 -1] == '\n')){
					sbuf[len1 - 1] = '\0';
			 }
			
			 p = my_strtok (sbuf, delim);
		
			 printf ("%s \n", p); 
			
			 break;	

	case 10 :// to check whether a string is pallindrome or not

			 printf ("enter the buffer string : \t");
 
			 getchar();           
                  
   			 if (NULL == (fgets(sbuf, MAX, stdin))){                                      
				 perror ("fgets for sbuf is failed.. \n");                                           
				 exit (1);                                                               
   			 }                                                                           
                                               
			 len1 = my_strlen(sbuf);      

			 if ((len1 > 0) && (sbuf[len1 -1] == '\n')){
					sbuf[len1 - 1] = '\0';
			 }
						
			 string_palindrome(sbuf);
			
			 break;
	
	case 11 : // Reverse a string
			 printf ("enter the buffer string : \t");
 
			 getchar();           
                  
   			 if (NULL == (fgets(sbuf, MAX, stdin))){                                      
				 perror ("fgets for sbuf is failed.. \n");                                           
				 exit (1);                                                               
   			 }                                                                           
                                               
			 len1 = my_strlen(sbuf);      

			 if ((len1 > 0) && (sbuf[len1 -1] == '\n')){
					sbuf[len1 - 1] = '\0';
			 }
									
			 p = my_reverse(sbuf);
			
			 printf ("%s \n", p);
			 
			 break;
			 
	case 12 ://To squeeze the consecutive similar characters in a given string
			 printf ("enter the buffer string : \t");
 
			 getchar();           
                  
   			 if (NULL == (fgets(sbuf, MAX, stdin))){                                      
				 perror ("fgets for sbuf is failed.. \n");                                           
				 exit (1);                                                               
   			 }                                                                           
                                               
			 len1 = my_strlen(sbuf);      

			 if ((len1 > 0) && (sbuf[len1 -1] == '\n')){
					sbuf[len1 - 1] = '\0';
			 }
														
			 p = my_squeze(sbuf);

			 printf ("%s \n", p);
			 
			 break;
			 
	case 13 : /*a function which checks the rstr and str are the rotated
			  versions or not */

			 printf ("enter the main string : \t");
 
			 getchar();           
                  
   			 if (NULL == (fgets(sbuf, MAX, stdin))){                                      
				 perror ("fgets for sbuf is failed.. \n");                                           
				 exit (1);                                                               
   			 }                                                                           
                                               
			 len1 = my_strlen(sbuf);      

			 if ((len1 > 0) && (sbuf[len1 -1] == '\n')){
					sbuf[len1 - 1] = '\0';
			 }
														
			 printf ("enter the sub-string to check  : \t");

   			 if (NULL == (fgets(dbuf, MAX, stdin))){                                      
				 perror ("fgets for dbuf is failed.. \n");                                           
				 exit (1);                                                               
   			 }                                                                           
                                               
			 len2 = my_strlen(dbuf);      

			 if ((len2 > 0) && (dbuf[len2 -1] == '\n')){
					dbuf[len2 - 1] = '\0';
			 }

			 m = my_strrot(sbuf, dbuf);

			 if (m == 1)
				printf ("rotated version \n");
			 else
				printf ("Not rotated version \n");

			 break;

	case 14 : /*A function  which checks for the substring sstr in str and 
				if found removes the substring sstr in string str*/
			 
			 printf ("enter the main string : \t");
 
			 getchar();           
                  
   			 if (NULL == (fgets(sbuf, MAX, stdin))){                                      
				 perror ("fgets for sbuf is failed.. \n");                                           
				 exit (1);                                                               
   			 }                                                                           
                                               
			 len1 = my_strlen(sbuf);      

			 if ((len1 > 0) && (sbuf[len1 -1] == '\n')){
					sbuf[len1 - 1] = '\0';
			 }
														

			 printf ("enter the sub-string : \t");

   			 if (NULL == (fgets(dbuf, MAX, stdin))){                                      
				 perror ("fgets for dbuf is failed.. \n");                                           
				 exit (1);                                                               
   			 }                                                                           
                                               
			 len2 = my_strlen(dbuf);      

			 if ((len2 > 0) && (dbuf[len2 -1] == '\n')){
					dbuf[len2 - 1] = '\0';
			 }


			 p = remstr(sbuf,dbuf);		
			 
			 if (p  == NULL)
				printf ("sub-string not found \n");
			 else 
				 printf ("after removing the string : %s \n", p);

			 break;

	case 15 : /*a function which will insert a char ch in the given string str 
				at a specified position pos*/
			 printf ("enter the main string : \t");
			
//			 printf ("Enter the character to add into string : \n");
//			 scanf ("%c", &ch);
 
			 getchar();           
                  
   			 if (NULL == (fgets(sbuf, MAX, stdin))){                                      
				 perror ("fgets for sbuf is failed.. \n");                                           
				 exit (1);                                                               
   			 }                                                                           
                                               
			 len1 = my_strlen(sbuf);      

			 if ((len1 > 0) && (sbuf[len1 -1] == '\n')){
					sbuf[len1 - 1] = '\0';
			 }														
				
			 ch = 's';
			
			 printf ("enter the position : \n");
			 scanf ("%d", &pos);

			 p = insert_char (sbuf, ch, pos);
			
			 printf ("after adding the character : %s \n", p);
		
			 break;


	default : printf ("enter the correct program");

	}

	return 0;
}


