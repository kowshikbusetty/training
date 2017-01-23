#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
void my_print(int num, char *signame)
{
	if(num == SIGINT)
		printf("the %s signal is blocked\n", signame);
}

void termination_handler (int signum)
{
	printf("In handler \n");
	my_print(signum, "SIGINT");
}

int main (void)
{
	struct sigaction new_sigact, old_sigact;

	new_sigact.sa_flags = 0 | SA_NODEFER | SA_RESETHAND;

	new_sigact.sa_handler = termination_handler;

	sigaction( SIGINT, &new_sigact, NULL);

	printf( "raise SIGINT signal\n" );
    kill( getpid(), SIGINT);

/*	sigaction( SIGINT, NULL, &old_sigact );
    if ( old_sigact.sa_handler != SIG_DFL )
        printf( "signal handler was not reset\n" );

	sigaction( SIGINT, NULL, &old_sigact );
    if( old_sigact.sa_handler != termination_handler)
        printf( "signal handler was reset\n" );
*/

	return 0;
}

#endif

#if 1

void sig_handler(int sig_num, siginfo_t * handler, void * p)
{
	if(SIGSEGV == sig_num) {       
    	printf("Signal received : segmentation fault\n");  
		printf("Address :  %08x \n",(unsigned int) handler->si_addr);
		printf("Adress last byte : %hi \n", handler->si_addr_lsb);
//		printf("trap no. : %d \n", handler->si_trapno);
		exit(1);                                
	}
	return;
}

int main (void)
{
	int *p = (int *)64;
	struct sigaction sig_act;

	sig_act.sa_sigaction = sig_handler;
	sig_act.sa_flags = SA_SIGINFO;

	if(-1 == sigaction(SIGSEGV, &sig_act, NULL)) {
		perror("sigaction error");
		exit(1);
	}

	printf("%d \n", *p);

	return 0;

}
#endif
