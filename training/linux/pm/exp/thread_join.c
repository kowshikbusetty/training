#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>

int t_status;

void *fun(void *a)
{
	printf("thread pid is : %d \n", getpid());
	printf("I am in Thread function \n");

	t_status = 25;

//	return &t_status;
	pthread_exit(&t_status);
}

int main(void)
{
	pthread_t thread_id;
	int thread;
	int *retval = malloc(sizeof(int));

	printf("parent pid : %d \n", getpid());

	thread = pthread_create(&thread_id, NULL, fun, NULL);
	
	if(0 == thread){
		printf("thread is created \n");
	}else if(thread){
		perror("Error.Thread creation failed ..! ");
		exit(1);
	}

	//pthread_detach(thread_id);

	thread = pthread_join(thread_id, (void **)&retval);

	if(thread != 0){
		perror("thread join failed .....!");
	}else {
		printf("return value is : %d \n", *retval);
	}
	printf("In parent\n");
	pthread_exit(NULL);

	return 0;
}
