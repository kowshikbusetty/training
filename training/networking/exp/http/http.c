#include<stdio.h> //printf
#include<string.h> //memset
#include<stdlib.h> //for exit(0);
#include<sys/socket.h>
#include<netdb.h> //hostent
#include<arpa/inet.h>
#include"errors.h" 
#define MAX 65536
 
int main(int argc , char *argv[])
{
	int len;//used for finding the size of structure
	int socd;//used for holding the descriptor for session/socket
	char req[100];//used for the request that has to
    char ip[100];
	char buf[MAX];
    struct hostent *he;
    struct in_addr **addr_list;
    struct sockaddr_in server_addr;                                                 

    if (argc < 2) {
        printf("Please provide a hostname to resolve\n");
        exit(1);
    }
 
	/* Creating the session/socket */
	if (-1 == (socd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))) {    
		errno_abort ("Assigning a session failed\n");                       
    }                                                                       
       
	/* Getting I/P address by using host name */ 
    if ( (he = gethostbyname(argv[1])) == NULL ) { // get the host info
        perror("gethostbyname failed ...!");
        return 1;
    }

	/* accessing addresses through structure */ 
    addr_list = (struct in_addr **) he -> h_addr_list;
     
    strcpy(ip , inet_ntoa(*addr_list[0]) );
     
    printf("%s resolved to %s\n", argv[1], ip);

	/* intialising the interface to structure */
    server_addr.sin_family = AF_INET;                                           
    server_addr.sin_port = htons (80);                               
    server_addr.sin_addr.s_addr = inet_addr(ip);                           
    
    len = sizeof(struct sockaddr);                                          

	/* connecting our socket with host/server */
    if (-1 == connect(socd, (struct sockaddr *)&server_addr, len)) {       
		errno_abort("Connecting to server failed \n");                        
    }             

	/* Creating format of http request */
	strcpy(req, "GET / HTTP/1.1\r\nHost: ");   
	strcat(req, argv[1]);
	strcat(req, "\r\n\r\n"); 

	printf("req = %s\n", req);

	/* Sending http request to the server */
	if (-1 == send(socd, req, MAX, 0)) {                             
		errno_abort("Sending data to server \n");                 
	}                                    

	/* Receiving http response from the server */

	do{

		if (-1 == recv(socd, buf, MAX, 0)) {                              
			errno_abort ("Receiving data from server to buffer failed \n");
		}
   
		printf("%s\n", buf);
       
	}while(buf != NULL);
                      
	/* Closing the session/socket */  
	if (-1 == close (socd)) {                                  
    	errno_abort ("Closing session failed\n");                   
	}                                                               
                    
	return 0;    
}
