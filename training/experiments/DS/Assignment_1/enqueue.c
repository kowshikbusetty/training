#include <stdio.h>
#define MAX 5

extern int arr[MAX];
extern int front_end;
extern int rare_end;

void my_enqueue(int n)                                                                
{                                                                               
	if ( (front_end == -1) && (rare_end == - 1) ){
		front_end++;
		rare_end++;
		arr[rare_end] = n;
	}else if( (rare_end - front_end + 1) < MAX ){
		rare_end++;
		arr[rare_end] = n;
	}else {
		printf ("queue is full \n");
	}
}

