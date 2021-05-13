#include <stdio.h>
#include <stdlib.h>

struct link
{
	struct link *left, *right;
	int data;
} *root = NULL;

struct link *insert(struct link *root, int x)
{
	if (root == NULL)
	{
		root = (struct link *)malloc(sizeof(struct link));
		root->data = x;
		root->left = root->right = NULL;
	}
	else if (x < root->data)
		root->left = insert(root->left, x);
	else if (x >= root->data)
		root->right = insert(root->right, x);

	return (root);
}

inorder(struct link *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%3d", root->data);
		inorder(root->right);
	}
}

main()
{
	int choice, value;
	while (1)
	{
		printf("\n----------------------------------------\n");
		printf("\n Press 1 for insert.");
		printf("\n Press 2 for in-order display.");
		printf("\n Press 3 for exit.");
		printf("\n----------------------------------------");
		printf("\nEnter your choice : ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("\nEnter data for insert : ");
			scanf("%d", &value);
			root = insert(root, value);
			break;
		case 2:
			printf("\nIn-Order Display : ");
			inorder(root);
			break;
		case 3:
			exit(1);
		default:
			printf("\nInvalid choice !");
			break;
		}
	}
}