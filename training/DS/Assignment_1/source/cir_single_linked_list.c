#include "../header/myheader_ds_1.h"
struct c_node {
	int data;
	struct c_node* link;
};

struct c_node * end = NULL;
struct c_node *c_temp = NULL;
struct c_node *c_p = NULL;
int size;
int n;

int cir_single_linked_list(void)
{
	int ch;
	int pos;
	char m = 'y';
	while (m == 'y') {
		system ("clear");
		printf ("\n   OPERATIONS TO BE PERFORMED ON CSLL");
		printf ("\n  1.INSERT\n  2.DELETE\nDo you want to insert or delete? :");
		scanf ("%d", &ch);

		if (ch == 1) {
			m = 'y';
			while (m == 'y') {
				system ("clear");
				printf ("\n\t       MENU FOR CSLL ISNERTION        \n"
						"\n\t1. Insert at the beginning"
						"\n\t2. Insert at the end"
						"\n\t3. Insert at a given position "
						"\n\t4. Insert before a given position"
						"\n\t5. Insert after a given position"
						"\n\t6. Insert before a given number"
						"\n\t7. Insert after a given number"
						"\n\t8. Insert at the middle"
						"\n\t9. Insert at penultimate c_node.");
				cir_sll_display();
				printf ("\nEnter the option:");
				scanf ("%d", &ch);
				switch (ch) {
					case 1: 
						cir_ins_beg(); // insert element at begining of linked list
						break;
					case 2:
						cir_ins_end (); // insert element at end.
						break;
					case 3:			// insertion at given position
						printf ("\nEnter the position you want to insert");
						scanf ("%d",&pos);
					 	(pos == (size + 1)) ? cir_ins_end() : cir_ins_pos (pos); //insert element at postion required
						break;
					case 4:   // insertio befoer given postion
						printf ("\nEnter the position before which you want to insert");
						scanf ("%d", &pos);
						cir_ins_pos (pos - 1);
						break;
					case 5:   // insertion after given postion
						printf ("\nEnter the position after which you want to insert");
						scanf ("%d", &pos);
						cir_ins_pos (pos + 1);
						break; 
					case 6:			// insertion before given number
						printf ("enter number before which you want to insert");
						scanf ("%d", &pos);
						pos = cir_search (pos);
						if (pos > 1) {
							cir_ins_pos (pos);
						} else if (1 == pos) {
							cir_ins_end();
						}
						break;
					case 7:  //insertion at c_node after number given
						printf ("enter number after which you want to insert");
						scanf ("%d", &pos);
						pos = cir_search (pos);
						if (pos > 0 && pos < size  ) {
							cir_ins_pos (pos + 1);
						} else if (size == pos) {
							cir_ins_beg ();
						}
						break;
					case 8:
						cir_ins_pos (((size + 1) / 2) + 1);  //insertion at middle c_node
						break;
					case 9:
						cir_ins_pos(size); // insertion at penultmiate c_node
						break;
					default :
						printf ("\ninvalid option");

				}
				cir_sll_display ();
				m = 'o';
				while (1) {
					printf ("\nDo you want to insert another element(y/n)?:");
					scanf (" %c", &m);
					if (m == 'y' || m == 'n') {
						break;
					}
				}

			}
		} else if (ch == 2) {
			m = 'y';
			while (m == 'y') {
				system("clear");
				printf ("\n\t       MENU for CSLL DELETION      \n"
						"\n\t1. DELETE at the beginning"
						"\n\t2. DELETE at the end"
						"\n\t3. DELETE at a given position "
						"\n\t4. DELETE before a given position"
						"\n\t5. DELETE after a given position"
						"\n\t6. DELETE before a given number"
						"\n\t7. DELETE after a given number"
						"\n\t8. DELETE at the middle"
						"\n\t9. DELETE at penultimate c_node.");
				printf ("\nEnter the option:");
				scanf ("%d", &ch);
				switch (ch) {
					case 1: 
						cir_del_pos(1); // delete element at begining of linked list
						break;
					case 2:
						cir_del_pos(size); // delete element at end.
						break;
					case 3:
						printf ("\nEnter the position you want to Delete");
						scanf ("%d",&pos);
						cir_del_pos (pos); //delete  element at postion required
						break;
					case 4:  // delete c_node before given postion
						printf ("\nEnter the position before which you want to delete");
						scanf ("%d", &pos);
						cir_del_pos(pos - 1);
						break;
					case 5:    // delete c_node after given postion
						printf ("\nEnter the position after which you want to delete");
						scanf ("%d", &pos);
						cir_del_pos (pos + 1);
						break;
					case 6: // delete c_node before given number
						printf ("enter number before which you want to delete");
						scanf ("%d", &pos);
						pos = cir_search (pos);
						if (pos) {
							pos --;
							cir_del_pos (pos);
						}
						break;
					case 7:   // delete c_node after given number
						printf ("enter number after which you want to insert");
						scanf ("%d", &pos);
						pos = cir_search (pos);
						if (pos) {
							pos++;
							cir_del_pos (pos);
						}
						break;
					case 8:           // deletion at middle c_node
						cir_del_pos ((size + 1)/2);
						break;
					case 9:
						cir_del_pos (size - 1); // deltion at peuultmiate c_node
						break;
					default :
						printf ("\ninvalid option");

				}
				cir_display ();
				m = 'o';
				while (1) {
					printf ("\nDo you want to Delete another element(y/n)?:");
					scanf (" %c", &m);
					if (m == 'y' || m == 'n') {
						break;
					}
				}

			}

		} else {
			printf ("\nINVALID option enter 1 or 2");
		}
		m = 'o';
		while (1) {
			printf ("\nDo you want to perform another operation(y/n)?:");
			scanf (" %c", &m);
			if (m == 'y' || m == 'n') {
				break;
			}
		}

	}
	return 0;
}
void cir_ins_beg()
{
	c_temp = (struct c_node*) malloc (sizeof (struct c_node));
	printf ("\nEnter the element you want to insert");
	scanf ("%d", &c_temp -> data);
	if (end) {
		c_temp -> link = end -> link;
		end -> link = c_temp;
		size++;
		c_temp = NULL;
	} else {
		end = c_temp;
		c_temp -> link = c_temp;
		c_temp = NULL;
		size ++;
	}

}

