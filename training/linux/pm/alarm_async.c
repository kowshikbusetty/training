#include "errors.h"

int status;

//assignment 10: using fork
#if 0
int main( void )
{
	int seconds;
	char line[120];
	char message[64];
	pid_t pid; // process ID variable
//	int status;
	
	while(1) {
        do{
            status = waitpid(-1, NULL, WNOHANG);   
            if(status == -1)
                break;

        }while(status != 0);


		printf("\nAlarm>");
		if(fgets(line, sizeof(line), stdin) == NULL) exit(0);

		if(strlen(line) <= 1) continue;
		//if given string length is less than = 1 it again prompts for input

		pid = fork ();

		if (pid > 0){
//			waitpid(-1, &status, WNOHANG);
				continue;
		}else if (pid == 0) {
			// child process where sleep takes given input seconds as alarm
			if(sscanf(line, "%d %64[^\n]", &seconds, message) < 2) {
				fprintf(stderr, "Bad command \n");
			} else {
				sleep(seconds);
				printf("(%d) %s \n", seconds, message);
			}
			exit (0);//after printing child will exit
		} else {
			perror ("fork failed");
		}
	}

}
#endif

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
