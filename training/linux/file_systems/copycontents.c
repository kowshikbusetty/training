#include<stdio.h>
#include<fcntl.h>
#include<sys/file.h>
#include<stdlib.h>
#include <sys/types.h>

int main(int argc,char *argv[])
{
	char buf[100];
	int  sf,df,fe;
	
	if(argc != 3)
	{
		write(1,"files not given\n",50);
		exit(1);
	}else{
		if((sf = open( argv[1],O_RDONLY)) == -1) {
				perror("Source file error");
				exit(0);
		}

		if ((df = open(argv[2],O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR)) == -1){
			perror("Destination failed open");
			exit(0);
		}

		while(0 < (fe = read(sf,&buf,1))){
				write (df,&buf,1);
		}

		close(sf);
		close(df);
		write(1,"FILES COPIED\n",15);
			
	}

	return 0;
}

	
