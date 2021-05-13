#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int queue[SIZE], front = -1, rear = -1;

int main(int argc, char const *argv[])
{
	int choice, input;
	while (1)
	{

		printf("\n<<<<<<<<<<<<<<< OPTIONS >>>>>>>>>>>>>>>>");
		printf("\n1 ENQUEUE");
		printf("\n2 DEQUEUE");
		printf("\n3 CHECK EMPTY");
		printf("\n4 CHECK FULL");
		printf("\n5 NUMBER OF ITEMS INSIDE");
		printf("\n6 STACK CONTENT");

		printf("\n\n0 EXIT\n");

		printf("---------------------------------------");

		printf("\nENTER CHOICE : ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 0:
			exit(1);
		case 1:
			// printf("\nENTER ITEM : ");
			// scanf("%d",&input);
			// enqueue(input);
			break;
		case 2:
			// printf("\nITEM POPED : %d",dequeue());
			break;
		case 3:
			// if(is_empty())
			// 	printf("\n\tQUEUE IS EMPTY!");
			// else
			// 	printf("\n\tQUEUE IS NOT EMPTY!");
			break;
		case 4:
			// if(is_full())
			// 	printf("\n\tQUEUE IS FULL!");
			// else
			// 	printf("\n\tQUEUE NOT FULL!");
			break;
		case 5:
			// printf("\nNUMBER OF ITEM INSIDE : %d",items_inside());
			break;
		case 6:
			queue_content();
			break;
		default:
			printf("\nINVALID INPUT!");
		}
	}
	return 0;
}