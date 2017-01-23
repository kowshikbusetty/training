#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main( void )
{
	mqd_t mq;
	char *s_buf = NULL;
	char *r_buf = NULL;
	struct mq_attr *attr;

	
	/*allocating memory for storing the attributes*/	

	if(NULL == (attr = (struct mq_attr *) malloc (sizeof(struct mq_attr)))) {
		perror("malloc failed");
		exit(1);
	}
	
	//assigning attributes , used to pass as attributes while creating a mq

	attr -> mq_flags = 0;
	attr -> mq_maxmsg = 4;
	attr -> mq_msgsize = 512;
	attr -> mq_curmsgs = 0;

	/*creating & opening msg_queue*/
	
	if(-1 == (mq = mq_open("/my_mq", O_RDWR | O_CREAT, 0666, attr))) {
		perror("message queue open failed");
		exit(1);
	}

	/*getting attributes for mq*/

	if(-1 == mq_getattr(mq, attr)) {
		perror("mq get attr failed");
		exit(1);
	}

	//printing the atttributes

	printf("queue size : %ld, msg size :  %ld\n", attr -> mq_maxmsg, 
														attr -> mq_msgsize);


	/*allocating memory for sending & receiving buffer*/

	if(NULL == (s_buf = (char *) malloc (sizeof(char)))) {
		perror("malloc failed");
		exit(1);
	}

	if(NULL == (r_buf = (char *) malloc (sizeof(char)))) {
		perror("malloc failed");
		exit(1);
	}


	while(1) {
	
		/* accessing the data inorder to send */

		if(NULL == (fgets(s_buf, (attr -> mq_msgsize), stdin))) {
			perror("fgets failed");
			exit(1);
		}

		//making last ending '\n' character as '\0'

		*(s_buf + strlen(s_buf) - 1) = '\0';
	
		//sending the data to queue

		if(-1 == (mq_send(mq, s_buf, (attr -> mq_msgsize), 0))) {
			perror("message send failed");
			exit(1);
		}
	
		//receiving data from queue
	
		if(-1 == (mq_receive(mq, r_buf, (attr -> mq_msgsize) + 1, 0))) {
			perror("message recieve failed");
			exit(1);
		}
	
		printf("\nReceived data from jerry : %s\n", r_buf);

	}/*while end*/

	if(-1 == (mq_close(mq))) { //closing the session
		perror("mq close failed");
		exit(1);
	}

	free(s_buf);//releasing the memory used by sending buffer
	s_buf = NULL;

	free(r_buf);//releasing the memory used by receiving buffer
	r_buf = NULL;

	free(attr);//releasing the memory used for holding attributes
	attr = NULL;

	return 0;
}
