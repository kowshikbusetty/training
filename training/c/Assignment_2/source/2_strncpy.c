#include <stdio.h>
void my_strncpy (char *dbuf, char *sbuf, int n)
{

	while(n){
		*dbuf = *sbuf;
		sbuf++;
		dbuf++;
		n--;
	}

	*dbuf = '\0';
	
}
