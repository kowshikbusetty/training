#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//experiment 1 : printing the values and addresses of variables in parent and in child

#if 1
int gv = 10;
int main(void)
{
	int sd;
	int lv = 100;
	int *hv = (int *)malloc(sizeof(int));
	pid_t pid;
	*hv = 1000;


	printf("in main \n");
	printf("parents PID in main : %d \n", getpid());
	printf("in main, gv : %d and &gv is : %p \n", gv, &gv);
	printf("in main, lv : %d and &lv is : %p \n", lv, &lv);
	printf("in main, hv : %d and &hv is : %p \n", *hv, hv);
	
	if((sd = open( "just.txt",O_RDWR | O_CREAT , S_IRUSR | S_IWUSR )) == -1) {
			perror("Source file error");
			exit(0);
		}
	printf("In parent :%d \n", sd);

	pid = fork();

	if (pid > 0){
//		wait(1);
#if 0	
		gv = 20;
		lv = 200;
		*hv = 2000;
#endif

		printf("in parent \n");
		printf("parents PID : %d \n", pid);
		printf("in parent, gv : %d and &gv is : %p \n", gv, &gv);
		printf("in parent, lv : %d and &lv is : %p \n", lv, &lv);
		printf("in parent, hv : %d and &hv is : %p \n", *hv, hv);
		
		write (sd,"Global Edge\n",12);
		close(sd);

	}else if (pid == 0){
#if 1
//		sleep(1);
		gv = 50;
		lv = 500;
		*hv = 5000;
#endif

		printf("in child \n");
		printf("childs PID : %d \n", pid);
		printf("in child, gv : %d and &gv is : %p \n", gv, &gv);
		printf("in child, lv : %d and &lv is : %p \n", lv, &lv);
		printf("in child, hv : %d and &hv is : %p \n", *hv, hv);

		write (sd,"Software limited\n",17);
		close(sd);

	}else
		printf("fork error..... \n");

	return 0;
}
#endif
