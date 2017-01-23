#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define MAX 256

int glob_var = 25;

int main( void )
{	
	pid_t pid;
	int local_var = 45;
	int *h_var;
	
	h_var = (int *)malloc(sizeof(int));
	*h_var = 82;
	
	pid = fork();

	if(pid > 0) {
		
		sleep(5);		
		printf("I am in parent process..\n");
		printf(" local_var = %d\n glob_var = %d \n h_var = %d\n", local_var, glob_var,*h_var);
		printf("local_var = %p\n glob_var = %p \n h_var = %p\n", &local_var, &glob_var, h_var);
		
	} else if(pid == 0) {
	
		printf("I am in child process..\n");
		local_var = 22;
		glob_var = 102;
		*h_var = 212;
		printf(" local_var = %d\n glob_var = %d \n h_var = %d\n", local_var, glob_var, *h_var);
		printf("local_var = %p\n glob_var = %p \n h_var = %p\n", &local_var, &glob_var, h_var);

	} else {
		
		perror("fork failed");
	
	}


return 0;
}

