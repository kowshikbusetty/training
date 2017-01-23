#include <stdio.h>
#include <string.h>
extern int my_strlen (char *);

char *insert_char (char *s, char ch, int pos)
{
	int len1;
	int i;

	len1 = my_strlen(s);
		
	for (i = len1 + 1; i > pos; i--)
			s[i] = s[i - 1];

	s[pos] = ch;

	return s;
}


