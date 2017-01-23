#include <stdio.h>
#include <stdlib.h>

#if 0
int main(void)
{
//	int a;
	char c;
	
//	printf("%p \n", &a);
	printf("%p \n", &c);

	return 0;
}
#endif

#if 0
int main()
{
	unsigned char *c;
	c = 'A';

	while (c >= 0)
		printf("%d\n", (*c)++);
}
#endif
#if 0
char *s = "char *s = %c%s%c;main(){printf(s,34,s,34);}";
	main(){printf(s,34,s,34);}

#endif
#if 0
int main(void)
{
//	printf("");
//	printf("%d");
	printf();

	return 0;
}
#endif
#if 0
int main()
{

	return 0;
}
#endif

#if 0
int main()
{
	printf("%d\n", argv[argc]);

	return 0;
}
#endif
#if 1
static void func()
{
	static int i = 1;
	for(;i<5;i++){
		printf("i=%d\n",i);
		func();
	}

}
int main(void)
{
	func();

	return 0;
}

#endif
