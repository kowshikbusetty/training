#include <sys/syscall.h>
#include "errors.h"
#define MAX 3

void *thread_start(void *arg);

pthread_t thr;

int main( void )
{	
	int my_thread;

	my_thread = pthread_create(&thr, NULL, &thread_start, NULL);
		
	if(my_thread != 0) {
	
		perror("thread creation failed.. \n");
	
	} else {
						
		printf("thread created succesfully.. \n");		

	}
		pthread_exit(NULL);
	
	return 0;
}

void *thread_start(void *arg)
{
	int seconds;
	char line[120];
	char message[64];
	pid_t pid;

	while(1) {
		printf("Alarm> ");
		if(fgets(line, sizeof(line), stdin) == NULL) exit(0);
		
		if(strlen(line) <= 1) continue;
		
		pid = fork();
		if(sscanf(line, "%d %64[^\n]", &seconds, message) < 2) {            
                fprintf(stderr, "Bad command \n");                              
            }      	
		if(pid > 0) {
			
		} else if(pid == 0) {

				sleep(seconds);
				printf("(%d) %s \n", seconds, message);
				exit(1);
		} else {

			perror("Fork failed \n");
		}

	}

return NULL;
}



















