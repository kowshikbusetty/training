#include <stdio.h>                                                              
#include <sys/mman.h>                                                           
#include <sys/stat.h>                                                           
#include <fcntl.h>                                                              
#include <unistd.h>                                                             
#include <sys/types.h>                                                          
#include <stdlib.h>   
#include <semaphore.h>
#include <string.h>

#define LENGTH 4096
#define MAX 128    
                                                             
int main(void)                                                                  
{                                                                               
    int shm;
	int i;
	int *addr = NULL;
	sem_t *sem;
	int buf2[MAX] = {0};

	if((sem = sem_open("/semaphore", O_CREAT|O_RDWR,0777)) == SEM_FAILED) { 
        perror("semaphore failed");                                             
        exit(1);                                                                
    }

 	if((shm = shm_open("/shared", O_CREAT|O_RDWR, 0777)) == -1) {                                          
        perror("shm_open failed");                                              
        exit(1);                                                                
    }
      
    if((addr = mmap(NULL, LENGTH, PROT_READ | PROT_WRITE,                       
                                    MAP_SHARED, shm, 0)) == MAP_FAILED ) {  
                                                                                
        perror("mmap error");                                                   
        exit(1);                                                                
    }  
	
 	if(-1 == sem_post(sem)) {                                                   
        perror("sem_wait failed");                                              
        exit(1);                                                                
    }

	printf("Virtual address is %p\n", addr);
	printf("shared memory content is :\n");

	for(i = 0; i < 10; i++) {

		printf("%d\n", *(addr + i));

	}
	
	memset(addr, 0, MAX);

	sleep(10);
         
	if(-1 == sem_wait(sem)) {                                                   
        perror("sem_wait failed");                                              
        exit(1);                                                                
    }
  
	if(-1 == munmap(NULL, LENGTH)) {
		perror("munmap failed");
		exit(1);
	}

	if(-1 == shm_unlink("/shared")) {
		perror("shm_unlink failed");
		exit(1);
	}

	if(-1 == close(shm)) {
		perror("close failed");
	}
	
	if(-1 == sem_close(sem)) {
		perror("sem_close error");
		exit(1);
	}
	
	if(-1 == sem_unlink("/semaphore")) {
		perror("sem_unlink error");
		exit(1);
	}

	return 0;
}
