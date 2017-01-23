#include <sys/stat.h>                                                           
#include <fcntl.h>                                                              
#include <sys/syscall.h>                                                        
#include"errors.h"
#include <pthread.h>
 
void *thread(void *);

int main(void)                                                                  
{                                                                               
    pthread_t tid;                                                              
    int status;                                                                 
                                                                                
    printf("pid is %d\n", getpid());                                            
                                                                                
    if(0 != (status = pthread_create(&tid, NULL, thread, NULL))) {
            err_abort(status, "pthread_create() failed");                       
    }
                                                                       
    printf("In thread group leader \n");
                                                                                
    pthread_exit(NULL);                                                         
    return 0;                                                                   
}
                                                                               
void *thread(void *dummy)
{                                                                               
    pid_t pid;                                                                  
    pid = syscall(SYS_gettid);

	printf("Thread pid is %d\n", pid);
       
	if((pid = fork()) > 0) {
		printf("Parent process\n");
	} else if(pid == 0){
		printf("Child process\n");
	} else {
		printf("fork() failed");
	}

    pthread_exit(NULL);                                                         
}                                                                               
