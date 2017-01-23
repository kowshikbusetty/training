#include <fcntl.h>
#include "../errors.h"

#define MAX 80	//used for array index

#if 1
int main(void)
{
	int fifod;
	int od;
	char buf[MAX];	//used for receiving and trasvering the data

	
	//opening the fifo for writing the data

	if(-1 == (od = mkfifo("file", 0777) ) ){
		errno_abort("Opening the fifo for writing is failed....!"); 
	}

	printf("Enter the data to Write into fifo : \n");

	if(-1 == (od = open("file", O_WRONLY) ) ){
		perror("Write failed \n");
		exit(1);
	}

	//accessing the data which has to write into fifo

	if(NULL == fgets(buf, MAX, stdin) ){
		printf("fgets failed \n");
		exit(1);
	}

	//writing into fifo
	if(-1 == write( od, buf, MAX ) ){
		errno_abort("Write into pipe failed \n");
	}

	close(od);
	return 0;
} 
#endif
