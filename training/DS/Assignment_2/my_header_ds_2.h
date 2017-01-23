#ifndef _MY_HEADER_DS_2
#define _MY_HEADER_DS_2

#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define MIN 0
#define MAX_SIZE 256

int arr[MAX];	//used in sorting techniques

unsigned short int i, j;		//used in loops
unsigned short int min;	//used for storing minimum position in selection sort
int temp;		//used for swapping the values
int option;

int  int_valid(char *);

int sort(void);
int selection_sort(void);
int bubble_sort(void);
int insertion_sort(void);
void merge(int [], int [], int, int, int);
void merge_sort(int [], int [], int, int);
void quick_sort(int[], int, int);
int partition(int[], int, int);

int rb_tree(void);

struct node {                                                                 
    struct node *rlink;                                                       
    int info;                                                                   
    struct node *llink;                                                       
};			//used in binary tree

struct rb_node {                                                                 
    struct rb_node *right;
    int data;                                                                   
    struct rb_node *left;
	struct rb_node *parent;
	char color;
};			//used in rb tree

struct node * insert_tree(struct node *, int);
struct node * create_node(struct node *, int);
struct node* bst_delete_node (struct node* , int);

void print_inorder(struct node *);
void print_pre_order(struct node *);
void print_level_order(struct node *);
void print_post_order(struct node *);

void printLevel(struct node*, int);
int height(struct node*);

void rbInsertFix(struct rb_node *);
void inorderTree(struct rb_node*);
void rbInsert(int);
#endif
