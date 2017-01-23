#include <signal.h>
#include <fcntl.h>
#include "../errors.h"

#define MAX 80	//used for array index

#if 1
int main(void)
{
	int fd;
	char buf[MAX];	//used for receiving and trasvering the data

	
	//opening the fifo for reading the data

	if(-1 == (fd = open("file", O_RDONLY) ) ){
		perror("Opening the fifo for reading is failed....!");
	}

	//reading the data from fifo
	if(-1 == read(fd, buf, MAX)){
		errno_abort("Write into pipe failed \n");
	}

	printf("Read data from fifo : %s \n", buf);

	close(fd);
	return 0;
} 
#endif
