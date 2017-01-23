#include <stdio.h>

extern int front_end;                                                           
extern int rare_end;

void my_dequeue(void)
{
	if(front_end <= rare_end){
		front_end++;
	}else {
		rare_end = -1;
		front_end = -1;
		printf ("queue is empty - no deletion can perform \n");
	}
}
