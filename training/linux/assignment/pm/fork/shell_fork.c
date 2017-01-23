#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#if 1

int global = 10;

int main (void)
{
	int stack = 20;
	int *heap = (int *) malloc(4);
	int pid;
	char *argv[] = {"./async_alarm"}; 

	*heap = 30;

	printf("before fork\n");
	printf("global = %d\taddress : %p\n", global, &global);
	printf("stack = %d\taddress : %p\n", stack, &stack);
	printf("heap = %d\taddress : %p\n", *heap, &heap);

	pid = fork();

	if (pid > 0) {
		wait(NULL);
		printf("in parent\n");
		printf("global = %d\taddress : %p\n", global, &global);
		printf("stack = %d\taddress : %p\n", stack, &stack);
		printf("heap = %d\taddress : %p\n", *heap, &heap);
	} else if (pid == 0) {
		global = 200;
		stack = 1000;
		*heap = 5000;
	
		printf("in child \n");
		printf("global = %d\taddress : %p\n", global, &global);
		printf("stack = %d\taddress : %p\n", stack, &stack);
		printf("heap = %d\taddress : %p\n", *heap, &heap);

		execv(argv[0], argv);
		printf("execv failed\n");
		exit(0);
	}

	return 0;
}

#endif
