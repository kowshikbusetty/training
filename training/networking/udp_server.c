#include <sys/socket.h>
#include "errors.h"
#include <netinet/in.h>

#define MAX 80

int main(void)
{
	int sockd; //used for holding the session of socket
	struct sockaddr_in my_addr;//used for holding the attributes of socket
	void *buf = NULL;//used for holding the data
	int len = 0;//used for holding the size of the above declared structure


	/*creating the socket*/

	if(-1 == (sockd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))){
		errno_abort("socket creation in server failed .... ! \n");
	}

	//assigning the i/p address, port number & network family for the structure 

	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(1234);
	my_addr.sin_addr.s_addr = inet_addr("172.16.5.56"); //htonl();

	len = (sizeof(my_addr));

	/* identifying the socket's ip address & port number */

	if(-1 == bind(sockd, (struct sockaddr *)&my_addr, sizeof(my_addr))){
		errno_abort("binding failed...! \n");
	}

	/*allocating memory to store the information received from client*/

	if(NULL == ( buf = malloc(MAX) ) ){
		perror("allocating memory for buffer dynamically - failed \n");
		exit(EXIT_FAILURE);
	}		

	while(1){

		/*waiting untill request sent from client */

		if(-1 == recvfrom(sockd, buf, MAX, 0, (struct sockaddr *)&my_addr,
																	 &len ) ){

			errno_abort("receiving request in server failed...! \n");
		}

		printf("%s \n", (char *)buf);

		/*Accessing to be sent from server */

		printf("Enter the data : \t");

		if(NULL == (buf = fgets(buf, MAX, stdin))){
			perror("Entering the data failed \n");
			exit(EXIT_FAILURE);
		}

		/*seding the data from server to client*/

		if(-1 == sendto(sockd, buf, MAX, 0, (struct sockaddr *)&my_addr,
														 (sizeof(my_addr)) ) ){

			errno_abort("Sending information to client failed...! \n");
		}
		
	}/*while end*/

	free(buf);//releasing the memory
	buf = NULL;

	/*closing the socket/session after transaction */

	if(-1 == close(sockd)){
		errno_abort("closing the session/socket in serverfailed..! \n");
	}

	return 0;
}
