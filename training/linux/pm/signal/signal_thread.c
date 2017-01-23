#include "errors.h"
#include <signal.h>
#include <pthread.h>

int status;

void signal_handler(int signum)
{
	if(signum == SIGWINCH) 
		printf("\nSignal received : ignore, window resize \n");
}

/*
 *generating signal in thread1
 */

void threadfunc1 (char *l)                                                       
{
	signal(10, signal_handler);

	printf("in thread1 \n");
 
	if(-1 == (status = kill(getpid(), SIGWINCH))){
		errno_abort("Signal sent failed : SIGUSR1 \n");
	}
}

/*
 *checking whether thread2 will execute
 */
void threadfunc2 (char *l)                                                       
{
	printf("in thread2 \n");
}

int main(void)
{
	pthread_t thread1, thread2;

	if (0 < (status = pthread_create(&thread1, NULL, (void *)threadfunc1, NULL))){
                err_abort(status, "thread creation failed\n");                  
    } 
	                                                                             
    if (0 < (status = pthread_create(&thread2, NULL, (void *)threadfunc2, NULL))){
                err_abort(status, "thread creation failed\n");                  
    }  

	printf("\nsignals generated successfully \n\n");
	pthread_exit(EXIT_SUCCESS);
	return 0;
	
}
