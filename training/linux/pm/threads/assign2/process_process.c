#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
	pid_t pid;
	pid = fork();

	if(pid > 0) {
		printf("In parent\n");
		printf("Process id %d\n", getpid());	
	} else if(pid == 0) {
		printf("In child\n");
		printf("Process id %d\n", getpid());	
		
	} else {
		printf("fork() failed\n");
	}

	return 0;
}
