#include <stdio.h>
//#include <string.h>
char *my_strstr(char *, char *);
extern char *sappend(char *, char *); 
extern int my_strlen (char *); 
                                               
int my_strrot(const char *str, const char *rstr)                                
{                             
	int len1;
	int len2;
	char *p;
	char temp[100]; 
                                                 
	temp[0] = '\0';   
                                                                            
    len1 = my_strlen((char *)str);                                              
    len2 = my_strlen((char *)rstr);                                             
                                                                                
    if (len1 != len2)                                                           
        return 0;                                                               
                                                                                
	sappend ((char *)str, temp);
	sappend ((char *)str, temp);
                                                                                
    p = my_strstr(temp, (char *)rstr);                                                  
                                                                                
    if (p == NULL)                                                              
        return 0;                                                               
    else                                                                        
        return 1;                                                               
                                                                                
}                                                                               
