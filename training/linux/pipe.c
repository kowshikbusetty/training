#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(void)
{
	int fd[2];
	pid_t pid;

	pipe(fd);

	pid = fork();

	if(pid > 0){
		close(fd[0]);
		dup2(fd[1], 0);
		execlp("wc", "wc", NULL);
		sleep(5);
		close(fd[1]);
	}else if(pid == 0){
		close(fd[1]);
		dup2(fd[0], 1);
		execlp("sort", "sort", NULL);
		close(fd[0]);
	}else{
		printf("error");
	}

	return 0;

}
