#include <stdio.h>

void fun(void)
{
	int fn_auto_var = 0;
	static int fn_static = 0;
	
	fn_auto_var = fn_auto_var+1;
	fn_static = fn_static+1;
	
	printf ("value of fn_auto_var : %d \n", fn_auto_var);
	printf ("value of fn_static : %d \n", fn_static);

	printf ("\n");
	return;
}

int main(void)
{
	int i;
	
	for (i=0; i<=5; i++ ){
		fun();
	}
	
	return (0);
}


