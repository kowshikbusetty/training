#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

unsigned long glob = 5;

int main( void )
{
	int fd;

	fd = open("/dev/pgw", O_RDWR);
	
	printf("pid from app%d\n", getpid());

	if(fd < 0) {
		perror("unable to open the device");
	} else {
		printf("file opened successfully %d \n", fd);
	}
	
	printf("glob var bef ioctl:%p %d\n", &glob, glob);

	ioctl(fd, getpid(), &glob);

	printf("glob var aftr ioctl:%p %d\n", &glob, glob);

	close(fd);

	return 0;
}
