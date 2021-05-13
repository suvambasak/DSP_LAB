#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct stk
{
	int data[SIZE];
	int top;
} s;

void push(int);
int pop();
void show();

int main()
{
	int item, job;
	s.top = -1;
	while (1)
	{
		printf("\n--------------------------------------------------\n");
		printf("Press 1 for push.\n");
		printf("Press 2 for pop.\n");
		printf("Press 3 for display.\n");
		printf("Press 4 for exit.");
		printf("\n--------------------------------------------------\n");
		printf("\nYour choice? : ");
		scanf("%d", &job);

		switch (job)
		{
		case 1:
			printf("\nGive the value for push : ");
			scanf("%d", &item);
			push(item);
			break;
		case 2:
			job = pop();
			printf("\nThe poped item is : %d", item);
			break;
		case 3:
			show();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("\nWRONG CHOICE !");
			break;
		}
	}
	return 0;
}

void push(int v)
{
	if (s.top == (SIZE - 1))
	{
		printf("\nTHE STACK IS FULL !");
	}
	else
	{
		s.data[++s.top] = v;
	}
}

int pop()
{
	int v;
	if (s.top == -1)
	{
		printf("\nTHE STACK IS EMPTY !");
		return 0;
	}
	else
	{
		v = s.data[s.top--];
		return v;
	}
}

void show()
{
	int i;
	printf("\nTHE DISPLAY IS : ");
	for (i = s.top; i >= 0; i--)
		printf("\n\t%d", s.data[i]);
}