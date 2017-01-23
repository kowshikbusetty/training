#include "../header/myheader_ds_1.h"
                  
int arr[MAX];	//array declaration
int top = -1;	//used for checking the array is full or empty in stack program
int front_end = -1;	//used for deleting element in queue
int rare_end = -1;	//used for inserting elements in queue

int main(void)
{
	int op;

	do {
		
		printf ("\n enter the option to be select the program & 0 for exit\n");
		printf ("1.stack \n");
		printf ("2.queue \n");
		printf ("3.circular queue \n");
		printf ("4.single_linked_list \n");
		printf ("5.double_linked_list \n");
		printf ("6.circular single linked list \n");
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
				cir_queue();	
				break;

		case 4:
				single_linked_list();
				break;

		case 5:
				double_linked_list();
				break;

		case 6:
				cir_single_linked_list();
				break;

		default:
				printf("enter the valid option from the above list\n");
				break;

		} 

	}while (op != 0);
	
	return 0;
}

