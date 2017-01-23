#include <stdio.h>                                                              
#include <pthread.h>                                                            
#include <stdlib.h>                                                             
                                                                                
int g_flag;

void *fun(void *a); 

int main(void)                                                                  
{                                                                               
    pthread_t thread;                                                           
    int thread_id;                                                              
                                                                                
    if(thread_id = pthread_create(&thread, NULL, fun, (void *)5)){
		perror("Error.Thread creation failed ..! ");                            
        exit(1);                                                                
    }                                                                           

	sleep(1);
	g_flag = 5;
                                                                                
    pthread_exit(NULL);                                                         
                                                                                
    return 0;                                                                   
}

void *fun(void *a)                                                              
{
	while(g_flag != 5){

	}

	printf("%d \n", g_flag);
}                         
