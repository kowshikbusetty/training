#include "errors.h"
#include <string.h>

struct node {
    char info[64];
	int seconds;
    struct node *link;
};

struct node *start = NULL;
struct node * p = NULL;

int status;

void ins_end (struct node * node)
{
    if (start == NULL){
        start = node;
    }else {
		p = start;

        while (p -> link != NULL){
            p = p -> link;
        }
        p -> link = node;
    }
}

char line[128];

#include <pthread.h>

void threadfunc (void);

int main ()
{
	char line[128];
	pthread_t thread;
	char message[64];
	int sec;
	struct node * temp = NULL;

	printf ("in main, pid is : %d \n", getpid());
	
	while (1) {
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
		temp -> seconds = sec;
		temp -> link = NULL;

		if(!start){
			ins_end (temp);

			if (0 < pthread_create(&thread, NULL, (void *) threadfunc, NULL)) {
				perror ("thread creation failed\n");
				exit(0);
			}
		}else{
			ins_end (temp);
		}
	}
	
	return 0;
}

void threadfunc (void)
{
	struct node *temp = NULL;

	while(start){
		sleep(start -> seconds);
		printf(" (%d) %s\n", start -> seconds, start -> info);
		temp = start;
		start = start -> link;
		free(temp);
	}
	pthread_detach(pthread_self());
}
