#include <stdio.h>
#include <stdlib.h>

// Structure for each node.
typedef struct node
{
	int data;
	struct node *next;
} stack;

stack *top = NULL;

// Function to check STACK is empty.
int is_empty()
{
	if (NULL == top)
		return 1;
	else
		return 0;
}

// Function to push item into the STACK.
int push(int input)
{
	stack *element = (stack *)malloc(sizeof(stack));
	if (NULL == element)
	{
		printf("\n\t STACK IS FULL!!");
		return 0;
	}
	else
	{
		element->data = input;
		if (NULL == top)
		{
			top = element;
			top->next = NULL;
		}
		else
		{
			element->next = top;
			top = element;
		}
		return 1;
	}
}

// Function to pop item from the STACK.
int pop()
{
	if (is_empty())
	{
		printf("\n\tSTACK IS EMPTY!");
		return -1;
	}
	else
	{
		int item = top->data;

		stack *del = top;
		top = top->next;
		del->next = NULL;
		free(del);

		return item;
	}
}

// Function to display STACK content.
int stack_content()
{
	if (is_empty())
	{
		printf("\n\tSTACK IS EMPTY!");
		return 0;
	}
	else
	{
		stack *temp = top;
		printf("\nSTACK CONTENT : ");
		while (temp)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
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
		printf("\n4 STACK CONTENT");

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
			stack_content();
			break;
		default:
			printf("\nINVALID INPUT!");
		}
	}
	return 0;
}