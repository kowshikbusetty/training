#include "errors.h"
#include <pthread.h>
void *fun(void *a)
{
	int seconds;
	char line[120];
	char message[64];
	while(1) {
		printf("Alarm> ");
		if(fgets(line, sizeof(line), stdin) == NULL) exit(0);
		
		if(strlen(line) <= 1) continue;
		
		if(sscanf(line, "%d %64[^\n]", &seconds, message) < 2) {
			fprintf(stderr, "Bad command \n");
		} else {
			sleep(seconds);
			printf("(%d) %s \n", seconds, message);
		}
	break;	
	}
}

int main( void )
{
	pthread_t thread_id;
	int thread1, thread2;
//	int *retval = malloc(sizeof(int));

	printf("parent pid : %d \n", getpid());

	thread1 = pthread_create(&thread_id, NULL, fun, NULL);
	
	if(0 == thread1){
		printf("thread is created \n");
	}else if(thread1){
		perror("Error.Thread creation failed ..!");
		exit(1);
	}

	thread2 = pthread_create(&thread_id, NULL, fun, NULL);
	
	if(0 == thread2){
		printf("thread is created \n");
	}else if(thread2){
		perror("Error.Thread creation failed ..!");
		exit(1);
	}

	pthread_exit(NULL);

	return 0;
}
		
