#include "../my_header_ds_2.h"

struct rb_node * rb_root = NULL;       //used for storing root rb_node

void leftRotate(struct rb_node *rb_t)
{
	struct rb_node *rb_q;

	rb_q = rb_t -> right;  //Set rb_q
	rb_t -> right = rb_q -> left; // Turn rb_q's left subtree into rb_t's right subtree

	if( rb_q -> left != NULL){
		rb_q -> left -> parent = rb_t; //Bridge the rb_q's left sublink
	}

	rb_q -> parent = rb_t -> parent; //Bridge rb_t's old parent and rb_q's parent
	if( rb_t -> parent == NULL){
		rb_root = rb_q;
	}else if( rb_t -> data == (rb_t -> parent -> left -> data)){
		rb_t -> parent -> left = rb_q; //Bridge rb_t's old parent's left or right child
	}else 
		rb_t -> parent -> right = rb_q;

	rb_q -> left = rb_t; //put rb_t on rb_q's left
	rb_t -> parent = rb_q; //Take care of rb_t's parent

	return;
}

void rightRotate(struct rb_node *rb_t)
{
	struct rb_node *rb_q;

	rb_q = rb_t -> left; //set rb_q
	rb_t -> left = rb_q -> right; //Turn rb_q's right subtree into rb_t's left subtree

	if ( rb_q -> right != NULL){
		rb_q -> right -> parent = rb_t;
	}

	rb_q -> parent = rb_t -> parent; //Bridge rb_t's old parent and rb_q's parent
	if( rb_t -> parent == NULL){
		rb_root = rb_q;
	}else if( rb_t -> data == rb_t -> parent -> left -> data){
		rb_t -> parent -> left = rb_q; //Bridge rb_t's old parent's left or right child
	}else
		rb_t -> parent -> right = rb_q;

	rb_q -> right = rb_t; //put rb_t on rb_q's right
	rb_t -> parent = rb_q; //Take care of rb_t's parent

	return;
}

                                                                               
void rbInsert(int val)
{
	struct rb_node * rb_t;	
	struct rb_node * rb_p = NULL;	
	struct rb_node * rb_q = NULL;	

    if (NULL == (rb_t = (struct rb_node*) malloc (sizeof (struct rb_node)))){
        perror ("rb_node not created \n");
        exit (1);
    }
    rb_t -> data = val;
    rb_t -> left = NULL;
	rb_t -> right = NULL;
	rb_t -> color = 'r';

	rb_p = rb_root;	//holding root address used for traversing in tree

	if(rb_root == NULL){
		rb_root = rb_t;
		rb_root -> color = 'b';
		return;
	}
	while (rb_p != NULL){
		rb_q = rb_p;		//hold the address of parent
		
		if(rb_t->data < rb_p->data)
			rb_p = rb_p -> left;	//moving into left branch
		else
			rb_p = rb_p -> right;	//moving into right branch

	}
	rb_t -> parent = rb_q;			//assigning the parent

	if(rb_q == NULL){				//adding data into tree
		rb_root = rb_t;
	}else if(rb_t -> data < rb_q -> data){
		rb_q -> left = rb_t;
	}else{
		rb_q -> right = rb_t;	
	}
	rbInsertFix(rb_t);
	
	return;
}


void rbInsertFix(struct rb_node * rb_t)
{
	struct rb_node * rb_q = NULL;//used for holding address of uncle

	while ((rb_t -> parent -> color) == 'r'){	//if parent is red
		if ((rb_t -> parent -> data) == (rb_t->parent->parent->left->data)) {//used for finding which branch (left or right)

			rb_q = (rb_t->parent->parent->right);//used for holding the uncle address present in right branch
				
			if (rb_q->color == 'r'){	//if uncle color is red
				rb_t->parent->color = 'b';//changing parent to black
				rb_q -> color = 'b';		  //changing uncle to black
				(rb_t->parent->parent->color) = 'r';//making grand parent as red
//				rb_t = rb_t -> parent -> parent;
			}else{						//if uncle is black 
				if (rb_t -> data == rb_t -> parent -> right -> data){
//		            rb_t = rb_t -> parent;
   			        leftRotate(rb_t->parent);
//				rb_t->parent = rb_t->parent;
				}
				(rb_t->parent->color) = 'b';
				(rb_t->parent->parent->color) = 'r';
				rightRotate((rb_t->parent->parent));
				}

		}else {
				rb_q = (rb_t -> parent -> parent -> left);//used for holding the address of uncle present in left branch

				if (rb_q -> color == 'r'){	//if uncle is red
					rb_t -> parent -> color = 'b';//changing parent to black
					rb_q -> color = 'b';//changing uncle to black
					(rb_t -> parent -> parent -> color) = 'r';//changing grand parent to red
					rb_t = rb_t -> parent -> parent;
				}else{ 
					if (rb_t -> data == (rb_t->parent->left->data)){
//						rb_t = rb_t -> parent;
						rightRotate(rb_t->parent);
        			}
					(rb_t->parent->color) = 'b';
					(rb_t->parent->parent->color) = 'r';
					leftRotate((rb_t -> parent ->parent));
					}
		}
	}
	rb_root -> color = 'b';

	return;
}

void inorderTree(struct rb_node* rb_root)
{
	struct rb_node * x = rb_root;

	if (x != NULL){
		inorderTree(x -> left);
		printf(" %d-%c ",x -> data, x -> color);
		inorderTree(x -> right);
	}
	return;
}

int rb_tree(void)
{
	unsigned short int loop = 1;
    unsigned short int choice;
    int val;

	while(loop){
		printf("\nRed Black Tree Management - Enter your choice : ");
		printf("\n1.Insert into RBT\n2.Display RBT inorder\n");
		scanf("%hi",&choice);
			switch(choice){
				case 1:
						printf("\nEnter the integer you want to add : ");
						scanf("%d",&val);
						rbInsert(val);
						break;

				case 2:
						printf("\nInorder tree traversal left-root-right\n");
						inorderTree(rb_root);
						break;

				default:
						printf("\nInvalid Choice\n");
						break;
			}
		printf("\nPress '0' to terminate and '1' to continue : ");
		scanf("%hi",&loop);
	}

	return 0;
}
