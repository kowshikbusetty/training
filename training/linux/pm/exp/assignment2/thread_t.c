#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/syscall.h>
#define MAX 3

void *thread_start(void *arg);
void *second_thread(void *arg);

pthread_t thr;

int main( void )
{	

	int my_thread;
	int s;
	int a = 20;
	pid_t tid = syscall(SYS_gettid);
	pthread_attr_t attr;

		s = pthread_attr_init(&attr);
    	if (s != 0)
    	   perror("pthread_attr_init failed");

		my_thread = pthread_create(&thr, &attr, &thread_start, &a);
		
		if(my_thread != 0) {
	
			perror("thread creation failed.. \n");
	
		} else {
			
			printf("thread created succesfully..%d \n", tid);		
		}
		s = pthread_attr_destroy(&attr);
        if (s != 0)
            perror("pthread_attr_destroy failed \n");
		pthread_exit(NULL);
return 0;
}

void *thread_start(void *arg)
{

	int my_thr;
	pid_t tid = syscall(SYS_gettid);

	my_thr = pthread_create(&thr, NULL, &second_thread, NULL);
	if(my_thr != 0) {                                                    
        perror("thread creation failed.. \n");                              
    } else {                                                                
        printf("thread created succesfully..%d \n", tid);                   
    }     

	return NULL;
}

void *second_thread(void *arg)
{
	printf("Second thread created \n");
	
	return NULL;	
}

















