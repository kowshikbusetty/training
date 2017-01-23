#include <stdio.h>
int my_strlen (char *p)
{
	int i;

	for (i = 0; p[i]; i++);

	return i;
}
