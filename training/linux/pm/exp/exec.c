#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#if 1
int main (void)
{
	pid_t pid, wait_pid;
	int status = 0;
	
	printf("in main pid : %d \n", getpid());
	printf("in main ppid : %d \n", getppid());

	pid = fork();
//	pid = fork();

	if (pid > 0){

		printf("in parent pid : %d \n", pid);
		if (pid == wait(&status)){
			printf ("status : %d \n", status);
			printf ("&status : %p \n", &status);
		}

	}else if (0 == pid){
		printf("in child pid : %d \n", pid);
		return 1;
	}else
		printf("fork error ....! \n");

	getchar();

	return 0;
}
#endif
