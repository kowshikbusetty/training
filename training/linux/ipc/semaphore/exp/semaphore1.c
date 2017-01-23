#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <semaphore.h>
#include "errors.h"
#include <pthread.h>

#define MAX 10
#define SIZE (4096)
#define LENGTH (80) 


int main(void)
{
	int shmd;   //used for opening the session for shared memory
	int * map = NULL;	//used for mapping the shared memory with virtual Address space
	sem_t *sem;	//used for creating semaphore
	int buf[MAX] = {0};
	off_t length;
	int i;

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
                                                                                
    if(MAP_FAILED == (map =(int *) mmap(NULL, LENGTH, PROT_READ | PROT_WRITE, MAP_SHARED, shmd, 0) ) ){
        errno_abort("mapping failed ....! \n");                                 
    }   	

	//acquiring the lock by semaphore(decrementing semaphore value)

	if(-1 == sem_wait(sem)){
		errno_abort("Semaphore locking failed....! \n");
	}

	//accessing the data to enter into file
	
	buf[0] = 0;

	for(i = 1; i < 10; i++){
		buf[i] = time(NULL) % i ;
	}
                                                                                
    //writing data into memory                                                  

	memcpy(map, buf, MAX);      
  
	for(i = 0; i< 10 ; i++)
		printf("%d \n", buf[i]);

	sleep(2);

	printf("shared memory content is :\n");                                                                                                                   
    for(i = 0; i < 10; i++) {
      	printf("%d\n", *(map + i));   
    }         
                                                                        
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
