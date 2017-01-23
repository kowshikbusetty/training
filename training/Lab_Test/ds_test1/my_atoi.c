# include <stdio.h>
int my_strlen(char *);

int my_atoi(char *arr)
{
	int value = 0;
	int i ;
	int length;
	i = 0;
	length = my_strlen(arr);

	while(arr[i] != '\n')	{
		if (arr[i] == '+' || arr[i] == '-') {
			i++;
		} else	{
			if(arr[i] == '.') {
				return 0;
			} else {
				while(arr[i] != '\n') {
					if(arr[i] >= 48 && arr[i] <= 57) {
						value *= 10;
						value += arr[i] - 48;
						i++;
					} else {
						printf("Invalid input..! Please enter valid input\n");
						return 0;
					}
				}
			}
		}

		if(i == length ) {
			printf("%d\n", value);
			return value;
		} else 	{
			printf("Invalid input PLEASE ENTER VALID INPUT \n");
			return 0;
		}
	}		
	return 0;
}
