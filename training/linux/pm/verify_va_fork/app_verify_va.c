#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
//int ioctl(int, int, int);

int main( void )
{
	int fd, sd;
	pid_t pid;

	fd = open("/dev/myChar", O_RDONLY);

	if(fd < 0) {
		perror("unable to open the device");
	} else {
		printf("file opened successfully %d \n", fd);
	}

	printf ("in app pid is : %d \n", getpid());	
	if((sd = open( "just.txt",O_RDWR | O_CREAT , S_IRUSR | S_IWUSR )) == -1) {
		perror("Source file error");                                        
            exit(0);                                                            
        }    
	pid = fork();

	if(pid > 0){
		write (sd,"Global Edge\n",12);
		ioctl(fd, getpid(), sd);

	}else if (pid == 0){
		write (sd,"Software limited\n",17);
		ioctl(fd, getpid(), sd);
	}else
		printf ("fork failed ....... \n");

	close(fd);

	return 0;
}
