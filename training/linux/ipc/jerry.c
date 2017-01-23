#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main( void )
{
	mqd_t mq;
	char *s_buff = NULL;
	char *r_buff = NULL;
	struct mq_attr *attr;


	/*allocating memory for storing the attributes*/ 

	if(NULL == (attr = (struct mq_attr *) malloc (sizeof(struct mq_attr)))) {
		perror("malloc failed");
		exit(1);
	}

	/*opening msg_queue*/

	if(-1 == (mq = mq_open("/my_mq", O_RDWR))) {
		perror("message queue open failed");
		exit(1);
	}

	/*getting attributes for mq*/

	if(-1 == mq_getattr(mq, attr)) {
		perror("mq get attr failed");
		exit(1);
	}

	 //printing the atttributes 

	printf("%ld %ld\n", attr -> mq_maxmsg, attr -> mq_msgsize);

	/*allocating memory for sending & receiving buffer*/ 

	if(NULL == (s_buff = (char *) malloc (sizeof(char)))) {
		perror("malloc failed");
		exit(1);
	}

	if(NULL == (r_buff = (char *) malloc (sizeof(char)))) {
		perror("malloc failed");
		exit(1);
	}

	while(1) {

		printf("Received data : ");
	
		//receiving data from queue 

		if(-1 == (mq_receive(mq, r_buff, (attr -> mq_msgsize) + 1, 0))) {
			perror("message recieve failed");
			exit(1);
		}
	
		printf("%s\n", r_buff);

		/* accessing the data inorder to send */

		if(NULL == (fgets(s_buff, (attr -> mq_msgsize), stdin))) {
			perror("fgets failed");
			exit(1);
		}
		
		//making last ending '\n' character as '\0' 

		*(s_buff + strlen(s_buff) - 1) = '\0';

		 //sending the data to queue

		if(-1 == (mq_send(mq, s_buff, (attr -> mq_msgsize), 0))) {
			perror("message send failed");
			exit(1);
		}
	}/*while end*/

	if(-1 == (mq_close(mq))) {	//closing the session  
		perror("mq close failed");
		exit(1);
	}

	free(s_buff);//releasing the memory used by sending buffer 
	s_buff = NULL;

	free(r_buff);//releasing the memory used by receiving buffer
	r_buff = NULL;

	free(attr);//releasing the memory used for holding attributes
	attr = NULL;

	if(-1 == mq_unlink("/my_mq")) {//removing the mq
		perror("queue deletion failed");
		exit(1);
	}

	return 0;
}
