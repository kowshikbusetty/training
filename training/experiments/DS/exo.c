#include <stdio.h>
#if 0
int main(void)
{
	union{
		int i;
		float f;
	}u = {10};
	printf ("%f \n", u.f);
	printf ("%d \n", u.i);
	return 0;
}
#endif
#if 0
int main(void)
{
union a{
	char c;
	int ascii;
	};
	union a arr[2] = {{65}, {'a'}};
	printf ("%c  %c \n", arr[0], arr[1]);

	return 0;
}
#endif
#if 1
int main(void)
{
	struct mystruct{
		int i;
		char a[];
	};
	printf ("%d \n", sizeof(struct mystruct));

	return 0;
}
#endif
