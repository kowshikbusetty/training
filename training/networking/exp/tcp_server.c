#include <sys/socket.h>
#include "errors.h"
#include <netinet/in.h>

#define MAX 80

int main(void)
{
	int sockd;
	int accept_sockd;
	struct sockaddr_in my_addr;
	struct sockaddr_in client_addr;
	void *buf;
	int len = 0;
//	pid_t pid;


	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(1234);
	my_addr.sin_addr.s_addr = INADDR_ANY;//inet_addr("172.16.5.56"); //htonl();

	len = (sizeof(client_addr));

	/*creating the socket*/

	if(-1 == (sockd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))){
		errno_abort("socket creation in server failed .... ! \n");
	}

	/* identifying the socket's ip address & port number */

	if(-1 == bind(sockd, (struct sockaddr *)&my_addr, sizeof(my_addr))){
		errno_abort("binding failed...! \n");
	}

	/*waiting for connections from client on socket*/

	if(-1 == listen(sockd, 0)){
		errno_abort("waiting for connections from the clients failed \n");
	}

	/*accepts a connection on socket from queue */

	if(-1 == (accept_sockd = accept(sockd, (struct sockaddr *)&client_addr, &len) ) ){
		errno_abort("Connecton acceptance failed \n");
	}

	//creating a child process for servicing the connection

//	pid = fork();

//	if(pid > 0){//in parent
		
//		close(accept_sockd);

//	}else if(pid == 0){	//in child
	
//		close(sockd);	
	
		/*allocating memory to store the information */

		if(NULL == ( buf = malloc(MAX) ) ){
			perror("allocating memory for buffer dynamically - failed \n");
			exit(EXIT_FAILURE);
		}

		while(1){

			if(-1 == read(accept_sockd, buf, MAX)){
				errno_abort("receiving the data from client failed \n");	
			}

			printf("%s \n", (char *)buf);

			/*Accessing data to be sent from server */

			printf("Enter the data to be sent from server : \n");

			if(NULL == (buf = fgets(buf, MAX, stdin))){
				perror("Entering the data to be sent from server to client failed \n");
				exit(EXIT_FAILURE);
			}

			if(-1 == write(accept_sockd, buf, MAX)){
				errno_abort("Sending data to client failed \n");
			}

		}/*while end*/

		free(buf);//releasing the dynamically allocated memory
		buf = NULL;	
	
		/*closing the socket/session after transaction */

		if(-1 == close(sockd)){
			errno_abort("closing the session/socket in serverfailed..! \n");
		}

//	}else{
//		printf("fork failed \n");
//	}

	return 0;
}
