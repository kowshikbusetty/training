#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <semaphore.h>
#include "errors.h"
#include <pthread.h>

#define MAX 80
#define SIZE (4096 * 10)
#define LENGTH (4096 * 2) 


int main(void)
{
	int shmd;   //used for opening the session for shared memory
	void * map;	//used for mapping the shared memory with virtual Address space
	sem_t *sem;	//used for creating semaphore
	char buf[MAX];
	off_t length;

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

	//acquiring the lock by semaphore(decrementing semaphore value)

	if(-1 == sem_wait(sem)){
		errno_abort("Semaphore locking failed....! \n");
	}

	//accesing the data from stdin to write into memory

	memcpy((char *)map, "hello\n", 6);
      
	printf("Enter the data to write into shared memory : \n");                  
                                                                                
    if(NULL == fgets(buf, MAX, stdin)){                                         
        perror("accessing the data from stdin failed ....! \n");                
    }                                                                           
                                                                                
    //writing data into memory                                                  
                                                                                
    //strcpy((char *)map, buf);                                                   
	memcpy((char *)map, buf, (strlen(buf) - 1));      
                                                                          
    if(-1 == close(shmd)){                                                      
        errno_abort("closing shared memory session failed \n");                 
    }         

	//releasing the lock for semaphore (incrementing semaphore value)
                                             
    if(-1 == sem_post(sem)){                                                    
        errno_abort("Semaphore unlocking failed ....! \n");                     
    }  	

	//closing the semaphore
	if(-1 == sem_close(sem)){
		errno_abort("Closing semaphore failed....! \n");
	}

	return 0;
}
