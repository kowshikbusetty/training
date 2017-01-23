#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#if 1

void sig_handler(int sig_num, siginfo_t * handler, void * p)
{
	if(SIGSEGV == sig_num) {       
    	printf("\nSignal received : segmentation fault\n");  
		printf("Address :  %08x \n",(unsigned int) handler->si_addr);
		printf("Adress last byte : %hi \n", handler->si_addr_lsb);
		exit(1);
	}else if(sig_num == SIGINT) {
		printf("\nSignal received from keyboard : interrupt  \n");
		exit(1);

	}else if (sig_num == SIGTSTP){
		 printf ("\nSignal received from keyboard : stop process execution \n");
		return;
	}else if(sig_num == SIGUSR1){
		printf ("\nsignal recived from usr1 - SIGUSR1 \n");
		return;
	}else if(sig_num == SIGUSR2){
		printf ("\nsignal recived from usr2 - SIGUSR2 \n");
		return;
	}
}

int main (void)
{
	int status;
	int *p;
	struct sigaction sig_act;

	sig_act.sa_sigaction = sig_handler;
	sig_act.sa_flags = SA_SIGINFO;

	p = (int *)64;

	//registering for signal - SIGSEGV
	if(-1 == sigaction(SIGSEGV, &sig_act, NULL)) {
		perror("sigaction error");
		exit(1);
	}

	//registering for signal - SIGTSTP
	if(-1 == sigaction(SIGTSTP, &sig_act, NULL)) {
		perror("sigaction error");
		exit(1);
	}

	//registering for signal - SIGINT
	if(-1 == sigaction(SIGINT, &sig_act, NULL)) {
		perror("sigaction error");
		exit(1);
	}

	//registering for signal - SIGUSR1
	if(-1 == sigaction(SIGUSR1, &sig_act, NULL)) {
		perror("sigaction error");
		exit(1);
	}

	//registering for signal - SIGUSR2
	if(-1 == sigaction(SIGUSR2, &sig_act, NULL)) {
		perror("sigaction error");
		exit(1);
	}

	//sending signal-SIGUSR1
	if(-1 == (status = kill(getpid(), SIGUSR1))){
		perror("Signal sent failed : SIGUSR1 \n");
		exit(1);
		} 

	//sending signal - SIGUSR2
	if(-1 == (status = kill(getpid(), SIGUSR2))){
		perror("Signal sent failed : SIGUSR2 \n");
		exit(1);
		} 

	//stop processes issued
	printf("enter (ctrl + c) or (ctrl + z) \n");
	getchar();

	//generating interrupt from keyboard
	printf("enter (ctrl + c) or (ctrl + z) \n");
	getchar();

	//generating segfault
	printf("%d \n", *p);

	return 0;

}
#endif
