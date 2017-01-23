#include "../my_header_ds_2.h"

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
	int pos = low;	//used as position for storing the elements in temp array
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
