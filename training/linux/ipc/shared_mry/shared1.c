#include "errors.h"
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE (4096 * 10)
#define LENGTH (4096 * 2)
#define MAX 80

int main(void)
{
	int shmd;	//used for opening the session for shared memory
	off_t length = SIZE;	
	void * map;	//used for mapping the shared memory with virtual Address space 
	char buf[MAX];

	//creating (or) opening the shared memory

	if(-1 == (shmd = shm_open("/shared", O_RDWR | O_CREAT, 00777) ) ){
		errno_abort("shared memory is not opened \n");
	}
	
	//allocating the size for shared memory

	if (-1 == ftruncate(shmd, length)){
		errno_abort("allocation of size for shared memory failed \n");
	}

	//mapping files into memory
	
	if(MAP_FAILED == (map = mmap(NULL, LENGTH, PROT_READ | PROT_WRITE, MAP_SHARED, shmd, 0x00000000) ) ){
		errno_abort("mapping failed ....! \n");
	}
	
	//accesing the data from stdin to write into memory

	printf("Enter the data to write into shared memory : \n");

	if(NULL == fgets(buf, MAX, stdin)){
		perror("accessing the data from stdin failed ....! \n");
	}

	//writing data into memory

	strcpy((char *)map, buf);

	if(-1 == close(shmd)){
		errno_abort("closing shared memory session failed \n");
	}
	
	return 0;
}
