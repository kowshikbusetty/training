#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <sys/wait.h>

unsigned long g_var = 5;

int main( void )
{
	int fd;
	pid_t pid;
	int *heap_var = malloc(4);
	int loc_var = 4;

	*heap_var = 20;

	fd = open("/dev/myChar", O_RDWR);
	
	printf("pid from app : %d\n", getpid());

	if(fd < 0) {
		perror("unable to open the device");
	} else {
		printf("file opened successfully %d \n", fd);
	}

	printf("before fork - &g_var : %p\n", &g_var);	
	ioctl(fd, getpid(), &g_var);// printing page frame
	getchar();

	pid = fork();

	if(pid > 0) {//parent process

#if 0	
		if(-1 == wait(NULL)) {
			perror("wait failed");
			exit(1);
		}
#endif
	
		printf("in parent before modify - &g_var: %p\n", &g_var);
		ioctl(fd, getpid(), &g_var);
		getchar();
#if 1
		//modifying the data in parent process

		*heap_var = 50;
		loc_var = 5;
		g_var = 24;

		printf("in parent after modify - &g_var : %p\n", &g_var);
		ioctl(fd, getpid(), &g_var);
		getchar();

		printf("in parent after modify - &loc_var : %p\n", &loc_var);
		ioctl(fd, getpid(), &loc_var);
		getchar();

		printf("in parent after modify - &heap_var : %p\n", heap_var);
		ioctl(fd, getpid(), heap_var);
		getchar();
#endif

		/*--- end of parent process ---*/

	} else if(pid == 0) {//child process

		printf("in child before modify - &g_var : %p \n", &g_var);
		ioctl(fd, getpid(), &g_var);
		getchar();

#if 1
		//modifying the data in child process

		*heap_var = 50;
		loc_var = 5;
		g_var = 24;

		printf("in child after modify - &g_var :  %p\n", &g_var);
		ioctl(fd, getpid(), &g_var);		
		getchar();

		printf("in child after modify - &loc_var : %p\n", &loc_var);
		ioctl(fd, getpid(), &loc_var);
		getchar();

		printf("in child after modify - &heap_var : %p\n", heap_var);
		ioctl(fd, getpid(), heap_var);
		getchar();
#endif

	/*--- end of child process ---*/

	} else {
		perror("fork failed");
		exit(1);
	}

	if(-1 == close(fd)){
		perror("closing session for character devices failed \n");
		exit(EXIT_FAILURE);
	}

	return 0;
}
