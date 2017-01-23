#include <signal.h>
#include <fcntl.h>
#include "errors.h"

#define MAX 80	//used for array index

#if 1
int main(void)
{
	int pipefd[2];	//used as descriptors for pipe

	char buf[MAX];	//used for receiving and trasvering the data

	if(-1 == pipe(pipefd)){	//creating the pipe
		errno_abort("pipe is not created \n");
	}	

	pid_t pid = fork();	//creating child process

	if (pid > 0){	//parent writes (trasfers) data into pipe

		close(pipefd[0]);	//closing read session
		
		printf("Write the data into pipe : \n");
	
		//accessing the data which has to transfer through pipe

		if(NULL == fgets(buf, MAX, stdin)){
			printf("fgets failed \n");
			exit(1);
		}
	
		//sending the data into pipe
		if(-1 == write(pipefd[1], buf, MAX)){
			errno_abort("Write into pipe failed \n");
		}

		close(pipefd[1]);//after passing the data into pipe close the write descriptor

	}else if(0 == pid){	//child reads (receives) data from pipe

		close(pipefd[1]);	//closing session for transfering the data

		//receiving the data from pipe
		if(-1 == read(pipefd[0], buf, MAX)){
			errno_abort("Read from pipe failed \n");
		}

		//printing the data received from pipe
		printf("\nReading data from pipe :\n%s \n", buf);
			
		close(pipefd[0]);	//closing session for receiving the data

	}else{
		printf("Error: child creation failed using fork \n");
	}

	return 0;
} 
#endif
