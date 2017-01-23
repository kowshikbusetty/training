#include "errors.h"
#include <string.h>

struct node {
    char info[128];
    struct node *link;
};

struct node *start = NULL;
struct node * temp = NULL;
struct node * p = NULL;

int count;

int status;

void ins_end (char * line)
{
    temp = (struct node*) malloc (sizeof (struct node));

    p = start;
    strcpy(temp -> info,line);
    temp -> link = NULL;

    if (start == NULL){
        start = temp;
        count++;
    }else {
        while (p -> link != NULL){
            p = p -> link;
        }
        p -> link = temp;
        count++;
    }
}

char line[128];

char * del_pos (int pos)
{

    p = start;

    if (count == 0){       
        printf ("\nNo requests present \n");
    } else if (pos == 0) {

        strcpy(line, start -> info);

        p = p -> link;
        free (start);
		start = p;
        count --;
    }
	return line;
}

#include <pthread.h>

void threadfunc (void);

int main ()
{
	char line[128];
	pthread_t thread;

	printf ("in main, pid is : %d \n", getpid());
	
	while (1) {

		printf("Alarm> ");
		if (fgets (line, sizeof (line), stdin) == NULL) {
			exit(0);
		}
		if (strlen (line) <= 1) 
			continue;

		ins_end (line);


		if (0 < pthread_create(&thread, NULL, (void *) threadfunc, NULL)) {
			perror ("thread creation failed\n");
			exit(0);
		}

	}
	
	return 0;
}

void threadfunc (void)
{
	char *line;

	line = del_pos(0);

	char message[64];
	int seconds;
	if (sscanf (line, "%d  %64[^\n]", &seconds, message ) < 2) {
		fprintf (stderr, "Bad command\n");
	} else {
		sleep(seconds);
		printf(" (%d) %s\n", seconds, message);
	}
	pthread_detach(pthread_self());
}
