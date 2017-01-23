#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
//#include <sys/ioctl.h>

int ioctl(int, int, int);

int main( void )
{
	int fd;

	fd = open("/dev/myChar", O_RDWR);

	if(fd < 0) {
		perror("unable to open the device");
	} else {
		printf("file opened successfully %d \n", fd);
	}

	printf ("in app pid is : %d \n", getpid());	
	
	ioctl(fd, getpid(), 12);

	close(fd);

	return 0;
}
