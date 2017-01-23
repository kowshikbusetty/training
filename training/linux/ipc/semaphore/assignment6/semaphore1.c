#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include<semaphore.h>
#include<time.h>
#include <sys/times.h>

#define LENGTH 4096
#define MAX 128

int main(void)
{
	int shmd;
	int i;
	int buf1[MAX] = {0.0};
	int *addr = NULL;
	sem_t *sem;

	if((shmd = shm_open("/shared", O_CREAT | O_RDWR, 0777)) == -1) {
		perror("shm_open failed"); 	
		exit(1);
	}

	if((sem = sem_open("/semaphore", O_CREAT|O_RDWR, 0777, 1)) == SEM_FAILED) {
		perror("semaphore failed");
		exit(1);
	}

	if(-1 == ftruncate(shmd, LENGTH)) { 
		perror("ftruncate failed");
		exit(1);
	}

	if((addr = mmap(NULL, LENGTH, PROT_READ | PROT_WRITE,
									MAP_SHARED, shmd, 0)) == MAP_FAILED ) {

		perror("mmap error");
		exit(1);
	}	

	if(-1 == sem_wait(sem)) {
		perror("sem_wait failed");
		exit(1);
	}

	printf("address is :%p\n", addr);

	printf("time is %ld\n",time(NULL));

	buf1[0] = 0;

	for(i = 1; i < 10; i++) {

		buf1[i] = time(NULL) % i;
	}

  	memcpy(addr, buf1, MAX);                                                                                                   
	printf("shared memory content is :\n");   
                                    
	for(i = 0; i < 10; i++) {

		printf("%d\n", buf1[i]);
	}
   	 
	sleep(10);

	printf("shared memory content is :\n");                                       
                                                                                
    for(i = 0; i < 10; i++) {                                                   
        
		printf("%d\n", *(addr + i));   
                                   
    }                                     
                                                                      
 	if(-1 == sem_close(sem)) {                                                  
        perror("sem_close error");                                              
        exit(1);                                                                
    }	

	return 0;	
} 
