#include "errors.h"
#include <signal.h>

void signal_handler(int signum)
{
	if(signum == SIGCHLD) 
		printf("\nSignal received : Terminte, child terminated \n");
}

int main(void)
{
	int status;
	pid_t pid = getpid();

//	signal(17, signal_handler); //signal handler executes 2 times	

	pid = fork();                                                               
                                                                                
    if (pid > 0){

		signal(17, signal_handler);	

		if(-1 == (status = kill(pid, SIGCHLD))){
			errno_abort("Signal sent failed : SIGUSR1 \n");
		}
	
		wait(NULL);	

	}else if (pid == 0){

	printf("\nchild is sending the signal \n");

	}else
		printf("\nfork creation error.....! \n"); 
	
	return 0;
}
