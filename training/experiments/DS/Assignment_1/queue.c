#include <stdio.h>
#define MAX 5 

extern void my_enqueue(int);                                                       
extern void my_dequeue(void);                                                       
extern void my_display_queue(void); 

int queue(void)
{
	int choice;
	int num;

	do {
		
		printf ("\nenter the operation to be performed & 0 for exit\n");
		printf ("1.enqueue the element\n2.dequeue the element\n" 
				"3.display_queue stack: \n");


		scanf ("%d", &choice);

		switch(choice) {
		
		case 0 :
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

