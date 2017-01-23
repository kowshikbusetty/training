#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int g_var = 20;

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
	printf ("address of global varaible is : %p\n", &g_var);	
	ioctl (fd, getpid(), &g_var);
	getchar();

	printf("global variable after modifying : %d \n", g_var);

	close(fd);


	return 0;
}
