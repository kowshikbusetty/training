#include "../errors.h"
#include <pthread.h>
#include <time.h>

struct input {	//to hold the alarm request
	int sec;
	int in;
	char msg[64];
	struct input *next;
};

struct security {		//used for locking the resource
	pthread_mutex_t res;
	pthread_cond_t cond1;
	pthread_cond_t cond2;
	struct input *head;
};
void dequeue();
void enqueue(struct input *);
void *alrm(void *);


struct security secure = {
	.res = PTHREAD_MUTEX_INITIALIZER, 
	.cond1 = PTHREAD_COND_INITIALIZER, 
	.cond2 = PTHREAD_COND_INITIALIZER, 
	.head = NULL
};

int main( void )
{
	char line[120];//used for holding the alarm request
	pthread_t tid;//used for creating the thread
	int status;//used for verifying the status of predefined functions from pthread
	struct input *cur;//used for inserting new node
	time_t i;

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
			
			if(NULL == (cur = (struct input *) malloc (sizeof(struct input)))) {
				errno_abort("malloc failed\n");
				exit(1);
			}
			
			cur -> next = NULL;

			if(sscanf(line, "%d %64[^\n]", &(cur -> in), cur -> msg) < 2) {
				fprintf(stderr, "Bad command \n");
				free(cur);
				continue;
			} 
				cur -> sec = (cur -> in) + time(&i);

			if(0 != (status = pthread_mutex_lock(&(secure.res)))) {//acquire the lock
				err_abort(status, "lock failed");
			} else {
				enqueue(cur);	//insert the request in queue
				if(0 != (status = pthread_mutex_unlock(&(secure.res)))) {
					err_abort(status, "unlock failed");
				}//releasing the lock
			}
		}
	}//while(1) end 

	return 0;

}

void enqueue(struct input * cur)
{
	struct input *p = NULL;//used for traversing
	int status;//used for verifying the status of predefined functions from pthread

	if(secure.head == NULL) {	//queue is empty
		secure.head = cur;
		if(0 != (status = pthread_cond_signal(&(secure.cond1)))) {
			err_abort(status, "signal failed");
		}
		return;
	} else {
		p = secure.head;

		if (secure.head->sec > cur->sec){
						//if new node is lessthan head node
			cur->next = secure.head;
			secure.head = cur;
			if(0 != (status = pthread_cond_signal(&(secure.cond2)))) {      
				err_abort(status, "signal failed");                         
			} 
			return;	
		}

		while((p->next) && (cur->sec > p->next->sec))//traversing upto position
			p = p->next;

		cur->next = p->next;                                                
		p->next = cur;                                                      
		return;
	}
}

void *alrm(void *l)
{
	time_t i;	
	int status;
	struct input *temp = NULL;
	struct timespec *abs = NULL;
	abs = (struct timespec *) malloc(sizeof(struct timespec));	

	if(0 != (status = pthread_mutex_lock(&(secure.res)))) {                       
        err_abort(status, "lock failed");                                       
	}  	

	while(1) {

		if(secure.head == NULL) {
			if(0 != (status = pthread_cond_wait(&(secure.cond1), &(secure.res)))) {
				err_abort(status, "wait failed");
			}
		}

		abs -> tv_sec = (secure.head -> sec);
		abs -> tv_nsec = 0;

		status = pthread_cond_timedwait(&(secure.cond2), &(secure.res),	abs);

		if(status == ETIMEDOUT) {
			printf("time: %lu:(%d) %s\n", time(&i), secure.head -> in, secure.head -> msg);
			temp = secure.head;
			secure.head = secure.head->next;
			free(temp);

		} else if(status == 0) {
			
		} else {
			err_abort(status, "timed wait failed");
		}

	}//while(1) end

	return;
}
