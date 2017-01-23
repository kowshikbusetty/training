#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <signal.h>

#include"errors.h"
#if 1
int fd;
int status;
void *thread(void *i)
{
	
	printf("Thread pid is %d\n", getpid());   
	printf("in thread using syscall  %lu\n", syscall(SYS_gettid));

	if(-1 == (status = ioctl(fd, getpid(), 0))) {
		errno_abort("ioctl failed");
	}
	getchar();
	getchar();
	pthread_exit(NULL);
}
int main(void)
{
	pthread_t tid;

	printf("pid is %d\n", getpid());
	printf("using syscall  %lu\n", syscall(SYS_gettid));

	fd = open ("/dev/myChar", O_RDWR);
	if(fd < 0) {
		errno_abort("open failed");
	}
	else
		printf("File opened Successfully %d\n", fd);


	    if(status = pthread_create(&tid, NULL, thread, NULL)) {
			err_abort(status, "pthread_create() failed");
		}
	if(-1 == (status = ioctl(fd, getpid(), 0))) {
		errno_abort("ioctl failed");
	}
	printf("Thread Group Leader \n");

	pthread_exit(NULL);
	return 0;
}
#endif
