#include <stdio.h>
#include <stdlib.h>
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
	struct sockaddr_in my_addr;
	struct sockaddr_in client_addr;
	socklen_t size = sizeof(client_addr);
	int boundary;

	if( -1 == (sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))) {
		error_message(session creation failed);
	}
	
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(45678);
	my_addr.sin_addr.s_addr = inet_addr("172.16.5.31");

	if ( -1 == bind(sockfd, (struct sockaddr *) &my_addr, sizeof(my_addr))) {
		error_message(binding failed)
	}
	
	while(1) {
		printf("waiting for the clinet:\n");
//		boundary = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&client_addr, &size);
		boundary = recvfrom(sockfd, buf, sizeof(buf), 0, NULL, NULL);
		if (boundary == 0) {
			error_message(creating receivering end in server failed);
		}
		buf[boundary] = '\0';

		printf("received message from the client:%s\n", buf);
		printf("port : %d\n", ntohs(client_addr.sin_port));
		printf("ip addr : %u\n", ntohl(client_addr.sin_addr.s_addr));


		printf("enter the message to be sent:\n");

		if (NULL == fgets(buf, MAX, stdin)) {
			error_message(fgets failed);
		}

		if ( -1 == sendto(sockfd, (char *)buf, sizeof(buf), 0, (const struct sockaddr*) &client_addr, (socklen_t)sizeof(client_addr))) {			
			error_message(send to failed\n);
		}

	}
	close(sockfd);
	return 0;

}
