#include "errors.h"
#include <string.h>
#include <pthread.h>

struct node {
	long int seconds;
    char info[64];
    struct node *link;
};

struct node *head= NULL;
struct node * p = NULL;

int status;

void ins_end (struct node * node)
{
	struct node * temp = NULL;

    if ((head == NULL)){
        head = node;
    }else {
		temp = head;
	
		if (head->seconds > node->seconds){
			node->link = head;
			head = node;
		return;
		}
		while((temp->link) && (node->seconds > temp->link->seconds))
			temp = temp->link;

		 node->link = temp->link;                                         
		 temp->link = node;                                                   
	}           	

}


void threadfunc (void);

int main (void)
{
	char line[128];
	pthread_t thread;
	char message[64];
	int sec;
	struct node * temp = NULL;
	pthread_mutex_t resource_lock;
	

	printf ("in main, pid is : %d \n", getpid());

	if (0 < pthread_create(&thread, NULL, (void *) threadfunc, NULL)) {
		perror ("thread creation failed\n");
		exit(0);
	}
	

	while (1) {
		pthread_mutex_lock(&resource_lock);	

	    temp = (struct node*) malloc (sizeof (struct node));

		printf("Alarm> ");
		if (fgets (line, sizeof (line), stdin) == NULL) {
			exit(0);
		}
		if (strlen (line) <= 1) 
			continue;
		if (sscanf (line, "%d  %64[^\n]", &sec, message ) < 2) {
			fprintf (stderr, "Bad command\n");
			continue;
		}

		strcpy(temp -> info, message);
		temp -> seconds = (sec + time(NULL));
		temp -> link = NULL;

		ins_end (temp);

		pthread_mutex_release(&resource_lock);

	}

	
	return 0;
}

void threadfunc (void)
{
	struct node *temp = NULL;

	while(1) {
		while(head) {
			sleep((head -> seconds) - time(NULL));
			printf(" (%ld) %s\n", head -> seconds, head -> info);
			temp = head;
			head = head -> link;
			free(temp);
		}
		sleep(1);
	}
}
