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

node *HEAD = NULL;

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

// Function to show infix expression.
int display()
{
	if (NULL == HEAD)
	{
		printf("\n\tLIST IS EMPTY!!");
		return 0;
	}
	else
	{
		node *temp = HEAD;
		printf("\n POSTFIX: ");

		while (NULL != temp)
		{
			if (temp->flg)
				printf("%c ", temp->num);
			else
				printf("%d ", temp->num);
			temp = temp->next;
		}
		return 1;
	}
}

//  Function to check number STACK is full.
int is_numstk_full()
{
	if (SIZE - 1 == num_top)
		return 1;
	else
		return 0;
}

//  Function to check number STACK is empty.
int is_numstk_empty()
{
	if (-1 == num_top)
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
	if (-1 == op_top)
		return 1;
	else
		return 0;
}

//  Function to check operator STACK is full.
int is_opstk_full()
{
	if (SIZE - 1 == op_top)
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

// Function for evaluating the post fix expression.
int evaluate()
{
	if (HEAD == NULL)
	{
		printf("\n\t NO EXPRESSION FOUND.");
		return 0;
	}
	else
	{
		node *temp = HEAD;
		// var operand.
		int op1, op2;
		while (temp != NULL)
		{
			if (temp->flg)
			{

				// Poping two operand from the number stack.
				op2 = pop_numstk();
				op1 = pop_numstk();

				// Performing the operation and pushing the result into the number stack.
				switch (temp->num)
				{
				case '^':
					push_numstk(pow(op1, op2));
					break;
				case '*':
					push_numstk(op1 * op2);
					break;
				case '/':
					push_numstk(op1 / op2);
					break;
				case '+':
					push_numstk(op1 + op2);
					break;
				case '-':
					push_numstk(op1 - op2);
					break;
				default:
					printf("ERROR");
					break;
				}
			}
			else
			{
				// Pushing the operands into the number stack.
				push_numstk(temp->num);
			}
			temp = temp->next;
		}
		// Returning the result by poping the last element from the number stack.
		return pop_numstk();
	}
}

// Main function.
int main()
{
	char infix[SIZE] = "10+(3*4-(4/2^2)*5)*3";

	// Input infix expression.
	// printf("\n ENTER INFIX: ");
	// scanf("%s",infix);

	// Function call to convert infix to postfix.
	infix_to_postfix(infix);

	// Show the postfix exression.
	display();

	// Result.
	printf("\n\n");
	printf(" EVALUATED: %d", evaluate());
	printf("\n\n");

	return 0;
}