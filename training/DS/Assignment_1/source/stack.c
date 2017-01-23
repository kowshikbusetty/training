#include "../header/myheader_ds_1.h"

int stack(void)
{
	int choice;
	int num;

	do {
		
		printf ("\nenter the operation to be performed & 0 for exit\n");
		printf ("1.push the elements\n2.pop the element\n3.display stack: \n");
		scanf ("%d", &choice);

		switch(choice) {
		
		case 0 :
				break;

		case 1:
				printf ("enter the number : \t");
				scanf ("%d", &num);
				my_push(num);
				break;

		case 2:
				my_pop();
				break;

		case 3:
				my_display();
				break;

		default:
				printf("enter the valid option from the above list\n");
				break;

		} 

	}while (choice != 0);
	
	return 0;
}

