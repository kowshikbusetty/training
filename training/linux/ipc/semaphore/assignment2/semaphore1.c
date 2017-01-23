#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <semaphore.h>
#include "errors.h"
#include <pthread.h>

#define MAX 80
#define SIZE (120)
#define LENGTH (80) 

sem_t *sem;	//used for creating semaphore

int main(void)
{
	int shmd;   //used for opening the session for shared memory
	void * map;	//used for mapping the shared memory with virtual Address space
	char * buf = NULL;
	off_t length;
	int i = 10;	//used for accessing 10 integers

	length = SIZE;
	
	//creating (or) opening the shared memory                                   
                                                                                
    if(-1 == (shmd = shm_open("/shared", O_RDWR | O_CREAT, 00777) ) ){          
        errno_abort("shared memory is not opened \n");                          
    } 

	//allocating the size for shared memory                                     
                                                                                
    if (-1 == ftruncate(shmd, length)){                                         
        errno_abort("allocation of size for shared memory failed \n");          
    } 

	//creating a semaphore

	if(SEM_FAILED == (sem = sem_open("/semaphore", O_CREAT | O_RDWR, 00777, 1u) ) ){
		errno_abort("Creating a Semaphore failed....! \n");
	}

	//mapping virtual memory with physical memory                            
                                                                                
    if(MAP_FAILED == (map = mmap(NULL, LENGTH, PROT_READ | PROT_WRITE, MAP_SHARED, shmd, 0x00000000) ) ){
        errno_abort("mapping failed ....! \n");                                 
    }   	


	printf("Enter the data to write into shared memory : \n");
																				
	while(i){

		//acquiring the lock by semaphore

		if(-1 == sem_wait(sem)){
			errno_abort("Semaphore locking failed....! \n");
		}

		//allocating memory for accessing buffer 

		if(NULL == (buf = (char *)malloc(MAX))){
			perror("Malloc failed \n");
			exit(1);
		}

		//accesing the data from stdin to write into memory

		if(NULL == fgets(buf, MAX, stdin)){
			perror("accessing the data from stdin failed ....! \n");
		}

		//writing data into memory 
																				
		memcpy((char *)map, buf, (strlen(buf) - 1));

		free(buf);
		buf = NULL;//releasing memory
 
		//releasing the lock for semaphore

		if(-1 == sem_post(sem)){
			errno_abort("Semaphore unlocking failed ....! \n");
		}

		i--;
		sleep(1);
		
	}	//while loop end

	if(-1 == close(shmd)){
		errno_abort("closing shared memory session failed \n");
	}

	//closing the semaphore
	if(-1 == sem_close(sem)){
		errno_abort("Closing semaphore failed....! \n");
	}

	return 0;
}
