#include <sys/socket.h>
#include <netdb.h>
#include "errors.h"
#include <netinet/in.h>

#define MAX 80	//used in allocating memory for buffer to hold the data

int main(void)
{
	int sockd;//used for holding the session
	struct sockaddr_in my_addr;//used to get the i/p address & port number
	void *buf = NULL;//used for holding the data
	int len = 0;//to hold the size of above declared structure


	/*creating the socket*/

	if(-1 == (sockd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))){
		errno_abort("socket creation in server failed .... ! \n");
	}
	
	//assigning the i/p address ,network type & port number to the structure

	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(1234);
	my_addr.sin_addr.s_addr = inet_addr("172.16.5.56");

	len = (sizeof(my_addr));
	
	/*allocating memory to store the information received from client*/

	if(NULL == ( buf = malloc(MAX) ) ){
		perror("allocating memory for buffer dynamically - failed \n");
		exit(EXIT_FAILURE);
	}	

	while(1){	
	
		/*accessing the data to be sent from client */

		printf("Enter the data : \t");                   

		if(NULL == (buf = fgets(buf, MAX, stdin))){                                 
			perror("Accessing the data failed \n"); 
			exit(EXIT_FAILURE);                                                     
		}  

		/*seding the data from server to client*/

		if(-1 == sendto(sockd, buf, MAX, 0, (struct sockaddr *)&my_addr,
														 (sizeof(my_addr)) ) ){

			errno_abort("Sending information to client failed...! \n");
		}
		
		/*waiting untill request sent from client */

		if(-1 == recvfrom(sockd, buf, MAX, 0, (struct sockaddr *)&my_addr,
																	 &len ) ){

			errno_abort("receiving request in server failed...! \n");
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
}//main function end
