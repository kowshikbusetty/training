#include "../my_header_ds_2.h"

int sort(void)
{
	int sort[MAX];	//used in merge sort
	int a[MAX];		//used in quick sort

	unsigned int op;
	printf ("1.Selection sort \n");
	printf ("2.Bubble sort \n");
	printf ("3.Insertion sort \n");
	printf ("4.Merge sort \n");
	printf ("5.Quick sort \n");
	printf ("0.Exit \n");

	do {
		printf ("\nEnter the option to select the sorting technique : \n");
		scanf ("%d", &op);

		if((op != 5) && (op != 0)){ //if not quick sort
			printf ("enter the array: \n");                                             
			for (i = 0; i < MAX; i++)                                                   
				scanf ("%d", (arr + i));

			printf ("elements before sorting are : \n");	
			for (i = 0; i < MAX; i++)
				printf ("%d \n", arr[i]);

		}else if((op == 5) && (op != 0)){
			printf ("enter the array: \n");                                             
			for (i = 0; i < MAX; i++)                                                   
				scanf ("%d", (a + i));

			printf ("elements before sorting are : \n");	
			for (i = 0; i < MAX; i++)
				printf ("%d \n", a[i]);
		}	

		switch (op){
		
		case 0 :		//to get out of the program 
				break;
		case 1 : 
				selection_sort();
				break;
		case 2 : 
				bubble_sort();
				break;
		case 3 : 
				insertion_sort();
				break;
		case 4 :
				merge_sort(arr, sort, MIN, (MAX - 1)); 
				break;
		case 5 :
				quick_sort(a, MIN, (MAX - 1));
				break;
		default : 
				printf ("enter correct sorting techinique \n");
				break;
		}

		if(((op == 1) || (op == 2) || (op == 3) || (op == 4)) && (op != 0)){
		printf ("elements after sorting are : \n");	
		for (i = 0; i < MAX; i++)
			printf ("%d \n", arr[i]);
		}else if((op == 5) && (op != 0)){
			printf ("elements after sorting are : \n");	
			for (i = 0; i < MAX; i++)
				printf ("%d \n", a[i]);	
		}
	
	}while(op != 0);

	return 0;
}

