#include <stdio.h>
#define MAX 5

extern int front_end;                                                           
extern int rare_end;    
extern int arr[MAX];
    
//if ( (front_end == 0) && (rare_end == (MAX - 1)) ){                         
  //      printf ("queue is full \n"); 

void my_display_queue(void)
{
	int i;
	int front;
	int rear;
	
	front = front_end;
	rear = rear_end;

	if ( (front_end == -1) && (rare_end == -1) ){
		printf ("queue is empty \n");
	}else if (front_end > rare_end){
		printf ("queue is empty \n");	
	}else{
		for (i = front_end; i <= rare_end; i++){
			printf ("arr[%d] : %d ", i, arr[i]);
		}
		printf ("\n");
	}
}
		

