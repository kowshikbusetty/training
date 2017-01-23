#include "../header/myheader_ds_1.h"

int cir_arr[MAX];
int size = 0;
int cir_front = -1;
int cir_rear = -1;

int cir_queue(void)
{
	int ch;
	int num;
	
	do {
		printf("\n1.enqueue\n2.dequeue\n3.display\n"
								"0.exit\nenter your choice:\n");
		scanf("%d", &ch);

		switch (ch) {
			
		case 0:							//to come out of the program
				break;
		case 1:
				printf("enter the element to insert in the circular queue\n");
				scanf("%d", &num);
				cir_enqueue(num);
				break;
		case 2:
				cir_dequeue();
				break;
		case 3:
				cir_display();
				break;
		default:
				printf("enter the valid option\n");
				break;
		}
	} while (ch != 0);
	
	return 0;
}

int cir_isfull(void)
{
	return ((cir_front == 0 && cir_rear == (MAX - 1)) || (cir_rear == (cir_front - 1))) ? 1 : 0;
}

int cir_isempty(void)
{
	return (cir_front == -1 && cir_rear == -1) ? 1 : 0;
}

void cir_enqueue(int num)
{
	if(cir_isfull()) {

		printf("Queue is full\n");
		return;

	} else if(-1 ==  cir_front && -1 ==  cir_rear) {
			cir_front = cir_rear = 0;
	} else {
			(cir_rear == (MAX -1)) ? (cir_rear = 0) : (cir_rear++);
	}
			cir_arr[cir_rear] = num;
}

void cir_dequeue(void)
{
	if(cir_isempty()) {
		printf("Queue is empty");
		return;
	} else if(cir_front == cir_rear) {
		printf("deleted element in is : %d ", cir_arr[cir_front]);
		cir_front = cir_rear = -1;
	} else {
		printf("deleted element is : %d ", cir_arr[cir_front]);
		cir_front++;
	}
}

void cir_display(void)
{
	int i = cir_front;
	if(cir_isempty()) {
		printf("Queue is empty \n");
		return;
	} else if(cir_front <= cir_rear) {
		while(i <= cir_rear) {
			printf("arr[%d] : %d\n", i , cir_arr[i]);
			i++;
		}
	} else {
		while(i != MAX) {
			printf("arr[%d] : %d\n", i, cir_arr[i]);
			i++;
		}
			i = 0;
			while(i <= cir_rear) {
				printf("arr[%d] : %d\n", i, cir_arr[i]);
				i++;
			}
	}
}
