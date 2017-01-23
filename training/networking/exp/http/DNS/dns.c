#include <stdio.h>                                                              
#include <stdlib.h>                                                             
#include <string.h>                                                             
#include <sys/types.h>                                                          
#include <sys/socket.h>                                                         
#include <netinet/in.h>
#include <netdb.h>

#define MAX 150                                                                 

#define error_message(message) \
		perror(#message);\
		exit(1);                                                                

int main(int argc, char *argv[])
{
	char *message = "POST /apikey=%s&command=%s HTTP/1.0\r\n\r\n"; 
	struct hostnet *server;
	int sockfd;
	char buf[4096];
	struct sockaddr_in server_addr;
	int total;
	int sent;
	int received;
	int bytes;
	char response[4096];

	if(argc != 2) {
		perror("invalid request from command line....!");

		exit(1);
	}

	printf("Your request:%s", argv[1]);

	if ( 0 > (sockfd = socket(AF_INET, SOCK_STREAM, 0))) {
		error_message(socket opening failed);
	}

	if (NULL == (server = (struct hostnet *) gethostbyname(argv[1]))) {
		error_message(no such host);
	}

	
	strcat(argv[1], message);
	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(80);
	server_addr.sin_addr.s_addr = inet_addr("172.16.2.8");

	if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
		error_message(ERROR connecting);
	}

	total = strlen(argv[1]);
	sent = 0;
	do {
		bytes = write(sockfd, argv[1] + sent, total - sent);
		
		if(bytes < 0) {
			error_message(writing failed);
		}
		if (bytes == 0) {
			break;
		}
		sent = sent + bytes;
	} while (sent < total);
	
	memset(response, 0, sizeof(response));
	total = sizeof(response) - 1;
	received = 0;
	do {
		bytes = read(sockfd, response+received, total - received);
		if(bytes < 0) {
			error_message(reading failed);
		}
		if (bytes == 0) {
			break;
		}
		received = received + bytes;
	} while (received < total);

	if(received == total)
			error_message(error storing complete response from the socket);

	close(sockfd);
	printf("response:\n%s\n", buf);

	return 0;
}
