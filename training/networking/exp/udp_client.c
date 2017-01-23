#include <sys/socket.h>
#include <netdb.h>
#include "errors.h"
#include <netinet/in.h>

#define MAX 80

int main(void)
{
	int sockd;
	struct sockaddr_in *my_addr;
	void *buf = NULL;
	int len = 0;


	/*creating the socket*/

	if(-1 == (sockd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))){
		errno_abort("socket creation in server failed .... ! \n");
	}

	/*allocating memory for getting attributes of server & client*/

	if(NULL == (my_addr = malloc(sizeof(struct sockaddr_in)))){                                
        perror("allocating memory for getting server attributes dynamically - failed \n");
        exit(EXIT_FAILURE);
    }

	if(NULL == (my_addr = malloc(sizeof(my_addr)))){
        perror("allocating memory for getting client attributes dynamically - failed \n");
        exit(EXIT_FAILURE);
    }

	my_addr->sin_family = AF_INET;
	my_addr->sin_port = 6452; //htons();
	my_addr->sin_addr.s_addr = inet_addr("172.16.5.56");

	len = (sizeof(my_addr));
	
	/*allocating memory to store the information received from client*/

	if(NULL == ( buf = malloc(MAX) ) ){
		perror("allocating memory for buffer dynamically - failed \n");
		exit(EXIT_FAILURE);
	}		
	
	/*accessing the data to be sent from client */

	printf("Enter the data to be sent from client : \n");                       
                                                                                
    if(NULL == (buf = fgets(buf, MAX, stdin))){                                 
        perror("Entering the data to be sent from server to client failed \n"); 
        exit(EXIT_FAILURE);                                                     
    }  

	/*seding the data from server to client*/

	if(-1 == sendto(sockd, buf, MAX, 0, (struct sockaddr *)my_addr, (sizeof(my_addr)) ) ){
		errno_abort("Sending information to client failed...! \n");
	}
	
	free(buf);//releasing the memory
	buf = NULL;

	/*waiting untill request sent from client */

	if(-1 == recvfrom(sockd, buf, MAX, 0, (struct sockaddr *)my_addr, &len ) ){
		errno_abort("receiving request in server failed...! \n");
	}

	printf("%s \n", (char*)buf);

	free(buf);//releasing the memory
	free(my_addr);
	my_addr = NULL; 
	buf = NULL;

	/*closing the socket/session after transaction */

	if(-1 == close(sockd)){
		errno_abort("closing the session/socket in serverfailed..! \n");
	}

	return 0;
}
