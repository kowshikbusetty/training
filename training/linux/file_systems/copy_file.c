#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>                                                          
#include <sys/stat.h>                                                           
#include <stdlib.h>
#include <errno.h>                                                              
#include <string.h>
#include <fcntl.h>

#define MAX 80

int main(void)
{
	FILE *fr = NULL, *fw = NULL;
	char buf[MAX];

	if ( -1 == (fw = open ("file_copy.txt",O_CREAT)) ){
		perror ("file_copy is not created \n");
		exit (1);
	}    

	fr = open("file.txt", O_RDONLY);
	
	if (fr >0){
	read(fr, buf,1);
	write(fw, buf, 1);
	}

	close(fr);
	close(fw);

	return 0;
}
