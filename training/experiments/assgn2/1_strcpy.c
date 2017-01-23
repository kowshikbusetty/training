#include <stdio.h>
void my_strcpy (char *dbuf, char *sbuf)
{
	while(*sbuf != '\0'){
		*dbuf = *sbuf;
		sbuf++;
		dbuf++;
	}

	*dbuf = '\0';	
}


