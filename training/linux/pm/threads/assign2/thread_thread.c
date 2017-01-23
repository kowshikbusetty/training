#include <sys/stat.h>                                                           
#include <fcntl.h>                                                              
#include <sys/syscall.h>                                                        
#include <pthread.h>
#include"errors.h"

void *thread_2(void *);
void *thread_1(void *);

int main(void)                                                                  
{                                                                               
    pthread_t tid;                                                              
    int status;                                                                 
                                                                                
    printf("pid in thread group leader:  %d\n", getpid());
                                                                                
    if(0 != (status = pthread_create(&tid, NULL, thread_1, NULL))) {
            err_abort(status, "pthread_create() failed");                       
        }                                                                       
    printf("In thread group leader \n");
                                                                                
    pthread_exit(NULL);                                                         
    return 0;                                                                   
}  
void *thread_2(void *dummy)
{                                                                               
    pid_t pid;                                                                  
    pid = syscall(SYS_gettid);

    printf("thread_2 pid is %d\n", pid);
                                  
   	pthread_exit(NULL);                                                                          
                                                                                
}                                                                   
void *thread_1(void *dummy)
{                                                                               
	int status;
	pthread_t t_tid;

    printf("thread_1 pid is %d\n", getpid());                                     

	if(0 != (status = pthread_create(&t_tid, NULL, thread_2, NULL))) {
            err_abort(status, "pthread_create() failed");                       
        }                                                        
   	pthread_exit(NULL);
}              

