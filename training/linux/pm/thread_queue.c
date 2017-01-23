#include <pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct input{                                                                   
    unsigned short seconds;                                                     
    char message[64];                                                           
    struct input *next;                                                         
                                                                                
}*first = NULL; 

void threadfunc (void);

int main ()
{
	char line[128];
	pthread_t thread;
	struct input *cur = NULL;
	struct input *last = NULL;
	printf ("in main, pid is : %d \n", getpid());
	
	while (1) {

		printf("Alarm> ");
		if (fgets (line, sizeof (line), stdin) == NULL) {
			exit(0);
		}
		if ((strlen (line) <= 1))
			continue; 
		
		cur = (struct input*)malloc(sizeof(struct input));                      
        cur->next = NULL;                  
		
		if (sscanf (line, "%hu  %64[^\n]", &(cur->seconds), (cur->message) ) < 2) {                
        	printf("Bad command\n");  
			free(cur); 
			continue;
		}
	
		if(!first){
			first = last = cur;
			if (0 < pthread_create(&thread, NULL, (void *)threadfunc, NULL)) {
				perror ("thread creation failed\n");
				exit(0);
			}
		}	
		else {                                                               
            last->next = cur;                                                   
            last = cur;                                                         
        }           
	}	
	return 0;
}

void threadfunc (void)
{
	struct input *cur = NULL;
	while(first){
		sleep(first->seconds);
		printf(" (%hu) %s\n", first->seconds, first->message);
		cur = first;
		first = first->next;
		free(cur);
	}
	pthread_detach(pthread_self());
}

