#include "../my_header_ds_2.h"

struct node *root = NULL; 		//used for storing root node
struct node * t = NULL;   		//used for other nodes
struct node * p = NULL;   		//used for other nodes

struct node * create_node(struct node *t, int n)
{
	if (NULL == (t = (struct node*) malloc (sizeof (struct node)))){
		perror ("node not created \n");
		exit (1);
	}                       
                                                                                                                                          
    t -> info = n; 
	t -> llink = t -> rlink = NULL;
	
	return t;
}
struct node * insert_tree(struct node * t, int n)
{
	if (t == NULL){
		t = create_node(t, n);
		root = t;
	}else if((t -> info) >= n){
		t -> llink = insert_tree(t -> llink, n);
	}else if ((t -> info) < n){
		t -> rlink = insert_tree(t -> rlink, n);
	}
	return t;
}		

void print_inorder(struct node *t)
{
	if (t == NULL) {
		return ;
	}
	print_inorder(t -> llink);
	printf ("%d \n", t -> info);
	print_inorder(t -> rlink);
}
void print_pre_order(struct node *t)
{
	if (t == NULL) {
		return ;
	}
	printf ("%d \n", t -> info);
	print_pre_order(t -> llink);
	print_pre_order(t -> rlink);
}
void print_post_order(struct node *t)
{
	if (t == NULL) {
		return ;
	}
	print_post_order(t -> llink);
	print_post_order(t -> rlink);
	printf ("%d \n", t -> info);
}


/* Function to print level order traversal a tree*/
void print_level_order(struct node* root)
{
	int h = height(root);//calculating height of a tree
	int i;
	for(i = 0; i < h; i++)
		printLevel(root, i);
	printf ("\n");
}     
 
/* Print nodes at a given level */
void printLevel(struct node* root, int level)
{
	if(root == NULL)
		return;
	if(level == 0)
		printf("%d ", root -> info);
	else if (level > 0)
	{
		printLevel(root -> llink, level - 1);
		printLevel(root -> rlink, level - 1);
	}
}
 
/* Compute the "height" of a tree */
int height(struct node* node)
{
   if (node == NULL)
       return 0;
   else
   {
     int lheight = height(node -> llink);
     int rheight = height(node -> rlink);
 
     if (lheight > rheight)
         return(lheight + 1);
     else 
		return(rheight + 1);
   }
} 


struct node* bst_delete_node (struct node* node, int num)
{
	if (node == NULL) {
		return NULL;
	} else if (node -> info > num) {
			node -> llink = bst_delete_node (node -> llink, num);
	} else if (node -> info < num) {
			node -> rlink = bst_delete_node (node -> rlink, num);
	} else if (node -> info == num) {
		if (node -> rlink == NULL && node -> llink == NULL) {
			free (node);
			return NULL;
		} else if (node -> rlink != NULL && node -> llink == NULL) {
			t = node -> rlink;
			free (node);
			return t;
		} else if (node -> rlink == NULL && node -> llink != NULL) {
			t = node -> llink;
			free (node);
			return t;
		} else if (node -> rlink != NULL && node -> llink != NULL) {
				p = node -> rlink;	
				t = node -> rlink;
				while (t -> llink ) {	//finding successor	
					t = t -> llink;
				}
				while (p -> llink != t && p -> llink != NULL) {
					p = p -> llink;
				}
				node -> info = t -> info;	//holding successor
				if (p -> llink) {
					p -> llink = bst_delete_node (t, t -> info);
				} else {
					node -> rlink = p -> rlink;
					free(p);
				}
		}
	} 
	return node;
}
