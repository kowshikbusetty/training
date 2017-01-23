#include "../header/myheader_ds_1.h"

struct node {
	int info;
	struct node *link;
};

struct node *start = NULL;
struct node * temp = NULL;
struct node * p = NULL;

int count;
int single_linked_list(void)
{

	unsigned int choice;
	int pos;
	int n;

	printf ("\n       MENU            \n"
					"\n1. Insert at the beginning"
					"\n2. Insert at the end"
					"\n3. Insert at a given position "
					"\n4. Insert before a given position"
					"\n5. Insert after a given position"
					"\n6. Insert before a given number"
					"\n7. Insert after a given number"
					"\n8. Insert at the middle"
					"\n9. Insert at penultimate node."
					"\n10. DELETE at the beginning"
					"\n11. DELETE at the end"
					"\n12. DELETE at a given position "
					"\n13. DELETE before a given position"
					"\n14. DELETE after a given position"
					"\n15. DELETE before a given number"
					"\n16. DELETE after a given number"
					"\n17. DELETE at the middle"
					"\n18. DELETE at penultimate node.");
	
	do{
		printf ("\nenter the operation to perform or 0 for exit \n");
		scanf ("%d", &choice);

		if(choice != 0){
			if((choice < 10) && (choice > 0)){
				printf ("enter the NUMBER you want to insert : \n");
				scanf (" %d", &n);
			}
			switch (choice){
			
			case 1:
					ins_beg(n); // insert element at begining of linked list
					break;
			case 2:
					ins_end (n); // insert element at end
					break;
			case 3:
					printf ("\nEnter the POSITION : \n");
					scanf ("%d",&pos);
					ins_pos (n, pos); //insert element at postion required
					break;
					
			case 4:
					printf ("\nEnter the position : \n");
					scanf ("%d", &pos);
					ins_before_pos (n, pos);
					break;
			case 5: 
					printf ("\nEnter the position : \n");
					scanf ("%d", &pos);
					ins_after_pos (n, pos);
					break;
			case 6:
					printf ("enter number before which you want to insert : \n");
					scanf ("%d", &pos);
					ins_bef_num (n, pos);
					break;
			case 7:
					printf ("enter number after which you want to insert : \n");
					scanf ("%d", &pos);
					ins_aft_num (n, pos);
					break;
			case 8:
					ins_middle (n);
					break;
			case 9:
					ins_penultimate (n);
					break;
			case 10: 
					del_pos(0); // delete element at begining
					break;
			case 11:
					pos = count -1;
					del_pos (pos); // delete element at end
					break;
			case 12:
					printf ("\nEnter the position you want to delete \n");
					scanf ("%d", &pos);
					if ( ((pos - 1) >= 0) && ((pos - 1) <= count) ) {
						del_pos (pos);
					}
					break;
			case 13:
					printf ("\nEnter the position before you want to delete \n");
					scanf ("%d", &pos);
				
					if (pos == 0){
						printf ("you cannot perform deletion\n");	
					}else if ( ((pos - 1) >= 0) && ((pos - 1) <= count) ) {
						del_pos (pos - 1);
					}
					break;
			case 14: 
					printf ("\nEnter the position after you want to delete \n");
					scanf ("%d", &pos);
					if ( ((pos - 1) >= 0) && ((pos - 1) <= count) ) {
						del_pos (pos + 1);
					}
					break;
			case 15:
					printf ("enter number before which you want to delete \n");
					scanf ("%d", &pos);
					pos = search (pos);
					if (pos) {
						pos--;
						del_pos (pos);
					}
					break;
			case 16:
					printf ("enter number after which you want to delete \n");
					scanf ("%d", &pos);
					pos = search (pos);
					pos++;
					if (pos) {
						del_pos (pos);
					}
					break;
			case 17:
					del_pos (count / 2);
					break;
			case 18:
					del_pos (count - 2);
					break;
			default : 
					printf ("enter the correct option \n");
					break;
			}
		}

	}while (choice != 0);

	display ();

	return 0;
}

void ins_beg(int n)
{
	temp = (struct node*) malloc (sizeof (struct node));

	temp -> info = n;
	
	if (start == NULL){
		temp -> link = NULL;
		start = temp;
		count++;
	}else {
		temp -> link = start;
		start = temp;
		count++;
	}
}

void ins_end (int n)
{
	temp = (struct node*) malloc (sizeof (struct node));

	p = start;
	temp -> info = n;
	temp -> link = NULL;
	
	if (start == NULL){
		start = temp;
		count++;
	}else {
		while (p -> link != NULL){
			p = p -> link;
		}
		p -> link = temp;
		count++;
	}
}

void ins_pos (int n , int pos)
{
	temp = (struct node*) malloc (sizeof (struct node));
	
	p = start;
	temp -> info = n;

	if (pos > count){
		printf ("enter correct position \n");
	}else if (pos == 0){
		temp -> link = start;
		start = temp;
		count++;
	
	}else {
		pos = pos -1;
		while ((pos)--){
			p = p -> link;
		}
		temp -> link = p -> link;
		p -> link = temp;
		count++;
	}
}

void ins_before_pos (int n, int pos)	//insert before position given
{
	ins_pos (n, pos);
}	

void ins_after_pos (int n, int pos) //insert after position given
{
	pos = pos + 1;
	ins_pos (n, pos);
}

void ins_bef_num (int n, int num) //insert before number
{
	int pos;
	pos = search (num);

	ins_pos (n, pos);

}

void ins_aft_num (int n, int num) // insert after given number
{
	int pos = 0;
	pos = search (num) + 1;

	if (pos) {
		ins_pos(n, pos);
	}
}

void ins_middle (int n)
{
	int pos;
	if( count % 2 == 0){
		pos = count / 2;
		ins_pos (n, pos);
	}else {
		pos = (count / 2) + 1;
		ins_pos (n, pos);
	}
}

void ins_penultimate (int n) // insert number before last element
{
	int pos;
	pos = count - 1;
	ins_pos (n, pos);
}

void display (void)  //function to display the linked list
{
	p = start;

	if (count == 0){
		printf ("list is empty \n");
	}else{
		printf ("\nlist elements are:\n");
		while (p) {
			printf ("%d\t", p -> info);
			p = p -> link;
		}
	}

}

void del_pos (int pos)
{
	int i;
	int del;
	p = start;

	if (((pos < 0) && (pos > count) && (count == 0)) || (pos == count)) {
		printf ("\ninvalid position");
	} else if (pos == 0) {
		del = start -> info;
		start = start -> link;
		free (p);
		count --;
		printf ("\nElement you deleted is %d \n",del);
	} else if(pos < count) {

		i = 1;
		while (i < pos) {
			p = p -> link;
			i ++;
		}
		temp = p -> link;
		p -> link = p -> link -> link;
		del = temp -> info;
		count --;
		free (temp);
		printf ("\nElement you deleted is %d \n",del);
	}
	
}

int search (int n) // to serach the given number in list and returns the position
{
	int pos;

	p = start;
	for (pos = 0 ; p; pos++) {
		if (p -> info == n)
			break;
		p = p -> link;
	}
	if (!p) {
		printf("\nNumber not found");
		return 0;
	} else {
		return pos;
	}
}
