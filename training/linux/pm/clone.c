#include <stdio.h>
#include <stdlib.h>
#include<sched.h>
#include<unistd.h>
#include <linux/sched.h>

#define STACK_SIZE (1024 * 1024)

int clone(int(*fn)(void), char *, int, ...);
int fun(void)
{
	printf ("function success \n");
	return 0;
}

int main(void)
{
	int thread_pid;
	char * stack = NULL;

	if(NULL == (stack = (char *)malloc(STACK_SIZE))){
		perror("child stack creation failed .... \n");
		exit(1);
	}

	if (0 < (thread_pid = clone(&fun, stack + STACK_SIZE, CLONE_VM,0))){
			printf("threads pid is : %d \n", thread_pid);
	}else if (-1 == thread_pid){
		perror("thread creation failed ...! \n");
		exit(1);
	}

	free(stack);
	stack = NULL;

	printf("child executed successfully \n");

	return 0;
}
