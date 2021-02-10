#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int stack[SIZE], top = -1;

//  Function to check STACK is full.
int is_full()
{
	if (SIZE - 1 == top)
		return 1;
	else
		return 0;
}

// Function to check STACK is empty.
int is_empty()
{
	if (-1 == top)
		return 1;
	else
		return 0;
}

// Function to push item into the STACK.
void push(int item)
{
	if (is_full())
	{
		printf("\n\tSTACK OVERFLOW!");
		return;
	}
	stack[++top] = item;
}

// Function to pop item from the STACK.
int pop()
{
	if (is_empty())
	{
		printf("\n\tSTACK UNDERFLOW!");
		return -1;
	}
	return stack[top--];
}

// Function to display STACK content.
int stack_content()
{
	if (is_empty())
	{
		printf("\n\tSTACK EMPTY");
		return 0;
	}
	else
	{
		int i;
		printf("\nSTACK CONTENTS : ");
		for (i = 0; i <= top; i++)
			printf(" %d", stack[i]);

		return 1;
	}
}

// Main function.
int main()
{
	int choice, input;
	while (1)
	{
		// Options
		printf("\n<<<<<<<<<<<<<<< OPTIONS >>>>>>>>>>>>>>>>");
		printf("\n1 PUSH");
		printf("\n2 POP");
		printf("\n3 CHECK EMPTY");
		printf("\n4 CHECK FULL");
		printf("\n5 STACK DISPLAY");

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
			push(input);
			break;
		case 2:
			printf("\nITEM POPED : %d", pop());
			break;
		case 3:
			if (is_empty())
				printf("\n\tSTACK IS EMPTY!");
			else
				printf("\n\tSTACK IS NOT EMPTY!");
			break;
		case 4:
			if (is_full())
				printf("\n\tSTACK IS FULL!");
			else
				printf("\n\tSTACK NOT FULL!");
			break;
		case 5:
			stack_content();
			break;
		default:
			printf("\nINVALID INPUT!");
		}
	}
	return 0;
}