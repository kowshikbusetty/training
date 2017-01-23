#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#if 0
int main(void)
{
	sprintf("in main \n");
	sprintf("parents PID : %d \n", getpid());
	
	pid_t pid = fork();

	sprintf("childs PID : %d \n", pid);

	if (pid){
		sprintf("in parent \n");
	}else {
		sprintf("in child \n");
	}

	
	return 0;
}
#endif

//experiment 2 : printing the values and addresses of variables in parent and in child

#if 1
int gv = 10;
int main(void)
{
	char *buf = NULL;
	int lv = 100;
	int *hv = (int *)malloc(sizeof(int));
	pid_t pid;
	*hv = 1000;

	buf = (char *)malloc(80);

	sprintf(buf, "parents PID : %d \n", getpid());
	write (1, buf, strlen(buf));

	pid = fork();
	sprintf(buf, "childs PID : %d \n", pid);
	write (1, buf, strlen(buf));

	if (pid > 0){
//		wait(1);
#if 0	
		gv = 20;
		lv = 200;
		*hv = 2000;
#endif

		sprintf(buf, "in parent \n");
		write (1, buf, strlen(buf));
		sprintf(buf, "in parent, gv : %d and &gv is : %p \n", gv, &gv);
		write (1, buf, strlen(buf));
		sprintf(buf, "in parent, lv : %d and &lv is : %p \n", lv, &lv);
		write (1, buf, strlen(buf));
		sprintf(buf, "in parent, hv : %d and &hv is : %p \n", *hv, hv);
		write (1, buf, strlen(buf));

	}else if (pid == 0){
#if 1
//		sleep(1);
		gv = 50;
		lv = 500;
		*hv = 5000;
#endif

		sprintf(buf, "in child \n");
		write (1, buf, strlen(buf));
		sprintf(buf, "in child, gv : %d and &gv is : %p \n", gv, &gv);
		write (1, buf, strlen(buf));
		sprintf(buf, "in child, lv : %d and &lv is : %p \n", lv, &lv);
		write (1, buf, strlen(buf));
		sprintf(buf, "in child, hv : %d and &hv is : %p \n", *hv, hv);
		write (1, buf, strlen(buf));
	}else
		printf("fork error..... \n");

	return 0;
}
#endif

//experiment 3: retaining a child allowing to parent exit
#if 0
int main(void)
{
	char *buf = NULL;
	pid_t pid;

	buf = (char *)malloc(80);

	sprintf(buf, " grand- parents PID : %d \n", getpid());
	write (1, buf, strlen(buf));

	pid = fork();

	if (pid > 0){

		printf("in parent \n");

		printf("parent PID using getpid() : %d \n", getpid());
		printf("parent pid : %d \n", pid);

	}else if (pid == 0){

		getchar();	
		printf("in child \n");

		printf("child PID using getpid() : %d \n", pid);
		printf("child pid : %d \n", getpid());

		while(1){	
		}
	}else
		printf("fork error..... \n");

	return 0;
}
#endif
