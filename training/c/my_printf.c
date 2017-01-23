#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

unsigned char buf[16];

/*void (int c, char *n)
{
	write (1, &n, sizeof(n));

}	*/
int main (void)
{
	int n = 1234;
	int r, len;
	int i;
	int cnt;
	char temp;
//	my_printf(1,n);
//	my_printf('2',n);
	 for (i = 0; n > 0; i++){
		r =( n % 10)+48;
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
//	buf = strrev(buf);

	cnt = write (1, buf, sizeof(buf));
	if(cnt <= 0){
		perror("error");
		exit (1);
	}
	
	return 0;
}

