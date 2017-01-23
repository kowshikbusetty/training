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
	struct sockaddr_in server_addr, my_addr;
	socklen_t size = sizeof(server_addr);

	if( -1 == (sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))) {
		error_message(session creation failed);
	}
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(45678);
	server_addr.sin_addr.s_addr = inet_addr("172.16.5.31");

#if 0
	my_addr.sin_family = AF_INET;                                               
    my_addr.sin_port = htons(45000);                                            
    my_addr.sin_addr.s_addr = inet_addr("172.16.5.56");                         
                                                                                
    if ( -1 == bind(sockfd, (struct sockaddr *) &my_addr, sizeof(my_addr))) {   
        error_message(binding failed)                                           
    } 

#endif

	while(1) {
		
		printf("enter the message to be sent:\n");

		if (NULL == fgets(buf, MAX, stdin)) {
			error_message(fgets failed);
		}

		if ( -1 == sendto(sockfd, (char *)buf, sizeof(buf), 0, (const struct sockaddr*) &server_addr, (socklen_t)sizeof(server_addr))) {			
			error_message(send to failed\n);
		}
		
		printf("waiting for the server response:\n");
		if (-1 == recvfrom(sockfd, (char*)buf, sizeof(buf), 0, (struct sockaddr*)&server_addr, &size)) {
			error_message(creating receivering end in server failed);
		}

		printf("recived message from server:%s\n", buf);

	}

	close(sockfd);
	return 0;

}
