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

int push(int input){
	STACK *element = (STACK*)malloc(sizeof(STACK));
	if(element == NULL){
		printf("\n\t STACK IS FULL!!");
		return 0;
	}else{
		element->data=input;
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


int stack_content(){
	if(is_empty()){
		printf("\n\tSTACK IS EMPTY!");
		return 0;
	}else{
		STACK *temp=top;
		printf("\nSTACK CONTENT : ");
		while(temp){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}


int main(int argc, char const *argv[])
{

	int choice,input;
	while(1){
		
		printf("\n<<<<<<<<<<<<<<< OPTIONS >>>>>>>>>>>>>>>>");
		printf("\n1 PUSH");
		printf("\n2 POP");
		printf("\n3 CHECK EMPTY");
		printf("\n4 STACK CONTENT");
		
		printf("\n\n0 EXIT\n");
		
		printf("---------------------------------------");
		
		printf("\nENTER CHOICE : ");
		scanf("%d",&choice);
		
		switch(choice){
			case 0:
				exit(1);
			case 1:
				printf("\nENTER ITEM : ");
				scanf("%d",&input);
				push(input);
				break;
			case 2:
				printf("\nITEM POPED : %d",pop());
				break;
			case 3:
				if(is_empty())
					printf("\n\tSTACK IS EMPTY!");
				else
					printf("\n\tSTACK IS NOT EMPTY!");
				break;
			case 4:
				stack_content();
				break;
			default:
				printf("\nINVALID INPUT!");
		}
	}
	return 0;
}