#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

//int ioctl(int, int, int);

int main( void )
{
	int fd;
	pid_t pid;

	fd = open("/dev/myChar", O_RDONLY);

	if(fd < 0) {
		perror("unable to open the device");
	} else {
		printf("file opened successfully %d \n", fd);
	}

	printf ("in app pid is : %d \n", getpid());	

	pid = vfork();

	if(pid > 0){		
		ioctl(fd, getpid(), 12);
	}else if (pid == 0){
		ioctl(fd, getpid(), 12);
		exit(1);
	}else
		printf ("fork failed ....... \n");

	close(fd);

	return 0;
}
