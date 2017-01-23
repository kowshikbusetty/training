#include<stdio.h>
#include<stdlib.h>

#if 0
int main (void)
{
	FILE *fd, *fd2;                                                              
    char c;                                                                                                               
        if(NULL == (fd = fopen("abc2.txt","r"))) {                         
            perror("Can't o//pen the file");                                     
            exit(2);                                                             
        }           
	fd2 = fd;
	 printf("%c",fgetc(fd2));     
	fseek(fd,5,SEEK_CUR);
	printf("%c",fgetc(fd));
	printf("%c",fgetc(fd2));   
	return 0;
}    
#endif

#if 1
int main(void)
{
	100;
	printf("hello \n");

	return 0;
}
   
#endif
