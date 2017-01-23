#ifndef MY_HEADER
#define MY_HEADER
extern int my_is_alpha(char);                                                   
extern void my_strcpy (char *, char *);                                         
extern void my_strncpy (char *, char *, int);                                   
extern char *char_add_instr (char *, char);                                     
extern char *sappend(char *, char *);                                           
extern char *snappend(char *, char *,int );                                     
extern char my_strcmp (char *, char *);                                         
extern char my_strcasecmp (char *, char *);                                     
extern int my_strspn(const char *, const char *);                            
extern char * my_strtok(const char *, const char *);                            
extern void string_palindrome(char *);                                          
extern char *my_reverse(char *);                                                
extern char *my_squeze(char *);                                                 
extern char *remstr(char *, const char *);                                      
extern char *insert_char (char *, char, int);                                   
extern int my_strlen (char *);   
extern int my_strrot(const char *, const char *);
#endif
