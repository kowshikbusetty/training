#include "errors.h"
#include <signal.h>

void signal_handler(int signum)
{
	if (signum == SIGSEGV) 
		printf ("\nSignal received : Dump, Invalid memory reference \n\n");

//	return;//executes handler infinite times

	exit(0);//without exit - signal_handler executes infinite times	
}

int main(void)
{
	int status;
	pid_t pid = getpid();

	signal(11, signal_handler);

	int *p =(int *) 0;
	printf("%d \n", *p);

/*	if(-1 == (status = kill(pid, SIGSEGV))){
		errno_abort("Signal sent failed : SIGUSR1 \n");
	}
*/
	printf("\nsignals generated successfully \n\n");
	return 0;
}
