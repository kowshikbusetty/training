#include "../my_header_ds_2.h"

int main (void)
{
	unsigned int option;

	int n;          //used to insert the number

	struct node *root = NULL; 		//used for storing root node
//	struct rb_node *rb_root = NULL; 	//used for storing root node in rb tree

	printf ("1.sorting technique \n");
	printf ("2.binary search insertion: \n");
	printf ("3.print_inorder \n");
	printf ("4.print_pre_order \n");
	printf ("5.print_post_order \n");
	printf ("6.print_level_order \n");
	printf ("7.delete element from binary tree \n");
	printf ("8.red black tree \n");
	printf ("0.exit \n");
	
	do {
		printf ("\nEnter the option to select the program : \n");
		scanf ("%d", &option);

		switch (option){
		
		case 0 :		//to get out of the program 
				break;
		case 1 :
				sort();
				break;		
		case 2 :		//to insert element into tree
				printf ("enter the NUMBER you want to insert : \n");
				scanf ("%d", &n);
				root = insert_tree(root, n);
				break;
		case 3 :		//print the elements of binary tree in IN_ORDER form
				printf ("elements in inorder_form is : \n");
				print_inorder(root);
				break;
		case 4 :		//print the elements of binary tree in PRE_ORDER form
				printf ("elements in pre_order_form is : \n");
				print_pre_order(root);
				break;
		case 5 :		//print the elements of binary tree in POST_ORDER form
				printf ("elements in post_order_form is : \n");
				print_post_order(root);
				break;
		case 6 :		//print the elements of binary tree in LEVEL_ORDER form
				printf ("elements in level_order_form is : \n");
				print_level_order(root);
				break;
		case 7 :		//delete the node in binary tree
				printf ("enter the number to delete : \n");
				scanf ("%d", &n);
				root = bst_delete_node(root, n);
				break;
		case 8 : 		//to insert node in rb tree
				rb_tree();
				break;

		default : 
				printf ("enter correct option \n");
				break;
		}

	}while (option != 0);

	return 0;
}


