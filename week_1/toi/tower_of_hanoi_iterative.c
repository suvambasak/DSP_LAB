// Compile with -lm flag    ::      $ cc toi_itr.c -lm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SOURCE "S"
#define DESTINATION "D"
#define AUXILLIARY "A"
#define TOTAL_MOVE(N) (pow(2, n) - 1)
#define SIZE 20
#define EMPTY -1

//  Function to check STACK is full.
int is_full(int *top)
{
    if (SIZE - 1 == *top)
        return 1;
    return 0;
}

// Function to check STACK is empty.
int is_empty(int *top)
{
    if (EMPTY == *top)
        return 1;
    return 0;
}

// Function to push item into the STACK.
void push(int *stack, int *top, int item)
{
    if (is_full(top))
        return;
    stack[++(*top)] = item;
}

// Function to pop item from the STACK.
int pop(int *stack, int *top)
{
    if (is_empty(top))
        return -1;
    return stack[(*top)--];
}

// Function to get top element of the stack with out poping.
int get_top(int *stack, int *top)
{
    if (is_empty(top))
        return (SIZE + 1);
    return stack[*top];
}

// Function for printing all the element of a stack from top to bottom.
void show(int *stack, int *top)
{
    int i;
    printf(" CONTENT TOP TO BOTTOM:");
    for (i = *top; i >= 0; i--)
        printf(" %d", stack[i]);
}

// Function to move disk
void move_peg(int move_number, int *stack_1, int *stack_top_1, int *stack_2, int *stack_top_2, char *place_1, char *place_2)
{
    int item;
    printf("\n MOVE (%d) B/W [%s] AND [%s] :: ", move_number, place_1, place_2);

    if (get_top(stack_1, stack_top_1) < get_top(stack_2, stack_top_2))
    {
        item = pop(stack_1, stack_top_1);
        push(stack_2, stack_top_2, item);
        printf("DISK %d FROM [%s] TO [%s]", item, place_1, place_2);
    }
    else
    {
        item = pop(stack_2, stack_top_2);
        push(stack_1, stack_top_1, item);
        printf("DISK %d FROM [%s] TO [%s]", item, place_2, place_1);
    }
}

// Main function.
int main()
{
    int n, flag, total_moves;

    printf("\n ENTER NUMBER OF DISK : ");
    scanf("%d", &n);

    // Getting total number of moves,
    total_moves = TOTAL_MOVE(n);
    // Setting the flag in case of number of disk is odd.
    flag = (n % 2);

    // stack_s is source stack.
    // stack_a is auxiliary stack.
    // stack_d is destination stack.
    int stack_s[SIZE], stack_a[SIZE], stack_d[SIZE];
    int top_s = -1, top_a = -1, top_d = -1;

    // Inserting N (input value) disk into the source stack.
    for (int i = n; i >= 1; i--)
        push(stack_s, &top_s, i);

    // Showing the source stack.
    printf("\n\n SOURCE - ");
    show(stack_s, &top_s);
    printf("\n\n");

    // Moving the disk. (ODD DISK:EVEN DISK)
    for (int i = 1; i <= total_moves; i++)
    {
        if ((i % 3) == 1)
            flag ? move_peg(i, stack_s, &top_s, stack_d, &top_d, SOURCE, DESTINATION) : move_peg(i, stack_s, &top_s, stack_a, &top_a, SOURCE, AUXILLIARY);
        if ((i % 3) == 2)
            flag ? move_peg(i, stack_s, &top_s, stack_a, &top_a, SOURCE, AUXILLIARY) : move_peg(i, stack_s, &top_s, stack_d, &top_d, SOURCE, DESTINATION);
        if ((i % 3) == 0)
            move_peg(i, stack_a, &top_a, stack_d, &top_d, AUXILLIARY, DESTINATION);
    }

    // Showing the destination stack after all moves.
    printf("\n\n DESTINATION - ");
    show(stack_d, &top_d);
    printf("\n\n");

    return 0;
}