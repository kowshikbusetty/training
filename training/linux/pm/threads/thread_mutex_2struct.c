#include <pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"errors.h"


struct input{		//to hold linked list
	unsigned seconds;                                                     
    char message[64];                                                           
    struct input *next;                                                         
};

struct queue {
	pthread_cond_t cond;
	pthread_mutex_t resource_lock;	
	struct input *head;
};

struct queue q = {	//intializing the resource with mutex & head node with null
	.cond = PTHREAD_COND_INITIALIZER,
	.resource_lock = PTHREAD_MUTEX_INITIALIZER, 
	.head = NULL
};

void threadfunc (char *);

int ret;	//used for holding the status for locking & unlocking the resources

struct input * insert(struct input * cur)
{
	struct input *temp = NULL;

	if(!q.head)
		q.head = cur;

	else {                                                               
		temp = q.head;
		if (q.head->seconds > cur->seconds){
			cur->next = q.head;
			q.head = cur;
			return q.head;
		}

		while((temp->next) && (cur->seconds > temp->next->seconds))
			temp = temp->next;

		 cur->next = temp->next;                                         
		 temp->next = cur;                                                   
	} 
	return q.head;
}

int main (void)
{
	char line[128];
	pthread_t thread;
	struct input *cur = NULL;
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

	/*	if(0 != (ret = pthread_mutex_lock(&q.resource_lock))){
			err_abort(ret, "lock failed\n");
		}else{*/
			q.head = insert(cur);	
			/*if(0 != (pthread_mutex_unlock(&q.resource_lock))){
				err_abort(ret, "unlock failed\n");
			}
		}*/
	}
	return 0;
}

void threadfunc (char *l)
{

	struct input *cur = NULL;
	while(1){

		while(!q.head)
			sleep(1);

		if(0 != (ret = pthread_mutex_lock(&(q.resource_lock)))){
			err_abort(ret, "lock failed\n");
		}else{

			while(time(NULL) != q.head->seconds)
				sleep(1);

			printf("%u %lu %s\n",q.head->seconds,time(NULL),q.head->message);

			if(0 != (pthread_mutex_unlock(&(q.resource_lock)))){
				err_abort(ret, "unlock failed\n");
			}

			cur = q.head;
			q.head = q.head->next;
			free(cur);
		}

	}
	
}

