#include <signal.h>
#include <fcntl.h>
#include "errors.h"
#include <mqueue.h>

#define MAX 80	//used for array index

#if 1
int main(void)
{
	pid_t pid;	//used for holding process Id's of a processes
	mqd_t mqdes;	//used as descriptor for message_queue
	char buf[MAX];	//used for trasvering the data
	char buf2[MAX];	//used for receiving the data
	struct mq_attr *mqattr;                                                         

	if(-1 == (mqdes = mq_open("/msgqueue", O_RDWR | O_CREAT, 0666, NULL))){	//creating (opening) queue
		errno_abort("queue is not opened ...! \n");
	}	

    if(NULL == (mqattr = (struct mq_attr *)malloc(sizeof(struct mq_attr)))){
		perror("malloc ... failed");
		exit(1);
	}

	mq_getattr(mqdes, mqattr);

	pid = fork();	//creating child process

	if (pid > 0){	//parent sends (trasfers) data into queue
	
		printf("Send the data into queue : \n");

		//accessing the data which has to transfer through queue

		if(NULL == fgets(buf, MAX, stdin)){
			perror("fgets failed \n");
			exit(1);
		}
	
		//sending the data into queue
		if(-1 == mq_send(mqdes, buf, MAX, 1u)){
			errno_abort("Sending data into queue failed....! \n");
		}

		if (-1 == mq_close(mqdes)){	//closing session for sending the data
			errno_abort("Closing the session for queue failed after sending...! \n");
		}

	}else if(0 == pid){	//child reads (receives) data from queue

		//receiving the data from queue
		if(-1 == mq_receive(mqdes, buf2, mqattr->mq_msgsize, NULL)){
			errno_abort("Receiving from queue failed...! \n");
		}

		//printing the data received from queue
		printf("\nReceived data from queue :\n%s \n", buf2);
			
		if (-1 == mq_close(mqdes)){	//closing session for receiving the data
			errno_abort("Closing the session for queue failed after receiving...! \n");
		}
	
		//unlinking the shared memory

		if(-1 == mq_unlink("/msgqueue")) {
			errno_abort("unlink failed \n");
		}
	}else{
		errno_abort("Error: child creation failed using fork \n");
	}

	return 0;
} 
#endif
