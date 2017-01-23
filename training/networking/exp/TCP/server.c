#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/in.h>

#define MAX 150

#define error_message(message)\
		perror(#message);\
		exit(1);

int main()
{
	int sockfd = 0; //socket descriptor in server
	int new_sockfd = 0; //socket descriptor for active socket
	char buf[MAX]; //buf to recieve the message form the client
	struct sockaddr_in my_addr;
	struct sockaddr_in client_addr;
	socklen_t size = sizeof(client_addr);
	int boundary;

	if( -1 == (sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))) {
		error_message(session creation failed);
	}

	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(1041);
	my_addr.sin_addr.s_addr = inet_addr("172.16.5.54");
	
	if ( -1 == bind(sockfd, (struct sockaddr *) &my_addr, sizeof(my_addr))) {
		error_message(binding failed);
	}

	if (-1 == listen(sockfd, 5)) {
		error_message(listen failed\n);
	}


	
	printf("waiting for the clinet:\n");
	
	if (-1 == (new_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &size))) {
		error_message(accept is failed\n);
	}
	
/*	if(new_sockfd) {
		fork();
	}
*/	while(1) {
		printf("waiting for client response:\n");
		if (-1 == read(new_sockfd, buf, sizeof(buf))) {	
			error_message(read failed\n);
		}
	
		printf("received message from server:%s\n", buf);

		printf("enter the message to send the clinet\n");

		if(NULL == fgets(buf, MAX, stdin)) {	
			error_message(fgets failed\n);
		}
		buf[strlen(buf) - 1] = '\0';
	
		if(-1 == write(new_sockfd, buf, strlen(buf)) ) {
			error_message(write failed\n);
		}
	}

	close(new_sockfd);
	close(sockfd);
	return 0;

}
