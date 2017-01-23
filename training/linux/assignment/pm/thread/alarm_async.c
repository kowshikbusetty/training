#include "../errors.h"

int status;

#if 1
//assignment 11: using thread
#include <pthread.h>

void threadfunc (char *);

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
		if (0 < pthread_create(&thread, NULL, (void *) threadfunc, (void *) line)) {
			perror ("thread creation failed\n");
			exit(0);
		}

	}
	
	return 0;
}

void threadfunc (char *line)
{
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
#endif
