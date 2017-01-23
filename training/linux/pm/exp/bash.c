#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//experiment : implementing own bash
#if 1
int main(int argc, char *argv[])
{
//	char * const argv[] = {"/home/kowshik"};
//	char * const argv[] = {};
//	char * const argv[] = {"/bin/ls", "/home/kowshik/training/linux/basic_kernel"};
	pid_t pid;

	pid = fork();

	if (pid > 0){
		wait(0)
		printf("parent \n");
	}else if (pid == 0){
		execv(argv[1] ,argv);
		printf("child \n");
	}else
		printf("fork error..... \n");

	return 0;
}
#endif
#if 0
int main(void)
{
	char * argv[] = {"","/home/kowshik/training/linux/pm/exp", NULL};
	char buf[80];
	pid_t pid;

	while(1){
		printf("enter the command \n");
		fgets(buf, 10, stdin);

		buf[strlen(buf) -1] = '\0';

		pid = fork();

		if (pid > 0){
			wait(0);
		}else if (pid == 0){
			if (-1 == execv(buf ,(argv + 0))){
					perror("execvp fails..... \n");
					exit(1);
			}
		}else
			printf("fork error..... \n");
	}

	return 0;
}
#endif
#if 0
int main(void)
{
	char * argv[] = {"","/home/kowshik/", NULL};
	char buf[80];
	
//	buf = (char *)malloc (80);
	
	pid_t pid;

	while(1){
		printf("enter the command \n");
		fgets(buf, 10, stdin);

		buf[strlen(buf) -1] = '\0';

		pid = fork();

		if (pid > 0){
			wait(0);
		}else if (pid == 0){
//			if (-1 == execvp(buf ,(argv + 0))){
  			if (-1 == execvp(buf,argv)){
					perror("execvp fails..... \n");
					exit(1);
			}
		}else
			printf("fork error..... \n");
	}

	return 0;
}
#endif
