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
	int ptr;
//    char *hostname = argv[1];
    int i;
	int sock_desc;
	char req[100];
    char ip[100];
	char buf[20];
    struct hostent *he;
    struct in_addr **addr_list;
    struct sockaddr_in sv_addr;                                                 

    if (argc <2) {
        printf("Please provide a hostname to resolve\n");
        exit(1);
    }
 
	if (-1 == (sock_desc = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))) {    
		errno_abort ("Assigning a session failed\n");                       
    }                                                                       
        
    if ( (he = gethostbyname(argv[1]/*hostname*/)) == NULL ) { // get the host info
        perror("gethostbyname");
        return 1;
    }
 
    addr_list = (struct in_addr **) he -> h_addr_list;
     
    for(i = 0; addr_list[i] != NULL; i++) {           //Return the first one;
        strcpy(ip , inet_ntoa(*addr_list[i]) );
		break;
    }
	
     
    printf("%s resolved to %s\n", argv[1]/*hostname*/, ip);

    sv_addr.sin_family = AF_INET;                                           
    sv_addr.sin_port = htons (80);                               
    sv_addr.sin_addr.s_addr = inet_addr(ip);                           
    
    ptr = sizeof(struct sockaddr);                                          


    if (-1 == connect(sock_desc, (struct sockaddr *)&sv_addr, ptr)) {       
		errno_abort("Y R U Not able to connect \n");                        
    }             

	strcpy(req, "GET ");   
	strcat(req, " HTTP/1.1\r\n");                   
	strcat(req, argv[1]/*hostname*/); 

	printf("req = %s\n", req);

	if (-1 == send(sock_desc, req, MAX, 0)) {                             
		errno_abort("Sending data to buffer failed\n");                 
	}                                    

//	while (1) {
		if (-1 == recv(sock_desc, buf, MAX, 0)) {                              
    		errno_abort ("Receiving data from buffer failed\n");            
	    }   
		printf("%s\n", buf);                                                       
//	}         
		
                               
	if (-1 == close (sock_desc)) {                                  
    	errno_abort ("Closing session failed\n");                   
	}                                                               
                    
	return 0;    
}
