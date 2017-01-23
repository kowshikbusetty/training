#include<stdio.h>
#include<string.h>
#define DEC 10

void main()
{
	char arr[10];
	int value = 0, i = 0;
	int flag = 1;
	int length;
	int ans = 0;

	scanf("%s",arr);
	
	while(ans != 1)
	{
		length = strlen(arr);
		i = 0;
		flag = 1;
		value = 0;
		while(arr[i] != '\0' && flag == 1)
		{
			if(i == 0 && (arr[i] == '+' || arr[i] == '-')){
				i++;
			} else{
				if(arr[i] == '.'){
					flag = 0;
					break;
				}else {
					if(arr[i] <= '9' && arr[i] >= '0'){
						value *= DEC;
						value += arr[i] - '0';
						i++;
					}else{
						flag = 0;
						break;
					}
				}
			}
		}
		if(i == length ){
			ans = 1;
			printf("%d \n",value);
		}else{
			printf("Invalid input..! Please enter valid input..! \n");
			scanf("%s",arr);
		}
	}
}
