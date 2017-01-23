#include "../my_header_ds_2.h"

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
