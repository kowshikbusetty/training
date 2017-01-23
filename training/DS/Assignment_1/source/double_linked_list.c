#include "../header/myheader_ds_1.h"

struct d_node {
	struct d_node *rlink;
	int info;
	struct d_node *llink;
};
static struct d_node *start_d = NULL;
struct d_node * t = NULL;
struct d_node * q = NULL;

int count = 0;			//used to count no. of elements present in list

int double_linked_list(void)
{

	unsigned int choice;
	int pos;		//used for position in list
	int n;			//used to insert the number
	int num;		//used to search the number in the list

	printf ("\n       MENU            \n"
					"\n1. Insert at the beginning"
					"\n2. Insert at the end"
					"\n3. Insert at a given position "
					"\n4. Insert before a given position"
					"\n5. Insert after a given position"
					"\n6. Insert before a given number"
					"\n7. Insert after a given number"
					"\n8. Insert at the middle"
					"\n9. Insert at penultimate d_node."
					"\n10. DELETE at the beginning"
					"\n11. DELETE at the end"
					"\n12. DELETE at a given position "
					"\n13. DELETE before a given position"
					"\n14. DELETE after a given position"
					"\n15. DELETE before a given number"
					"\n16. DELETE after a given number"
					"\n17. DELETE at the middle"
					"\n18. DELETE at penultimate d_node.");
	
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
					pos = 0;
					ins_pos_d(n,pos);	//insert a element at send position
					break;
			case 2:
					ins_end_d (n); // insert element at end
					break;
			case 3:
					printf ("\nEnter the POSITION : \n");
					scanf ("%d",&pos);
					ins_pos_d (n, pos); //insert element at postion required
					break;
					
			case 4:
					printf ("\nEnter the position : \n");
					scanf ("%d", &pos);
					ins_before_pos_d (n, pos);//insert before the position
					break;
			case 5: 
					printf ("\nEnter the position : \n");
					scanf ("%d", &pos);
					ins_after_pos_d (n, pos);//insert element after the position
					break;
			case 6:
					printf ("enter number before where you want to insert : \n");
					scanf ("%d", &num);
					ins_bef_num_d (n, num);//insert before the number
					break;
			case 7:
					printf ("enter number after which you want to insert : \n");
					scanf ("%d", &num);
					ins_aft_num_d (n, num);//insert after the number
					break;
			case 8:
					ins_middle_d (n);//insert at the middle
					break;
			case 9:
					ins_penultimate_d (n);//insert at penultimate position
					break;
			case 10: 
					del_pos_d(0); // delete element at begining
					break;
			case 11:
					pos = count -1;
					del_pos_d (pos); // delete element at end
					break;
			case 12:
					printf ("\nEnter the position you want to delete \n");
					scanf ("%d", &pos);
					if ( ((pos - 1) >= 0) && ((pos - 1) <= count) ) {
						del_pos_d (pos);//delete element at given position
					}
					break;
			case 13:
					printf ("\nEnter the position before you want to delete \n");
					scanf ("%d", &pos);
				
					if (pos == 0){
						printf ("you cannot perform deletion\n");	
					}else if ( ((pos - 1) >= 0) && ((pos - 1) <= count) ) {
						del_pos_d (pos - 1);//delete element at position
					}
					break;
			case 14: 
					printf ("\nEnter the position after you want to delete \n");
					scanf ("%d", &pos);
					if ( ((pos - 1) >= 0) && ((pos - 1) <= count) ) {
						del_pos_d (pos + 1);//delete element at position
					}
					break;
			case 15:
					printf ("enter number before which you want to delete \n");
					scanf ("%d", &pos);
					pos = search_d (pos);//search the position of element in list
					if (pos) {
						pos--;
						del_pos_d (pos);//delete element at position
					}
					break;
			case 16:
					printf ("enter number after which you want to delete \n");
					scanf ("%d", &pos);
					pos = search_d (pos);//search the position of element in list
					pos++;
					if (pos) {
						del_pos_d (pos);//delete element at position 
					}
					break;
			case 17:
					if( count % 2 == 0){                                                        
						pos = count / 2;                                                        
						del_pos_d(pos);                                                      
					}else {                                                                     
						pos = (count / 2) + 1;                                                  
						del_pos_d(pos);                                                      
					} 
					break;
			case 18:
					del_pos_d (count - 2);//delete element at position 
					break;
			default : 
					printf ("enter the correct option \n");
					break;
			}
		}

	}while (choice != 0);

	display_d ();	//display elements present in the list

	return 0;
}

