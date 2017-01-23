#include "errors.h"
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>

#define SIZE (4096 * 10)
#define LENGTH (4096 * 2)
#define MAX 80


int main(void)
{
	int shm;	//used for opening the session for shared memory
	sem_t *sem; //used for creating semaphore 
	off_t length;	
	char buf[MAX];	
	void * map;

	length = SIZE;

	//creating (or) opening the shared memory

	if(-1 == (shm = shm_open("/shared", O_RDWR , 00777) ) ){
		errno_abort("shared memory is not opened \n");
	}

	
	//creating a semaphore                                                      
                                                                                
    if(SEM_FAILED == (sem = sem_open("/semaphore", O_CREAT | O_RDWR, 00777, 1u) ) ){
        errno_abort("Creating a Semaphore failed....! \n");                     
    }  

	//mapping vertual memory with physical memory

	if(MAP_FAILED == (map = mmap(NULL, LENGTH, PROT_READ , MAP_SHARED, shm, 0x00000000) ) ){
        errno_abort("mapping failed ....! \n");                                 
    }   

/*	//releasing the lock for semaphore

	if(-1 == sem_post(sem)){
		errno_abort("Semaphore unlocking failed ....! \n");
	}
*/
	//acquiring the lock by semaphore                                           
                                                                                
    if(-1 == sem_wait(sem)){                                                    
        errno_abort("Semaphore locking failed....! \n");                        
    }                                                                           
        
	//accessing contents of shared memory 
	
	printf("Read data from memory : %s \n", (char *)map);
	
	//releasing the lock for semaphore

	if(-1 == sem_post(sem)){
		errno_abort("Semaphore unlocking failed ....! \n");
	}

	//unmap the files from shared memory

	if(-1 == munmap(NULL, SIZE) ){
		errno_abort("Unmapping failed....! \n");
	}

	//unlink the shared memory

	if(-1 == shm_unlink("/shared")){
		errno_abort("unlink failed \n");
	}      

	//closing the session for shared memory
	
	if(-1 == close(shm)){
		errno_abort("closing shared memory session failed \n");
	}

	//closing the semaphore                                                     
                                                                                
    if(-1 == sem_close(sem)){                                                   
        errno_abort("Closing semaphore failed....! \n");                        
    }  

	//unlink the semaphore when not on use
	
	if(-1 == sem_unlink("/semaphore")){
		errno_abort("Unlink of semaphore failed ....! \n");
	}
	
	return 0;
}
