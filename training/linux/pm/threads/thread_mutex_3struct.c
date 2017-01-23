#include "errors.h"
#include <pthread.h>
#include <time.h>

void dequeue();
void enqueue(char []);
void *alrm(void *);

struct input {
	int sec;
	int in;
	char msg[64];
	struct input *next;
};

struct security {
	pthread_mutex_t res;
	pthread_cond_t cond1;
	pthread_cond_t cond2;
	struct input *head;
};

struct security door = {
	.res = PTHREAD_MUTEX_INITIALIZER, 
	.cond1 = PTHREAD_COND_INITIALIZER, 
	.cond2 = PTHREAD_COND_INITIALIZER, 
	.head = NULL
};

int main( void )
{
	char line[120];
	pthread_t tid;
	int status;

	if(0 != (status = pthread_create(&tid, NULL, &alrm, NULL))) {
		err_abort(status, "thread creation failed");
	}
	
	while(1) {
		printf("Alarm > ");
		if(fgets(line, sizeof(line), stdin) == NULL) {
			errno_abort("fgets failed");
		}
		*(line + strlen(line) - 1) = '\0';

		if(strlen(line) < 1) {
			continue;
		} else {
			if(0 != (status = pthread_mutex_lock(&(door.res)))) {
				err_abort(status, "lock failed");
			} else {
				enqueue(line);
				if(0 != (status = pthread_mutex_unlock(&(door.res)))) {
					err_abort(status, "unlock failed");
				}
			}
		}
	} // end of while (1)

}

void enqueue(char str[])
{
	struct input *temp;
	struct input *p = NULL;
	time_t i;
	struct input *gp = NULL;
	int status;
	
	if(NULL == (temp = (struct input *) malloc (sizeof(struct input)))) {
		errno_abort("malloc failed\n");
		exit(1);
	}

	if(sscanf(str, "%d %64[^\n]", &(temp -> in), temp -> msg) < 2) {
		fprintf(stderr, "Bad command \n");
	} else {
		temp -> sec = (temp -> in) + time(&i);
		temp -> next = NULL;

		if(door.head == NULL) {
			door.head = temp;
			if(0 != (status = pthread_cond_signal(&(door.cond1)))) {
				err_abort(status, "pthread_cond_signal failed");
			}
		} else {
			p = door.head;
			while((p != NULL) && ((p -> sec) < (temp -> sec))) {
				gp = p;
				p = p -> next;
			}
			if(p == NULL) {
				gp -> next = temp;
			} else if(gp == NULL) {
				temp -> next = door.head;
				door.head = temp;
				if(0 != (status = pthread_cond_signal(&(door.cond2)))) {
					err_abort(status, "pthread_cond_signal_failed");
				}
			} else {
				temp -> next = gp -> next;
				gp -> next = temp;
			}
		}
	}
}

void dequeue()
{
	struct input *p = door.head;

	door.head = door.head -> next;
	free(p);
}

void *alrm(void *l)
{
	time_t i;	
	int status;
	struct input *p = NULL;
	struct timespec *abs = NULL;

	if(0 != (status = pthread_mutex_lock(&(door.res)))) {
		err_abort(status, "lock failed");
	}
 	
	while(1) {

			if(door.head == NULL) {
				if(0 != (status = pthread_cond_wait(&(door.cond1), &(door.res)))) {
					err_abort(status, "wait failed");
				}
			}

			p = door.head;

			abs = (struct timespec *) malloc(sizeof(struct timespec));	
			abs -> tv_sec = (p -> sec);
			abs -> tv_nsec = 0;
			status = pthread_cond_timedwait(&(door.cond2), &(door.res),	abs);
	
			if(status == ETIMEDOUT) {
				printf("time: %lu:(%d) %s\n", time(&i), p -> in, p -> msg);
				dequeue();
		
			} else if(status == 0) {
				
			} else {
				err_abort(status, "timed wait failed");
			}
#if 0
			if(0 != (status = pthread_mutex_unlock(&(door.res)))) {
					err_abort(status, "unlock failed");
				}
#endif

	}

	return NULL;
}
