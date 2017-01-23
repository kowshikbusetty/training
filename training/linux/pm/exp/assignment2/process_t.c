#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>

#define MAX 3

void *thread_start(void *arg);


int main( void )
{	

	pthread_t thr;
	int status;
	int s;
	int a = 20;
	pthread_attr_t attr;

	s = pthread_attr_init(&attr);
    if (s != 0)
       perror("pthread_attr_init failed");

	//	printf("%d \n %d",getpid(),gettid());
	status = pthread_create(&thr, &attr, &thread_start, &a);	
	if(status != 0) {
			perror("thread creation failed.. \n");
	}

	pthread_join(thr, NULL);
	pthread_exit(NULL);
return 0;
}

void *thread_start(void *arg)
{

	pid_t tid = syscall(SYS_gettid);

	printf("I am in thread and result is %d and tid is %d \n", *(int *)arg, tid);

	return NULL;
}



















