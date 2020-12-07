#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}STACK;

STACK *top=NULL;

int is_empty(){
	if(top==NULL)
		return 1;
	else
		return 0;
}

void push(int input){
	STACK *element = (STACK*)malloc(sizeof(STACK));
	if(element == NULL){
		printf("\n\t STACK IS FULL!!");
		return;
	}else{
		element->data=input;
		if(top==NULL){
			top=element;
			top->next=NULL;
		}else{
			element->next=top;
			top=element;
		}
	}
}

int pop(){
	if(is_empty()){
		printf("\n\tSTACK IS EMPTY!");
		return -1;
	}else{
		int item = top->data;

		STACK *del = top;
		top = top->next;
		del->next = NULL;
		free(del);

		return item;
	}
}

void main(){
    push(10);
    push(20);
    push('A');


    char c = atoi(pop());

    printf("%c \n",c);
    printf("%d \n",pop());
    printf("%d \n",pop());

    
}