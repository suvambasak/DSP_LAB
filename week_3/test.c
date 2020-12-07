#include <stdio.h>
#include <stdlib.h>

struct tree_node{
    struct node *left, *right;
    int data;
} *root = NULL;


typedef struct node{
	struct tree_node *addr;
	struct node *next;
}STACK;

STACK *top=NULL;

int is_empty(){
	if(top==NULL)
		return 1;
	else
		return 0;
}

int push(struct tree_node *input){
	STACK *element = (STACK*)malloc(sizeof(STACK));
	if(element == NULL){
		printf("\n\t STACK IS FULL!!");
		return 0;
	}else{
		element->addr=input;
		if(top==NULL){
			top=element;
			top->next=NULL;
		}else{
			element->next=top;
			top=element;
		}
		return 1;
	}
}

struct tree_node* pop(){
	if(is_empty()){
		printf("\n\tSTACK IS EMPTY!");
		return NULL;
	}else{
		struct tree_node *item = top->addr;

		STACK *del = top;
		top = top->next;
		del->next = NULL;
		free(del);

		return item;
	}
}


int main(int argc, char const *argv[])
{

    root = (struct tree_node*)malloc(sizeof(struct tree_node));
    root->data=10;
    root->left=NULL;
    root->right=NULL;

    printf("%p\n",root);
    push(root);


    root = (struct tree_node*)malloc(sizeof(struct tree_node));
    root->data=10;
    root->left=NULL;
    root->right=NULL;

    printf("%p\n",root);
    push(root);


    root = (struct tree_node*)malloc(sizeof(struct tree_node));
    root->data=10;
    root->left=NULL;
    root->right=NULL;

    printf("%p\n",root);
    push(root);

    printf("pop: %p \n",pop());
    printf("pop: %p \n",pop());
    printf("pop: %p \n",pop());
    printf("pop: %p \n",pop());


    printf("\n");
	return 0;
}