#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
	char item;
	struct node *next;
} node;

node *TOP = NULL;

int is_empty()
{
	if (TOP == NULL)
		return 1;
	else
		return 0;
}

int push(char input)
{
	node *element = (node *)malloc(sizeof(node));
	if (element == NULL)
	{
		printf("\n\t STACK IS FULL!!");
		return 0;
	}
	else
	{
		element->item = input;
		if (TOP == NULL)
		{
			TOP = element;
			TOP->next = NULL;
		}
		else
		{
			element->next = TOP;
			TOP = element;
		}
		printf("in\n");
		return 1;
	}
}

char get_top()
{
	if (is_empty())
	{
		return '\0';
	}
	else
	{
		return TOP->item;
	}
}

char pop()
{
	if (is_empty())
	{
		printf("\n\tSTACK IS EMPTY!");
		return -1;
	}
	else
	{
		char item = TOP->item;

		node *del = TOP;
		TOP = TOP->next;
		del->next = NULL;
		free(del);
		printf("out\n");
		return item;
	}
}

int main()
{
	char eq[500] = "()";
	printf("\nENTER EQUATION : ");
	scanf("%s", eq);

	int i, len = strlen(eq);

	for (i = 0; i < len; i++)
	{
		if (eq[i] == '(' || eq[i] == '{' || eq[i] == '[')
			push(eq[i]);
		else
		{
			if ((eq[i] == ')') && ('(' == get_top()))
				pop();
			if ((eq[i] == '}') && ('{' == get_top()))
				pop();
			if ((eq[i] == ']') && ('[' == get_top()))
				pop();
		}
	}

	if (is_empty())
	{
		printf("\n\tCORRECT\n");
	}
	else
	{
		printf("\n\tERROR\n");
	}
}