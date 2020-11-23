#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

//  Function to check STACK is full.
int is_full(int *top)
{
	if (*top == SIZE - 1)
		return 1;
	else
		return 0;
}

// Function to check STACK is empty.
int is_empty(int *top)
{
	if (*top == -1)
		return 1;
	else
		return 0;
}

// Function to push item into the STACK.
void push(int *stack, int *top, int item)
{
	if (is_full(top))
	{
		printf("\n\tSTACK OVERFLOW!");
		return;
	}
	*top = (*top + 1);
	stack[*top] = item;
}

// Function to pop item from the STACK.
int pop(int *stack, int *top)
{
	if (is_empty(top))
	{
		printf("\n\tSTACK UNDERFLOW!");
		return -1;
	}
	int item;
	item = stack[*top];
	*top = (*top - 1);
	return item;
}

int main()
{
	int stack1[SIZE], top1 = -1;
	int stack2[SIZE], top2 = -1;

	int choice, input;
	while (1)
	{
		// Options
		printf("\n<<<<<<<<<<<<<<< OPTIONS >>>>>>>>>>>>>>>>");
		printf("\n1 ENQUEUE");
		printf("\n2 DEQUEUE");
		printf("\n\n0 EXIT\n");

		printf("---------------------------------------");

		printf("\nENTER CHOICE : ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 0:
			exit(1);
		case 1:
			printf("\nENTER ITEM : ");
			scanf("%d", &input);
			if (is_full(&top1))
			{
				printf("\n\tOVERFLOW!");
			}
			else
			{
				push(stack1, &top1, input);
			}
			break;
		case 2:
			if (!is_empty(&top2))
			{
				printf("\nITEM POPED : %d", pop(stack2, &top2));
			}
			else
			{
				if (!is_empty(&top1))
				{
					while (!is_empty(&top1))
					{
						push(stack2, &top2, pop(stack1, &top1));
					}
					printf("\nITEM POPED : %d", pop(stack2, &top2));
				}
				else
				{
					printf("\n\tUNDERFLOW!");
				}
			}
			break;
		default:
			printf("\nINVALID INPUT!");
		}
	}

	return 0;
}