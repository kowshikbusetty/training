#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define MIN 0
//int arr[MAX] = {37, 61, 12, 28, 100, 42, 95, 36, 6, 10};
//int arr[MAX] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//int arr[MAX];

unsigned short int i, j;
unsigned short int min;
int temp;

void merge(int [], int [], int, int, int);
void merge_sort(int [], int [], int, int);
void quick_sort(int[], int, int);
int partition(int[], int, int);

struct node {                                                                 
    struct node *rlink;                                                       
    int info;                                                                   
    struct node *llink;                                                       
};                                                                              
void print_inorder(struct node *);
void print_pre_order(struct node *);
void print_level_order(struct node *);
void print_post_order(struct node *);
struct node * insert_tree(struct node *, int);
struct node * create_node(struct node *, int);


struct node *root = NULL;                                           
struct node * t = NULL;                                                       
//struct node * parent = NULL;                                                       
                                                                                                                
//experiment 1 : selection sort
#if 0
int main(void)
{
	printf ("elements before sorting are : \n");	
	for (i = 0; i < MAX; i++)
		printf ("%d \n", arr[i]);

	for (i = 0; i < (MAX - 1); i++){	//repeating the loop for no. of passes
		min = i;
		for (j = i + 1; j < MAX; j++){
			if (arr[min] > arr[j]){
				min = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}

	printf ("elements after sorting are : \n");	
	for (i = 0; i < MAX; i++)
		printf ("%d \n", arr[i]);

	return 0;
}
#endif

//experiment 2 : bubble sort
#if 0
int main(void)
{
	printf ("elements before sorting are : \n");	
	for (i = 0; i < MAX; i++)
		printf ("%d \n", arr[i]);

	for (i = 0; i < (MAX - 1); i++){	//repeating the loop for no. of passes
		for (j = 0; j < (MAX -1 -i); j++){
			if (arr[j] > arr[j + 1]){
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}

	}
	printf ("elements after sorting are : \n");	
	for (i = 0; i < MAX; i++)
		printf ("%d \n", arr[i]);

	return 0;
}
#endif

//experiment 3 : insertion sort
#if 0
int main(void)
{
	printf ("elements before sorting are : \n");	
	for (i = 0; i < MAX; i++)
		printf ("%d \n", arr[i]);

	for (i = 1; i < (MAX); i++){	//repeating the loop for no. of passes
		temp = arr[i];
		for( j = i; (j > 0) && (arr[j - 1] > temp); j--){
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
	printf ("elements after sorting are : \n");	
	for (i = 0; i < MAX; i++)
		printf ("%d \n", arr[i]);

	return 0;
}
#endif
#if 0
int sort[MAX];
int main(void)
{

	printf ("elements before sorting are : \n");	
	for (i = 0; i < MAX; i++)
		printf ("%d \n", arr[i]);

	merge_sort(arr, sort, MIN, (MAX - 1));

	printf ("elements after sorting are : \n");	
	for (i = 0; i < MAX; i++)
		printf ("%d \n", arr[i]);

	return 0;
}

void merge_sort(int arr[], int sort[], int low, int up)
{
	int mid;

	if (up > low){
		mid = (low + up) / 2;

		merge_sort(arr, sort, low, mid);
		merge_sort(arr, sort, (mid + 1), up);
		merge(arr, sort, low, mid, up);
	}
}

void merge(int arr[], int sort[], int low, int mid, int up)
{
	int i;
	int pos = low;
	int low_end = mid;
	int mid1 = mid + 1;
	int num_ele = up - low + 1;

	while( (low <= low_end) && (mid1 <= up)){
		if (arr[low] <= arr[mid1]){
			sort[pos++] = arr[low++];
		}else{ 
			sort[pos++] = arr[mid1++];
		}
	}

	while (mid1 <= up){
		sort[pos++] = arr[mid1++];
	}

	while (low <= low_end){
		sort[pos++] = arr[low++];
	}
	for ( i = 0; i <= num_ele; i++){
		arr[up] = sort[up];
		up = up - 1;
	}
}
#endif
#if 0
int main(void)
{
	int a[MAX];
	printf ("enter the array: \n");                                             
	for (i = 0; i < MAX; i++)                                                   
		scanf ("%d", (a + i));

	printf ("elements before sorting are : \n");	
	for (i = 0; i < MAX; i++)
		printf ("%d \n", a[i]);

	quick_sort(a, MIN, (MAX - 1));

	printf ("elements after sorting are : \n");	
	for (i = 0; i < MAX; i++)
		printf ("%d \n", a[i]);	

	return 0;
}

void quick_sort(int a[], int low, int high)
{
	int pivot = a[low];
	int i = low + 1;
	int j = high;

	if (low < high){
		while (i <= j){
			while((a[i] < pivot) && (i <= high)){
				i++;
			}
			while(a[j] > pivot && (j >= low)){
				j--;
			}

			if (i < j){

				a[i] = a[i] + a[j];
				a[j] = a[i] - a[j];
				a[i] = a[i] - a[j];	
				i++;
				j--;
			}else if (i > j){
				i++;
			} else {
				break;
			}
		}

/*		a[j] = a[low] + a[j];
		a[low] = a[j] - a[low];
		a[j] = a[j] - a[low];	
*/
		temp = a[low];
		a[low] = a[j];
		a[j] = temp;

		quick_sort(a, low, j - 1);
		quick_sort(a, j + 1, high);
	}

}
#endif

int main (void)
{
	unsigned int option;
	int n;          //used to insert the number

	printf ("1.sorting technique \n");
	printf ("2.binary search insertion \n");
	printf ("3.print_inorder \n");
	printf ("4.print_pre_order \n");
	printf ("5.print_post_order \n");
	printf ("6.print_level_order \n");
	printf ("0.exit \n");
	
	do {
		printf ("\nEnter the option to select the program : \n");
		scanf ("%d", &option);

		switch (option){
		
		case 0 :		//to get out of the program 
				break;
		case 1 :sort();	//to select sorting techniques
				break;		
		case 2 :		//to insert element into tree
				printf ("enter the NUMBER you want to insert : \n");            
                scanf (" %d", &n);
				root = insert_tree(root, n);
				break;
		case 3 :
				printf ("elements in inorder_form is : \n");
				print_inorder(root);
				break;
		case 4 :
				printf ("elements in pre_order_form is : \n");
				print_pre_order(root);
				break;
		case 5 :
				printf ("elements in post_order_form is : \n");
				print_post_order(root);
				break;
		case 6 :
				printf ("elements in level_order_form is : \n");
				printf ("%d \n", root -> info);
				print_level_order(root);
				break;

		default : 
				printf ("enter correct option \n");
				break;
		}

	}while (option != 0);

	return 0;
}

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
	if (t != NULL){
		print_inorder(t -> llink);
		printf ("%d \n", t -> info);
		print_inorder(t -> rlink);
	}
}
void print_pre_order(struct node *t)
{
	if (t != NULL){
		printf ("%d \n", t -> info);
		print_pre_order(t -> llink);
		print_pre_order(t -> rlink);
	}
}
void print_post_order(struct node *t)
{
	if (t != NULL){
		print_post_order(t -> llink);
		print_post_order(t -> rlink);
		printf ("%d \n", t -> info);
	}
}
void print_level_order(struct node *t)
{
	while ((t -> llink != NULL) && (t -> rlink != NULL)){
		printf ("%d \n", t -> llink -> info);
		printf ("%d \n", t -> rlink -> info);
		print_level_order(t -> llink);
		print_level_order(t -> rlink);
	}
}
