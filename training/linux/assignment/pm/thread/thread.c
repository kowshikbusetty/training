#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *fun(void *a)
{
	printf("In Thread\n");
	printf("in thread pid : %d \n", getpid());
}

int main(void)
{
	pthread_t thread;
	int thread_id;

	printf("parent pid : %d \n", getpid());

	thread_id = pthread_create(&thread, NULL, fun, (void *)5);
	
	if(0 == thread_id){
		printf("thread pid is : %d \n", getpid());
		printf("thread is created \n");
	}else if(thread_id){
		printf("Error.Thread creation failed ..! ");
		exit(1);
	}

	printf("In parent\n");
	pthread_exit(NULL);

	return 0;
}
