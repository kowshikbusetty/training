#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>

int main( void )
{
	int fd;

	fd = open("/dev/myChar", O_RDONLY);

	if(fd < 0) {
		perror("unable to open the device");
	} else {
		printf("file opened successfully %d \n", fd);
	}

	printf ("in app pid is : %d \n", getpid());	

	if(-1 == ioctl(fd, getpid(), 12)){
		perror("ioctl failed...!\n");
		exit(1);
	}

	if(-1 == close(fd)){
		perror("close failed \n");
		exit(1);
	}
	
	getchar();

	return 0;
}
