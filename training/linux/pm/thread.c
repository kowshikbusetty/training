#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *fun(void *a)
{
	printf("In Thread\n");

//	sleep(10);

	printf("in thread pid : %d \n", getpid());

	return NULL;
}

int main(void)
{
	pthread_t thread;
	int thread_id;

	printf("parent pid : %d \n", getpid());

	thread_id = pthread_create(&thread, NULL, fun, (void *)5);

//	fflush(NULL);
	
	if(0 == thread_id){
		printf("in thread group leader pid is : %d \n", getpid());
		printf("thread is created \n");
	}else if(thread_id){
		printf("Error.Thread creation failed ..! ");
		exit(1);
	}

	printf("In parent\n");
	pthread_exit(NULL);

//	exit(1);

	return 0;
}
