#include <sys/socket.h>
#include <netdb.h>
#include "errors.h"
#include <netinet/in.h>

#define MAX 80

int main(void)
{
	int sockd;
	struct sockaddr_in my_addr;
	void *buf = NULL;
	int len = 0;


	/*creating the socket*/

	if(-1 == (sockd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))){
		errno_abort("socket creation in server failed .... ! \n");
	}

	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(1234);
	my_addr.sin_addr.s_addr = INADDR_ANY;//inet_addr("172.16.5.56");

	len = (sizeof(my_addr));
	
	/*sending request for connection*/

	if(-1 == connect(sockd, (struct sockaddr *)&my_addr, len)){
		errno_abort("sending request for connection failed \n")
	}

	/*allocating memory to store the information received from client*/

	if(NULL == ( buf = malloc(MAX) ) ){
		perror("allocating memory for buffer dynamically - failed \n");
		exit(EXIT_FAILURE);
	}		

	while(1){

		/*accessing the data to be sent from client */

		printf("Enter the data to be sent from client : \t");

		if(NULL == (buf = fgets(buf, MAX, stdin))){                                 
			perror("Entering the data to be sent from server to client failed \n"); 
			exit(EXIT_FAILURE);                                                     
		}  

		if(-1 == write(sockd, buf, MAX)){                            
                errno_abort("Sending data to client failed \n");                
        }

		if(-1 == read(sockd, buf, MAX)){                             
                errno_abort("receiving the data from client failed \n");        
        } 

		printf("%s \n", (char*)buf);

	}/*while end*/

	free(buf);//releasing the memory
	buf = NULL;

	/*closing the socket/session after transaction */

	if(-1 == close(sockd)){
		errno_abort("closing the session/socket in serverfailed..! \n");
	}

	return 0;
}