void ins_end_d (int n)
{
	if ((start_d == NULL) && (count)){
		t = (struct d_node*) malloc (sizeof (struct d_node));
		q = start_d;
		t -> info = n;
		t -> llink = NULL;
		t -> rlink = start_d;
		start_d -> rlink = t;
		start_d = t;
		count++;
	}else {
		ins_pos_d(n, count);
	}
}

void ins_pos_d (int n , int pos)
{
	t = (struct d_node*) malloc (sizeof (struct d_node));
	
	q = start_d;
	t -> info = n;

	if ((pos > count) && (pos < 0)){
		printf ("enter correct position \n");
	}else if ((start_d == NULL)){
		start_d = t;
		count++;

	}else if (pos == 0){
		t -> llink = NULL;
		t -> rlink = start_d;
		start_d ->llink = t;
		start_d = t;
		count++;
	
	}else {
		pos = pos -1;
		while ((pos)--){
			q = q -> rlink;
		}
		t -> llink = q;
		t -> rlink = q -> rlink;
		q -> rlink = t;
		count++;
	}
}

void ins_before_pos_d (int n, int pos)	//insert before position given
{
	ins_pos_d (n, (pos - 1));
}	

void ins_after_pos_d (int n, int pos) //insert after position given
{
	pos = pos + 1;
	ins_pos_d(n, pos);
}

void ins_bef_num_d (int n, int num) //insert before number
{
	int pos;
	pos = search_d(num);
	ins_pos_d(n, pos);

}

void ins_aft_num_d (int n, int num) // insert after given number
{
	int pos = 0;
	pos = search_d(num) + 1;

	if (pos) {
		ins_pos_d(n, pos);
	}
}

void ins_middle_d (int n)
{
	int pos;
	if( count % 2 == 0){
		pos = count / 2;
		ins_pos_d(n, pos);
	}else {
		pos = (count / 2) + 1;
		ins_pos_d(n, pos);
	}
}

void ins_penultimate_d (int n) // insert number before last element
{
	int pos;
	pos = count - 1;
	ins_pos_d(n, pos);
}

void display_d (void)  //function to display the linked list
{
	q = start_d;

	if (count == 0){
		printf ("list is empty \n");
	}else{
		printf ("\nlist elements are:\n");
		while (q) {
			printf ("%d\t", q -> info);
			q = q -> rlink;
		}
	}

}

void del_pos_d (int pos)
{
	int i;
	int del;
	q = start_d;

	if (((pos < 0) && (pos > count) && (count == 0)) || (pos == count)) {
		printf ("\ninvalid position");
	} else if (pos == 0) {
		del = start_d -> info;
		start_d = start_d -> rlink;
		free (q);
		count --;
		printf ("\nElement you deleted is %d \n",del);
	} else if(pos < count) {

		i = 1;
		while (i < pos) {
			q = q -> rlink;
			i ++;
		}
		t = q -> rlink;
		q -> rlink = q -> rlink -> rlink;
		del = t -> info;
		count --;
		free (t);
		printf ("\nElement you deleted is %d \n",del);
	}
	
}

int search_d (int n) // to serach the given number in list and returns the position
{
	int pos;

	q = start_d;
	for (pos = 0 ; q; pos++) {
		if (q -> info == n)
			break;
		q = q -> rlink;
	}
	if (!q) {
		printf("\nNumber not found");
		return 0;
	} else {
		return pos;
	}
}
