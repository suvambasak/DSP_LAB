#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 100

// Structure of linkedlist.
typedef struct node
{
    int type;
    int data;
    struct node *next;
} node;

// Structure of stack.
typedef struct stack
{
    char op;
    struct stack *next;
} STACK;

// Global var for list head and stack top.
STACK *TOP = NULL;
node *HEAD = NULL;

// Function to check empty.
int isempty()
{
    if (TOP)
        return 0;
    else
        return 1;
}

// Function to push.
void push(char c)
{
    STACK *new_node = (STACK *)malloc(sizeof(STACK));
    if (new_node == NULL)// if (NULL == new_node)
    {
        printf("STACK IS OVERFLOW!");
        return;
    }
    new_node->op = c;
    new_node->next = TOP;
    TOP = new_node;
}

// Function to pop.
char pop()
{
    if (isempty())
    {
        printf("STACK UNDERFLOW!");
        return '\0';
    }
    else
    {
        char item = TOP->op;
        // printf("\n test : %c",item);
        STACK *temp = TOP;
        TOP = TOP->next;
        temp->next = NULL;
        free(temp);
        return item;
    }
}

// Function to get top of the stack.
char gettop()
{
    if (isempty())
        return '\0';
    else
        return (TOP->op);
}

// Function to insert in linkedlist.
int insert(int value, int flag)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->next = NULL;
    new_node->type = flag;
    new_node->data = value;
    if (HEAD == NULL)
    {
        HEAD = new_node;
        new_node = NULL;
    }
    else
    {
        node *temp = HEAD;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = new_node;
        new_node = NULL;
        temp = NULL;
    }
    return 1;
}

// Function to display.
int display()
{
    if (HEAD == NULL)
    {
        printf("\n\tLIST IS EMPTY!!");
        return 0;
    }
    else
    {
        node *temp = HEAD;
        printf("\n POSTFIX: ");
        while (temp != NULL)
        {
            if (temp->type)
                printf("%c ", temp->data);
            else
                printf("%d ", temp->data);
            temp = temp->next;
        }
        return 1;
    }
}

// Function for precedence.
int get_precedence(char ch)
{
    switch (ch)
    {
    case '%':
        return 2;
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

void infix_to_postfix(char *infix)
{
    for (int i = 0; i < strlen(infix); i++)
    {
        if (infix[i] == ' ')
            continue;
        if (isalpha(infix[i]))
        {
            insert(infix[i], 1);
        }
        else if (isdigit(infix[i]))
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
            if (isempty())
            {
                push(infix[i]);
            }
            else
            {
                // When open bracket found.
                if (infix[i] == '(')
                {
                    push(infix[i]);
                }
                // When Closing bracket found.
                else if (infix[i] == ')')
                {
                    while (gettop() != '(')
                    {
                        insert(pop(), 1);
                    }
                    pop();
                }
                else
                {
                    // When precedence of operator stack top and input char is same.
                    if (get_precedence(gettop()) == get_precedence(infix[i]))
                    {
                        while (get_precedence(gettop()) == get_precedence(infix[i]))
                        {
                            insert(pop(), 1);
                        }
                        push(infix[i]);
                    }
                    // When precedence of operator stack top less than input char.
                    else if (get_precedence(gettop()) < get_precedence(infix[i]))
                    {
                        push(infix[i]);
                    }
                    // When precedence of operator stack top more than and input char.
                    else if (get_precedence(gettop()) > get_precedence(infix[i]))
                    {
                        while (get_precedence(gettop()) >= get_precedence(infix[i]))
                        {
                            insert(pop(), 1);
                        }
                        push(infix[i]);
                    }
                }
            }
        }
    }
    // Inserting all the remaining operator stack content at the end.
    while (!isempty())
    {
        insert(pop(), 1);
    }
}

// Main
int main()
{
    char infix[SIZE];
    // input
    printf(" INFIX : ");
    scanf("%[^\n]%*c", infix);
    // puts(infix);
    infix_to_postfix(infix);
    // output
    display();

    printf("\n");
    return 0;
}

/*
a + b * c + (d * e + f) * 10


Implement a stack using linked lists.



Using the implemented stack write program to convert an infix expression to postfix expression.



Input/Output Specification:

-Input expression will consists of single letter variables and integer constants

-Only binary operators +, -, *, / and % will be allowed

-brackets () can be used in the infix expression

-Operator precedence is same as the C language

-You can assume that infix expression is a valid infix expression.



Sample Input/Output:



Input: a + b * c + (d * e + f) * 10

Output: a b c * + d e * f + 10 * +


*/