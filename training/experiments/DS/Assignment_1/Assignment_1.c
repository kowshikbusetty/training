#include "myheader.h"
                  
int arr[MAX];	//array declaration
int top = -1;	//used for checking the array is full or empty in stack program
int front_end = -1;	//used for deleting element in queue
int rare_end = -1;	//used for inserting elements in queue

int main(void)
{
	int op;

	printf ("1.stack \n");
	printf ("2.queue \n");

	do {
		
		printf ("\nenter the option to be select the program & 0 for exit\n");
		scanf ("%d", &op);

		switch( op ) {
		
		case 0:
				break;

		case 1 :
				stack();
				break;

		case 2:
				queue();
				break;

		case 3:
				break;

		case 4:
				break;

		default:
				printf("enter the valid option from the above list\n");
				break;

		} 

	}while (op != 0);
	
	return 0;
}

