
int my_strlen(char *);

int my_strlen(char *str)
{
	int i = 0;
	while((*(str + i)) != '\n') {
		i++;
	}
	return i;
}
