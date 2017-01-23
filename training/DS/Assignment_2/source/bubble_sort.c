#include "../my_header_ds_2.h"

int bubble_sort(void)
{
	for (i = 0; i < (MAX - 1); i++){	//repeating the loop for no. of passes
		for (j = 0; j < (MAX -1 -i); j++){
			if (arr[j] > arr[j + 1]){
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}

	}

	return 0;
}
