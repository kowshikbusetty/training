#include <stdio.h>
#include <stdlib.h>
#define MAX 80

extern int my_atoi(char *);

struct node {
	int info;
	struct node *llink;
	struct node *rlink;
};

struct node * root = NULL;
struct node * p = NULL;

struct node * insert (struct node *, int);
struct node * bin_search_tree_del(struct node *, int);
void print_inorder(struct node *);

int main(void)
{
	char op[MAX];
	char num[MAX];
	char c;	

	printf ("1.to insert \n");
	printf ("2.delete \n");
	printf ("3.display inorder \n0.exit \n");

	do {
		printf ("enter the option : \n");
		if(NULL == (fgets (op, MAX, stdin))) {                    
				perror("fgets failed\n");                               
				exit(1);                                                
		}

		switch(my_atoi(op)){
		
		case 1 :
				printf ("enter the num to insert : \n");
				if(NULL == (fgets (num, MAX, stdin))) {
					   perror("fgets failed\n");
					   exit(1);
				 }      

				root = insert (root, my_atoi(num));
				break;
		case 2 :
				printf ("enter the number to delete : \n");
				 if(NULL == (fgets (num, MAX, stdin))) {
                       perror("fgets failed\n");
                       exit(1);
                 }

				root = bin_search_tree_del(root, my_atoi(num));
				break;

		case 3 :
				printf ("Indorder form is : \n");
				print_inorder(root);
				break;
		default :
				printf ("enter correct option \n");
				
		}
	
		printf("Do you want to continue (y or Y) : ");
		c = fgetc(stdin);
		getchar();
	} while (c == 'y' || c == 'Y');


	return 0;
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

struct node * insert(struct node * t, int n)
{
	if (t == NULL){
		if (NULL == (t = (struct node*) malloc (sizeof (struct node)))){
		perror ("node not created \n");
		exit (1);
		}

		t -> info = n;
		t -> llink = t -> rlink = NULL;
		root = t;
		return root;

	}else if (t -> info >= n){
		t -> llink = insert(t -> llink, n);
	
	}else if (t -> info < n){
		t -> rlink = insert(t -> rlink, n);

	}
	
	return t;
}

struct node * bin_search_tree_del(struct node * t, int num)
{
	struct node * node = NULL;
	
	if (t == NULL){
		return NULL;
	}else if (num > t -> info){
		t -> rlink = bin_search_tree_del(t -> rlink, num);
	}else if (num < t -> info){
		t -> llink = bin_search_tree_del(t -> llink, num);
	}else if (num == t -> info){
		if ((t -> rlink == NULL) && (t -> llink == NULL)) {
			free (t);
			return NULL;
		} else if ((t -> rlink != NULL) && (t -> llink == NULL)) {
			node = t -> rlink;
			free (t);
			return node;
		} else if ((t -> rlink == NULL) && (t -> llink != NULL)) {
			node = t -> llink;
			free (t);
			return node;
		} else if ((t -> rlink != NULL) && (t -> llink != NULL)) {
				p = t -> rlink;	
				node = t -> rlink;
				while (node -> llink) {
					node = node -> llink;
				}
				while ((p -> llink != node) && (p -> llink != NULL)) {
					p = p -> llink;
				}
				t -> info = node -> info;
				if (p -> llink) {
					p -> llink = bin_search_tree_del (node, node -> info);
				} else {
					t -> rlink = p -> rlink;
					free(p);
				}
		}
	} 
	return t;
}
