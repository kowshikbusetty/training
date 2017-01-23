#include "../my_header_ds_2.h"

int selection_sort(void)
{
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

	return 0;
}
