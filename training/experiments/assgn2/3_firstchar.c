#include <stdio.h>
extern int my_strlen (char *);

int i;

char *char_add_instr (char *buf, char ch)
{
	

	for (i = 0; buf[i] != '\0'; i++){
		
		if (buf[i] == ch)
			break;
	}

	if (i == my_strlen(buf))
		return NULL;
	else 
		return (buf+i);

}
