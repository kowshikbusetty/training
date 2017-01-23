#include "../my_header_ds_2.h"

int insertion_sort(void)
{
	for (i = 1; i < (MAX); i++){	//repeating the loop for no. of passes
		temp = arr[i];
		for( j = i; (j > 0) && (arr[j - 1] > temp); j--){
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
	return 0;
}
