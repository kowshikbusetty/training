#include <stdio.h>
#include <sys/stat.h>                                                           
#include <fcntl.h>                                                              
#include <mqueue.h>                                                             
#include "../errors.h" 

int main (void) 
{
    mqd_t mq_desc;                                                              
    char name[10] = "/myqueue";                                                 
    char messag[10] = "Hello\n";                                                
    char ptr[10];                                                
    struct mq_attr *attr;                                                       
                                                                                
    if(-1 == (mq_desc = mq_open(name, O_RDWR | O_CREAT, 0666, NULL))) {        
        perror("msg creation failed\n");                                        
        mq_unlink(name);                                                        
    }

	printf("Sending message to P2:\n"); 

    if (-1 == mq_send(mq_desc, messag, 12, 1)) {                            
    	errno_abort("Sending message in to Message Queue Failed\n");        
    }                                                                       

	sleep(5);

    attr = (struct mq_attr *) malloc (sizeof(struct mq_attr));                  
    mq_getattr(mq_desc, attr);                                                  
                                                                                
    printf("Received message from P2:\n");                                      
    if (-1 == mq_receive (mq_desc, ptr, attr -> mq_msgsize, NULL)) {            
        errno_abort("receiving message in to Message Queue Failed\n");            
    }                                                                           
                                                                                
    printf("%s\n", ptr);                                                        
                                                                                
    if(-1 == mq_unlink(name)) {                                                 
        errno_abort("unlink failed");                                           
    }                                                                           

	free(attr);                                                                                
}


