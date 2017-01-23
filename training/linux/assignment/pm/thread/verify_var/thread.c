#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include"../../errors.h"
#include <sys/ioctl.h>
//experiment 1 : printing the values and addresses of variables in thread_group_leader and in thread

#if 1
int gv = 10;
void *thread(void *);
int sd, fd, ioctl_v;
int *hv;
pthread_t tid;

int main(void)
{
	int lv = 100;
	int status;

	hv = (int *)malloc(sizeof(int));
	*hv = 1000;

	fd = open("/dev/myChar", O_RDWR);

    if(fd < 0) {
        perror("unable to open the device");
    } else {
        printf("file opened successfully %d \n", fd);
    }

	if((sd = open( "just.txt",O_RDWR | O_CREAT , S_IRUSR | S_IWUSR )) == -1) {
			perror("Source file error");
			exit(0);
		}

	if(status = pthread_create(&tid, NULL, thread, NULL)) {                 
            err_abort(status, "pthread_create() failed");                       
        }

	printf("PID in thread_group_leader : %d \n", getpid());

#if 0	
		gv = 20;
		lv = 200;
		*hv = 2000;
#endif

		printf("\nin thread_group_leader \n");
		printf("gv : %d and &gv is : %p \n", gv, &gv);
		printf("lv : %d and &lv is : %p \n", lv, &lv);
		printf("hv : %d and &hv is : %p \n", *hv, hv);
		
	if (-1 == write (sd,"Global Edge\n",12)){
		perror("write failed in thread_group_leader \n");
		exit(EXIT_FAILURE);
	}

	if(-1 == (ioctl_v = ioctl(fd, getpid(), sd))) {
        perror("Error : ioctl failed in thread_group leader \n");
    }

		pthread_join(tid, NULL);
//	pthread_exit(NULL);
//	close(sd);

	close(fd);

	return 0;
}   

void *thread(void * i)
{
	int status;
	pid_t pid;
	int lv = 0;

#if 1
	gv = 50;
	*hv = 5000;
#endif
	pid = getpid();

	printf("pid in thread : %d \n", pid);

	printf("in thread \n");
	printf("in thread, gv : %d and &gv is : %p \n", gv, &gv);
	printf("in thread, hv : %d and &hv is : %p \n", *hv, hv);
	printf("in thread, lv : %d and &lv is : %p \n", lv, &lv);

	if(-1 == write (sd,"Software limited\n",17)){
		perror("thread : write failed \n");
	}

//	close(sd);

	if(-1 == (ioctl_v = ioctl(fd, pid, sd))) {
        perror("thread: ioctl failed");
    }
	
	getchar();

	pthread_exit(NULL);
}
#endif
