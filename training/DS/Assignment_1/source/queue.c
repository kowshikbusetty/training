#include "../header/myheader_ds_1.h"

extern int arr[MAX];                                                            
static int front = -1;                                                           
static int rear = -1;                                                                                

int queue(void)
{
	int choice;
	int num;

	do {
		
		printf ("\nenter the operation to be performed \n0 for exit\n");
		printf ("1.enqueue the element\n2.dequeue the element\n");
		printf ("3.display the queue \n");

		scanf ("%d", &choice);

		switch(choice) {
		
		case 0:				//to come out of program
				break;

		case 1:
				printf ("enter the number : \t");
				scanf ("%d", &num);
				my_enqueue(num);
				break;

		case 2:
				my_dequeue();
				break;
		case 3:
				my_display_queue();
				break;
		default:
				printf("enter the valid option from the above list\n");
				break;

		} 

	}while (choice != 0);
		
	return 0;
}

void my_enqueue(int n)
{
	if ( (front == -1) && (rear == - 1) ){
        front = rear = 0;
        arr[rear] = n;
    }else if( (rear - front + 1) < MAX ){
        rear++;
        arr[rear] = n;
    }else {
        printf ("queue is full \n");
    }

}

void my_dequeue(void)
{
	if(front <= rear){
		front++;
	}else {
		rear = -1;
		front = -1;
		printf ("queue is empty - no deletion can perform \n");
	}
}
void my_display_queue(void)
{
	int i;
	if ( (front == -1) && (rear == -1) ){
		printf ("queue is empty \n");
	}else if (front > rear){
		printf ("queue is empty \n");	
	}else{
		for (i = front; i <= rear; i++){
			printf ("%d  ",arr[i]);
		}
		printf ("\n");
	}
}
