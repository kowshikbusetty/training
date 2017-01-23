#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

unsigned char buf[16];

void my_printf (char c, int n)
{
	int r, len;
	int i;
	int cnt;
	char temp;

	if('1' == c){
		for (i = 0; n > 0; i++){
			r =( n % 10) + 0x30;
			buf[i] = (char)r;	
			n = n/10;
		}

		buf[i] = '\0';
		len = i;
		i = 0;

		while (i < len/2)
		{
			temp = buf[len - i - 1];
			buf[len - i - 1] = buf[i];
			buf[i] = temp;
			i++;
	}

	}

	if('2' == c){
		for (i = 0; n > 0; i++){
			r =( n % 16) + 0x30;
			buf[i] = (char)r;	
			n = n/16;
		}

		buf[i] = '\0';
		len = i;
		i = 0;

		while (i < len/2)
		{
			temp = buf[len - i - 1];
			buf[len - i - 1] = buf[i];
			buf[i] = temp;
			i++;
	}

	}

	cnt = write (1, buf, sizeof(buf));
	if(cnt <= 0){
		perror("error");
		exit (1);
	}

	write (1, "\n", 2);
}	

int main (void)
{
	int n = 0x1019;

		
//	my_printf('1',n);

	my_printf('2',n);

	return 0;
}

