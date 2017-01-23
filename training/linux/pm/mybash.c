#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 80

int main ( void )
{
	printf(" welcome to MY SHELL \n");

	while(1){ 
		char *argv[MAX];
		int i = 0;
		char *delimit = "\n ";
		pid_t pid;
		char arr[MAX] = {'\0'};   	

		printf("myshell$:");
		fgets(arr , 80 , stdin);

		argv[0] = (char *)strtok (arr,delimit);

		for ( i= 0 ;(argv[i] != NULL); i++ ){
			argv[i + 1] =  (char *)strtok (NULL,delimit);
		}
		pid = fork();
		if( pid == 0 ){
			execvp(argv[0], argv);
			printf(" exec failed \n");
		}
		else{
			wait(NULL);	
		}
	}
	return 0;
}
