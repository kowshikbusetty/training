#include "myheader_ds_3.h"

int main(void)
{
	int arr[MAX];
	int i;				//used in loops
	int option;			//to select searching technique
	int search;			//to store the searching integer
	int pos = -1;			//to catch the position of searching element in the array
		
	printf ("enter the array: \n");
	for (i = 0; i < MAX; i++)
		scanf ("%d", (arr + i));

	do{			//repeating the execution of program untill user want to exit

		printf ("\nEnter the option to select searching technique: \n");
		printf ("1. Sequential search \n");
		printf ("2. Binary search \n");
		printf ("3. Binary search using reccursion \n");
		printf ("0. Exit \n");

		scanf ("%d", &option);

		switch (option){		//to execute selected searching technique

		case 0 :				//to exit from program
				break;	

		case 1 :
				printf ("enter the integer you want to search : \n");
				scanf ("%d", &search);
				pos = sequential_search(arr, search);	//execute sequential searching logic
				break;
		case 2 :
				printf ("enter the integer you want to search : \n");
				scanf ("%d", &search);
				pos = binary_search(arr, search, MIN, (MAX - 1));
				break;
		
		case 3 :
				printf ("enter the integer you want to search : \n");
				scanf ("%d", &search);
				binary_rec_search(arr, search, MIN, (MAX - 1));
				break;
		
		default : 
				printf ("enter correct option to select searching technique \n");
				break;
		}

		if ((option != 0) && (option != 3)){//not to print the position for binary search recursion & to exit
			if(-1 == pos){
				printf ("searching element not found \n");
			}else {
				printf ("element found at position : arr[%d] = %d \n", 
																pos, arr[pos]);
	
			}
		}

	}while (option != 0);
	
	return 0;
}

int sequential_search (int arr[], int search)
{
	int i;	//used for traversing in array
	
	for (i = 0; arr[i] != '\0'; i++){
		if (search == arr[i]){
			return i;
		}
	}
			
	return -1;
}

int binary_search(int arr[], int search, int low, int high)
{
	int mid;

	while (low < high){
		
		mid = (low + high) / 2;

		if (search > arr[mid])	
			low = mid + 1;
		else if (search < arr[mid])
			high = mid - 1;
		else
			return mid;
	}

	return -1;
}
void binary_rec_search(int arr[], int search, int low, int high)
{
	int mid = (low + high) / 2;

	if (low <= high){
		if (search == arr[mid]){
			printf ("element found at arr[%d] = %d \n", mid, arr[mid]);
		}else if ((search > arr[mid]) && (mid <= high)){
			binary_rec_search(arr, search, mid + 1, high);
		}else if ((search < arr[mid]) && (mid >= low)){
			binary_rec_search(arr, search, low, mid - 1);
		}
	}else{ 
		printf ("element not found \n");
	}
}
