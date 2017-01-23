#include "my_cir_sll_head.h"

extern struct c_node {
	int info;
	struct c_node *link;
};

struct c_node *start = NULL;
struct c_node * new = NULL;
struct c_node * c = NULL;

int count;
int cir_single_linked_list(void)
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
					"\n9. Insert at penultimate c_node."
					"\n10. DELETE at the beginning"
					"\n11. DELETE at the end"
					"\n12. DELETE at a given position "
					"\n13. DELETE before a given position"
					"\n14. DELETE after a given position"
					"\n15. DELETE before a given number"
					"\n16. DELETE after a given number"
					"\n17. DELETE at the middle"
					"\n18. DELETE at penultimate c_node.");
	
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
					cir_ins_beg(n); // insert element at begining of linked list
					break;
			case 2:
					cir_ins_end (n); // insert element at end
					break;
			case 3:
					printf ("\nEnter the POSITION : \n");
					scanf ("%d",&pos);
					cir_ins_pos (n, pos); //insert element at postion required
					break;
					
			case 4:
					printf ("\nEnter the position : \n");
					scanf ("%d", &pos);
					cir_ins_before_pos (n, pos);
					break;
			case 5: 
					printf ("\nEnter the position : \n");
					scanf ("%d", &pos);
					cir_ins_after_pos (n, pos);
					break;
			case 6:
					printf ("enter number before which you want to insert : \n");
					scanf ("%d", &pos);
					cir_ins_bef_num (n, pos);
					break;
			case 7:
					printf ("enter number after which you want to insert : \n");
					scanf ("%d", &pos);
					cir_ins_aft_num (n, pos);
					break;
			case 8:
					cir_ins_middle (n);
					break;
			case 9:
					cir_ins_penultimate (n);
					break;
			case 10: 
					cir_del_pos(0); // delete element at begining
					break;
			case 11:
					pos = count -1;
					cir_del_pos (pos); // delete element at end
					break;
			case 12:
					printf ("\nEnter the position you want to delete \n");
					scanf ("%d", &pos);
					if ( ((pos - 1) >= 0) && ((pos - 1) <= count) ) {
						cir_del_pos (pos);
					}
					break;
			case 13:
					printf ("\nEnter the position before you want to delete \n");
					scanf ("%d", &pos);
				
					if (pos == 0){
						printf ("you cannot perform deletion\n");	
					}else if ( ((pos - 1) >= 0) && ((pos - 1) <= count) ) {
						cir_del_pos (pos - 1);
					}
					break;
			case 14: 
					printf ("\nEnter the position after you want to delete \n");
					scanf ("%d", &pos);
					if ( ((pos - 1) >= 0) && ((pos - 1) <= count) ) {
						cir_del_pos (pos + 1);
					}
					break;
			case 15:
					printf ("enter number before which you want to delete \n");
					scanf ("%d", &pos);
					pos = cir_search (pos);
					if (pos) {
						pos--;
						cir_del_pos (pos);
					}
					break;
			case 16:
					printf ("enter number after which you want to delete \n");
					scanf ("%d", &pos);
					pos = cir_search (pos);
					pos++;
					if (pos) {
						cir_del_pos (pos);
					}
					break;
			case 17:
					cir_del_pos (count / 2);
					break;
			case 18:
					cir_del_pos (count - 2);
					break;
			default : 
					printf ("enter the correct option \n");
					break;
			}
		}

	}while (choice != 0);

	cir_display ();

	return 0;
}

void cir_ins_beg(int n)
{
	new = (struct c_node*) malloc (sizeof (struct c_node));

	new -> info = n;
	
	if (start == NULL){
		new -> link = NULL;
		start = new;
		count++;
	}else {
		new -> link = start;
		start = new;
		count++;
	}
}

void cir_ins_end (int n)
{
	new = (struct c_node*) malloc (sizeof (struct c_node));

	c = start;
	new -> info = n;
	new -> link = NULL;
	
	if (start == NULL){
		start = new;
		count++;
	}else {
		while (c -> link != NULL){
			c = c -> link;
		}
		c -> link = new;
		count++;
	}
}

void cir_ins_pos (int n , int pos)
{
	new = (struct c_node*) malloc (sizeof (struct c_node));
	
	c = start;
	new -> info = n;

	if (pos > count){
		printf ("enter correct position \n");
	}else if (pos == 0){
		new -> link = start;
		start = new;
		count++;
	
	}else {
		pos = pos -1;
		while ((pos)--){
			c = c -> link;
		}
		new -> link = c -> link;
		c -> link = new;
		count++;
	}
}

void cir_ins_before_pos (int n, int pos)	//insert before position given
{
	cir_ins_pos (n, pos);
}	

void cir_ins_after_pos (int n, int pos) //insert after position given
{
	pos = pos + 1;
	cir_ins_pos (n, pos);
}

void cir_ins_bef_num (int n, int num) //insert before number
{
	int pos;
	pos = cir_search (num);

	cir_ins_pos (n, pos);

}

void cir_ins_aft_num (int n, int num) // insert after given number
{
	int pos = 0;
	pos = cir_search (num) + 1;

	if (pos) {
		cir_ins_pos(n, pos);
	}
}

void cir_ins_middle (int n)
{
	int pos;
	if( count % 2 == 0){
		pos = count / 2;
		cir_ins_pos (n, pos);
	}else {
		pos = (count / 2) + 1;
		cir_ins_pos (n, pos);
	}
}

void cir_ins_penultimate (int n) // insert number before last element
{
	int pos;
	pos = count - 1;
	cir_ins_pos (n, pos);
}

void cir_display (void)  //function to display the linked list
{
	c = start;

	if (count == 0){
		printf ("list is empty \n");
	}else{
		printf ("\nlist elements are:\n");
		while (c) {
			printf ("%d\t", c -> info);
			c = c -> link;
		}
	}

}

void cir_del_pos (int pos)
{
	int i;
	int del;
	c = start;

	if (((pos < 0) && (pos > count) && (count == 0)) || (pos == count)) {
		printf ("\ninvalid position");
	} else if (pos == 0) {
		del = start -> info;
		start = start -> link;
		free (c);
		count --;
		printf ("\nElement you deleted is %d \n",del);
	} else if(pos < count) {

		i = 1;
		while (i < pos) {
			c = c -> link;
			i ++;
		}
		new = c -> link;
		c -> link = c -> link -> link;
		del = new -> info;
		count --;
		free (new);
		printf ("\nElement you deleted is %d \n",del);
	}
	
}

int cir_search (int n) // to serach the given number in list and returns the position
{
	int pos;

	c = start;
	for (pos = 0 ; c; pos++) {
		if (c -> info == n)
			break;
		c = c -> link;
	}
	if (!c) {
		printf("\nNumber not found");
		return 0;
	} else {
		return pos;
	}
}
