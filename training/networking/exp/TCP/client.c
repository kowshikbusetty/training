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
	char buf[MAX]; //buf to recieve the message form the client
	struct sockaddr_in server_addr;
	socklen_t size = sizeof(server_addr);
	int boundary;

	if( -1 == (sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))) {
		error_message(session creation failed);
	}
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(1041);
	server_addr.sin_addr.s_addr = inet_addr("172.16.5.54");

	if (-1 == connect(sockfd, (struct sockaddr*) & server_addr, size)) {
		error_message(connect failed\n);
	}
	
//	while(1) {
	
		printf("enter the message:\n");

		if(NULL == fgets(buf, sizeof(buf), stdin)) {	
			error_message(fgets failed\n);
		}
		
		buf[strlen(buf) - 1] = '\0';
	
		if(-1 == write(sockfd, buf, sizeof(buf)) ) {
			error_message(write failed\n);
		}
		
		printf("waiting for the server reply:\n");	
		
		if (-1 == read(sockfd, buf, sizeof(buf))) {	
			error_message(read failed\n);
		}
	
		printf("received message:%s\n", buf);

	
//	}

	close(sockfd);
	return 0;

}
