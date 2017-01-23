#include "errors.h"
#include <fcntl.h>
#include <signal.h>

#if 1

int status;

int main(void)
{
	pid_t pid;
	int pipefd[2];	//used for creating sessions using pipes

	if(-1 == pipe(pipefd)){		//creating the pipe
        errno_abort("pipe is not created \n");
    }

	printf("pipefd[0] : %d pipefd[1] : %d \n", pipefd[0], pipefd[1]);

	pid = fork();

	if (pid > 0){

		close(pipefd[0]);	//closing read session

		//changing pipefd[0] session descriptor with stdout session descriptor
		dup2(pipefd[1], 1);

/*		signal(SIGCHLD, SIG_DFL);	//waiting untill child terminates

        if(-1 == (status = kill(pid, SIGCHLD))){
            errno_abort("Signal sent failed : SIGUSR1 \n");
        }
*/

		sleep(5);

		//executing the other application in our application
		execlp("ls", "ls", NULL);

	}else if (pid == 0){

		close(pipefd[1]);	//closing write session
		
		//changing stdin session descriptor with pipefd[0] session descriptor
		dup2(pipefd[0], 0);

		//executing other application with our application
		execlp("wc", "wc", NULL);	

	}else
		printf("Error: child creation failed \n");

	return 0;
}
#endif
