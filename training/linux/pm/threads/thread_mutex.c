#include <pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"errors.h"


struct input{
	pthread_mutex_t resource_lock;
	unsigned seconds;                                                     
    char message[64];                                                           
    struct input *next;                                                         
                                                                                
}*head = NULL;

//struct input *head = {PTHREAD_MUTEX_INITIALIZER, 0, '\0', NULL}; 

void threadfunc (char *);

int ret;	//used for holding the status for locking & unlocking the resources

int main ()
{
	char line[128];
	pthread_t thread;
	struct input *cur = NULL;
	struct input *temp = NULL;
	int status;		
	printf ("in main, pid is : %d \n", getpid());

	if (0 < (status = pthread_create(&thread, NULL, (void *)threadfunc, NULL))) {
                err_abort(status, "thread creation failed\n");                  
	}
	
	while (1) {

		printf("Alarm> ");
		if (fgets (line, sizeof (line), stdin) == NULL) {
			exit(0);
		}
		if ((strlen (line) <= 1))
			continue; 
		
		cur = (struct input*)malloc(sizeof(struct input));                      
        cur->next = NULL;                  
		
		if (sscanf (line, "%u  %64[^\n]", &(cur->seconds), (cur->message) ) < 2) {                
        	printf("Bad command\n");  
			free(cur); 
			continue;
		}
		cur->seconds += time(NULL);

/*		if(0 != (ret = pthread_mutex_lock(&resource_lock))){
			err_abort(ret, "lock failed\n");
		}else{*/

			if(!head)
				head = cur;
			else {                                                               
				temp = head;
				if (head->seconds > cur->seconds){
					cur->next = head;
					head = cur;
					continue;
				}

				while((temp->next) && (cur->seconds > temp->next->seconds))
					temp = temp->next;

				 cur->next = temp->next;                                         
				 temp->next = cur;                                                   
			}           

//		}	

/*		if(0 != (pthread_mutex_unlock(&resource_lock))){
			err_abort(ret, "unlock failed\n");
		}*/

	}
	return 0;
}

void threadfunc (char *l)
{

	struct input *cur = NULL;
	while(1){

		while(!head)
			sleep(1);

		if(0 != (ret = pthread_mutex_lock(&head->resource_lock))){
			err_abort(ret, "lock failed\n");
		}else{

			while(time(NULL) != head->seconds)
				sleep(1);

			printf("%u %lu %s\n",head->seconds,time(NULL),head->message);
			cur = head;
			head = head->next;
			free(cur);
			}

		if(0 != (pthread_mutex_unlock(&head->resource_lock))){
			err_abort(ret, "unlock failed\n");
		}
	}
	
}

