// Compile with -lm flag :   $ cc infix_to_postfix.c -lm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define SIZE 100

// Number stack and Operator stack.
char op_stack[SIZE];
int num_stack[SIZE];
int op_top = -1, num_top = -1;

// Node structure for holding expression.
typedef struct node
{
	int flg;
	int num;
	struct node *next;
} node;

// Node structure for tree node.
struct tree_node
{
	struct tree_node *left, *right;
	int flg;
	int data;
} *root = NULL;

// Node structure for stack for pushing tree.
typedef struct stack_node
{
	struct tree_node *addr;
	struct stack_node *next;
} STACK;

// Tree stack and linked list.
STACK *top = NULL;
node *HEAD = NULL;

// Function to check tree stack is empty or not.
int is_adr_empty()
{
	if (top == NULL)
		return 1;
	else
		return 0;
}

// Function to push tree node into the stack.
int adr_push(struct tree_node *input)
{
	STACK *element = (STACK *)malloc(sizeof(STACK));
	if (element == NULL)
	{
		printf("\n\t STACK IS FULL!!");
		return 0;
	}
	else
	{
		element->addr = input;
		if (top == NULL)
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

// Function to pop tree node from the stack.
struct tree_node *adr_pop()
{
	if (is_adr_empty())
	{
		printf("\n\tSTACK IS EMPTY!");
		return NULL;
	}
	else
	{
		struct tree_node *item = top->addr;

		STACK *del = top;
		top = top->next;
		del->next = NULL;
		free(del);

		return item;
	}
}

// Linkedlist insert function.
int insert(int value, int flag)
{
	node *p = (node *)malloc(sizeof(node));
	p->next = NULL;
	p->flg = flag;
	p->num = value;

	if (HEAD == NULL)
	{
		HEAD = p;
		p = NULL;
	}
	else
	{
		// Adding node at the end.
		node *temp = HEAD;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = p;
		p = NULL;
		temp = NULL;
	}
	return 1;
}

// Function to to build expression tree.
int buildexpressiontree()
{
	if (HEAD == NULL)
	{
		printf("\n\tLIST IS EMPTY!!");
		return 0;
	}
	else
	{
		node *temp = HEAD;

		while (temp != NULL)
		{
			if (temp->flg)
			{
				// For operator create a node.
				struct tree_node *new_node = (struct tree_node *)malloc(sizeof(struct tree_node));
				new_node->data = temp->num;
				new_node->flg = temp->flg;
				new_node->left = NULL;
				new_node->right = NULL;

				// Pop two node from the stack.
				struct tree_node *r = adr_pop();
				struct tree_node *l = adr_pop();

				// Add left and right to the operator node.
				new_node->left = l;
				new_node->right = r;

				// Push the operator node into the stack.
				adr_push(new_node);
			}
			else
			{
				// for operand create a node.
				struct tree_node *new_node = (struct tree_node *)malloc(sizeof(struct tree_node));
				new_node->data = temp->num;
				new_node->flg = temp->flg;
				new_node->left = NULL;
				new_node->right = NULL;

				// Push the node into the stack.
				adr_push(new_node);
			}
			temp = temp->next;
		}
		return 1;
	}
}

//  Function to check number STACK is full.
int is_numstk_full()
{
	if (num_top == SIZE - 1)
		return 1;
	else
		return 0;
}

//  Function to check number STACK is empty.
int is_numstk_empty()
{
	if (num_top == -1)
		return 1;
	else
		return 0;
}

// Function to push item into the number STACK.
void push_numstk(int item)
{
	if (is_numstk_full())
	{
		printf("\n\tSTACK OVERFLOW!");
		return;
	}
	num_stack[++num_top] = item;
}

// Function to pop item from the number STACK.
int pop_numstk()
{
	if (is_numstk_empty())
	{
		printf("\n\tSTACK UNDERFLOW!");
		return -1;
	}
	return num_stack[num_top--];
}

//  Function to check operator STACK is empty.
int is_opstk_empty()
{
	if (op_top == -1)
		return 1;
	else
		return 0;
}

//  Function to check operator STACK is full.
int is_opstk_full()
{
	if (op_top == SIZE - 1)
		return 1;
	else
		return 0;
}

// Function to push item into the operator STACK.
void push_opstk(char item)
{
	if (is_opstk_full())
	{
		printf("\n\t OP STACK OVERFLOW!");
		return;
	}
	op_stack[++op_top] = item;
}

// Function to pop item from the operator STACK.
char pop_opstk()
{
	if (is_opstk_empty())
	{
		printf("\n\t OP STACK UNDERFLOW!");
		return -1;
	}
	return op_stack[op_top--];
}

// Function to get top element of the stack with out poping.
char get_top()
{
	if (is_opstk_empty())
	{
		return 0;
	}
	else
	{
		return op_stack[op_top];
	}
}

// Function for precedence of operator.
int get_precedence(char ch)
{
	switch (ch)
	{
	case '^':
		return 3;
	case '*':
		return 2;
	case '/':
		return 2;
	case '+':
		return 1;
	case '-':
		return 1;
	default:
		return 0;
	}
}

// Function to check input char is a operator.
int is_operator(char ch)
{
	if (
		ch == '^' ||
		ch == '+' ||
		ch == '-' ||
		ch == '*' ||
		ch == '/')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// Function to conver infix expression to postfix expression.
void infix_to_postfix(char *infix)
{
	for (int i = 0; i < strlen(infix); i++)
	{
		// If the input is the digit.
		if (isdigit(infix[i]))
		{
			int d = infix[i] - '0';
			// More the one digit in the number.
			while (isdigit(infix[i + 1]))
			{
				d *= 10;
				d += infix[i + 1] - '0';
				i++;
			}
			insert(d, 0);
		}
		else
		{
			// When first operator found.
			if (is_opstk_empty())
			{
				push_opstk(infix[i]);
			}
			else
			{
				// When open bracket found.
				if (infix[i] == '(')
				{
					push_opstk(infix[i]);
				}
				// When Closing bracket found.
				else if (infix[i] == ')')
				{
					while (get_top() != '(')
					{
						insert(pop_opstk(), 1);
					}
					pop_opstk();
				}
				else
				{
					// When precedence of operator stack top and input char is same.
					if (get_precedence(get_top()) == get_precedence(infix[i]))
					{
						while (get_precedence(get_top()) == get_precedence(infix[i]))
						{
							insert(pop_opstk(), 1);
						}
						push_opstk(infix[i]);
					}
					// When precedence of operator stack top less than input char.
					else if (get_precedence(get_top()) < get_precedence(infix[i]))
					{
						push_opstk(infix[i]);
					}
					// When precedence of operator stack top more than and input char.
					else if (get_precedence(get_top()) > get_precedence(infix[i]))
					{
						while (get_precedence(get_top()) > get_precedence(infix[i]))
						{
							insert(pop_opstk(), 1);
						}
						push_opstk(infix[i]);
					}
				}
			}
		}
	}
	// Inserting all the remaining operator stack content at the end.
	while (!is_opstk_empty())
	{
		insert(pop_opstk(), 1);
	}
}

// Function to check input expression is valid or not.
void valid(char *infix)
{
	for (int i = 0; i < strlen(infix); i++)
	{
		// If input char is not digit & not operator.
		if (!isdigit(infix[i]) && !is_operator(infix[i]))
		{
			// If input char is not ().
			if (infix[i] != '(' && infix[i] != ')')
			{
				printf("Invalid");
				exit(0);
			}
		}
	}
}

// Function to evaluate the expression tree.
int eval_exp_tree(struct tree_node *root)
{
	// Empty.
	if (root == NULL)
		return 0;
	// leaf node of the tree.
	if (root->right == NULL && root->left == NULL)
		return root->data;

	// All other node | operator node.
	int left_value = eval_exp_tree(root->left);
	int right_value = eval_exp_tree(root->right);

	switch (root->data)
	{
	case '^':
		return (pow(left_value, right_value));
	case '*':
		return (left_value * right_value);
	case '/':
		return (left_value / right_value);
	case '+':
		return (left_value + right_value);
	case '-':
		return (left_value - right_value);
	default:
		printf("ERROR");
		break;
	}
}

// Main function.
int main()
{
	// char infix[SIZE] = "3+((5+9)*2)";
	// char infix[SIZE] = "((10*7)*5)+((100-(75/15))+5)";

	// Input infix expression.
	printf(" INPUT INFIX: ");
	char infix[SIZE];
	scanf("%s", infix);
	valid(infix);

	// Function call to convert infix to postfix.
	infix_to_postfix(infix);

	// Show the postfix exression.
	buildexpressiontree();

	// Result.
	printf("\n");
	printf(" EVALUATED: %d", eval_exp_tree(adr_pop()));
	printf("\n\n");

	return 0;
}

/*

Given a Arithmetic Expression, build the expression tree and from the generated tree Evaluate the expression tree using its prefix notation.

You should follow the BODMAS rule while evaluating the expression. 

Example :

 Let an expression ((10*7)*5)+((100-(75/15))+5) is given, Build its expression tree.  Evaluate the expression and print it 450



Input : 

((10*7)*5)+((100-(75/15))+5)

Output: 

450 //in the new line

Invalid Case

When you encounter operators other than  + , – ,* ,^,  / , ( , ) it should Print output as Invalid as it's not an arithmetic expression 

input:

3#3+4

output:

Invalid

*/