#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
} *start1 = NULL, *start2 = NULL, *list1, *list2, *temp1, *temp2, *p;

void cr_node1()
{
	int con = 1;
	while (con)
	{
		p = (struct node *)malloc(sizeof(struct node));

		printf("\nEnter the 1st data : ");
		scanf("%d", &p->data);

		p->next = NULL;

		if (start1 == NULL)
		{
			start1 = p;
			list1 = p;
		}
		else
		{
			list1->next = p;
			list1 = p;
		}
		printf("\nDo you want to insert another node(1/0): ");
		scanf("%d", &con);
	}
}

void cr_node2()
{
	int con = 1;
	while (con)
	{
		p = (struct node *)malloc(sizeof(struct node));

		printf("\nEnter the 2nd data : ");
		scanf("%d", &p->data);

		p->next = NULL;

		if (start2 == NULL)
		{
			start2 = p;
			list2 = p;
		}
		else
		{
			list2->next = p;
			list2 = p;
		}
		printf("\nDo you want to insert another node(1/0): ");
		scanf("%d", &con);
	}
}

void display(struct node *start)
{
	if (start == NULL)
	{
		printf("\nNo data found for display !");
	}
	else
	{
		temp1 = start;
		printf("\nThe lined list is : ");
		while (temp1 != NULL)
		{
			printf("%d->", temp1->data);
			temp1 = temp1->next;
		}
		printf("NULL\n");
	}
}

void zig()
{
	temp1 = start1;
	temp2 = start2;

	while (temp1 != NULL)
	{

		p = temp1->next;

		temp1->next = temp2;
		temp1 = temp2;
		temp2 = temp2->next;
		temp1->next = p;
		temp1 = p;
	}
}

main()
{
	cr_node1();
	display(start1);

	cr_node2();

	display(start2);
	zig();
	display(start1);
}