void cir_ins_end ()
{
	if (0 == size) {
		cir_ins_beg();
	} else {
		c_temp = (struct c_node*) malloc (sizeof (struct c_node));
		printf ("\nEnter the element you want to insert");
		scanf ("%d", &c_temp -> data);
		c_temp -> link = end -> link;
		end -> link = c_temp;
		end = c_temp;
		c_temp = NULL;
		size ++;
	}
}

void cir_ins_pos (int pos)
{
	int i;

	if (pos > (size + 1) || pos < 0) {
		printf("\npostion is beyond list size");
	} else if (1 == pos || pos == (size + 1)) {
		cir_ins_beg();
	} else if (size  == pos || 0 == pos) {
		cir_ins_end();
	} else {
		c_p = end;
		for (i = 1 ; i < pos; i++, c_p = c_p -> link);		
		c_temp = (struct c_node*) malloc (sizeof (struct c_node));
		printf ("\nEnter the element you want to insert");
		scanf ("%d", &c_temp -> data);
		c_temp -> link = c_p -> link;
		c_p -> link = c_temp;
		c_temp = NULL;
		size ++;
	}
}


int cir_search (int num) // to serach the given number in list and returns the position
{
	int i;		

	if (0 == size) {
		printf ("\nlist is empty to cir_search");
	} else {
		c_p = end -> link;
		for (i = 1; (c_p -> data != num) && (c_p != end); c_p = c_p -> link, i++);
		if (c_p == end) {
			if (num == c_p -> data) {
				return i ;
			} else {
				printf ("Given number not found in the list");
				return 0;
			}
		} else {
			return i;
		}

	}
	return 0;
} 

void cir_sll_display (void)  //function to cir_display the linked list
{
	if (0 == size) {
		printf ("\nCircular list is Empty");
	} else {
		printf ("\ncircular single linked list elements:\n");
		for (c_p = end -> link; c_p != end; c_p = c_p -> link) {
			printf ("%d -> ", c_p -> data);
		}
		printf ("%d\n", c_p -> data);
	}
}
void cir_del_beg ()
{
	c_temp = end -> link;
	printf ("\nthe element you are deleting is %d", c_temp -> data);
	end -> link = c_temp -> link;
	free(c_temp);
	size --;
}
void cir_del_end ()
{
	for (c_p = end -> link; c_p -> link != end ; c_p = c_p -> link);
	printf ("\nthe element you are deleting is: %d", end -> data);
	c_p -> link = end -> link;
	free (end);
	end = c_p;
	size--;
}
void cir_del_pos (int pos)
{
	int i ;

	c_p = end;

	if (size == 0) {
		printf ("\nlinked list is empty to delete");
	} else if (pos < 0 || pos > size + 1) {
		printf ("\ninvalid position");
	} else if (pos == 1 || pos == size + 1) {
		cir_del_beg();
	} else if (pos == size || 0 == pos) {
		cir_del_end();
	} else {
		c_p = end -> link;
		for (i = 1; i < (pos - 1) ; c_p = c_p -> link);
		printf ("\nthe element you are going to delete is :%d", c_p -> link -> data);
		c_temp = c_p -> link;
		c_p -> link = c_temp -> link;
		free (c_temp);
		size --;
	}

}
