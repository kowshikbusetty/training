#include "errors.h"
#include <signal.h>

void signal_handler(int signum)
{
	if(signum == SIGINT) 
		printf("\nSignal received from keyboard : interrupt  \n");
	if (signum == SIGTSTP) 
		printf ("\nSignal received from keyboard : stop process execution \n");

	exit(1);	
}

int main(void)
{
	int status;
//	pid_t pid = getpid();

	signal(20, signal_handler);
	signal(2, signal_handler);

	getchar();

	printf("\nsignals generated successfully \n\n");
	return 0;
}
