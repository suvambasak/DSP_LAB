#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define SIZE 100

char op_stack[SIZE];
int num_stack[SIZE];
int op_top=-1,num_top=-1;

int is_numstk_full(){
	if(num_top==SIZE-1)
		return 1;
	else
		return 0;
}

int is_numstk_empty(){
	if(num_top==-1)
		return 1;
	else
		return 0;
}

void push_numstk(int item){
	if(is_numstk_full()){
		printf("\n\tSTACK OVERFLOW!");
		return;
	}
	num_stack[++num_top] = item;
}

int pop_numstk(){
	if(is_numstk_empty()){
		printf("\n\tSTACK UNDERFLOW!");
		return -1;
	}
	return num_stack[num_top--];
}

int is_opstk_empty(){
	if(op_top==-1)
		return 1;
	else
		return 0;
}

int is_opstk_full(){
	if(op_top==SIZE-1)
		return 1;
	else
		return 0;
}

void push_opstk(char item){
	if(is_opstk_full()){
		printf("\n\t OP STACK OVERFLOW!");
		return;
	}
	op_stack[++op_top] = item;
}

char pop_opstk(){
	if(is_opstk_empty()){
		printf("\n\t OP STACK UNDERFLOW!");
		return -1;
	}
	return op_stack[op_top--];
}

int get_precedence(char ch){
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

int is_operator(char ch){
    if(
        ch == '^' ||
        ch == '+' ||
        ch == '-' ||
        ch == '*' ||
        ch == '/'
    ){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    char infix[SIZE];

    // scanf("%s",infix);
    // printf("%s",infix);
    // printf("%ld",strlen(infix));

    // printf("%d",get_precedence('^'));
    // printf("%d",is_operator('*'));

    // push_opstk('+');
    // push_opstk('-');
    // push_opstk('*');
    // push_opstk('^');
    // push_opstk('/');
    // printf("%c ",pop_opstk());
    // printf("%c ",pop_opstk());
    // printf("%c ",pop_opstk());
    // printf("%c ",pop_opstk());
    // printf("%c ",pop_opstk());
    // printf("%c ",pop_opstk());
    // printf("%c ",pop_opstk());
    // push_opstk('+');
    // push_opstk('-');
    // push_opstk('*');
    // printf("%c ",pop_opstk());
    // printf("%c ",pop_opstk());
    // printf("%c ",pop_opstk());
    // printf("%c ",pop_opstk());
    // printf("%c ",pop_opstk());

    // push_numstk(10);
    // push_numstk(20);
    // push_numstk(30);
    // push_numstk(40);
    // push_numstk(50);
    // printf("%d ",pop_numstk());
    // printf("%d ",pop_numstk());
    // printf("%d ",pop_numstk());
    // printf("%d ",pop_numstk());
    // printf("%d ",pop_numstk());
    // printf("%d ",pop_numstk());
    // printf("%d ",pop_numstk());
    // push_numstk(30);
    // push_numstk(40);
    // push_numstk(50);
    // printf("%d ",pop_numstk());
    // printf("%d ",pop_numstk());
    // printf("%d ",pop_numstk());
    // printf("%d ",pop_numstk());
    // printf("%d ",pop_numstk());

    return 0;
}