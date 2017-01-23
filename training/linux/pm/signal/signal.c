#include "errors.h"
#include <signal.h>

void signal_handler(int signum)
{
	if(signum == SIGUSR1) 
		printf("\nSignal received : Termintae, Available to process \n");
	if (signum == SIGWINCH) 
		printf ("Signal received : Terminate, profile timer clock \n");
	
}

int main(void)
{
	int status;
	pid_t pid = getpid();

	signal(10, signal_handler);

	if(-1 == (status = kill(pid, SIGUSR1))){
		errno_abort("Signal sent failed : SIGUSR1 \n");
	}

//	signal(28, signal_handler);

	if(-1 == (status = kill(pid, SIGSTOP))){
		errno_abort("Signal sent failed : SIGWINCH \n");
	}

	printf("\nsignals generated successfully \n\n");
	return 0;
}
