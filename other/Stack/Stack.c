#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int stack[SIZE],top=-1;

int is_full(){
	if(top==SIZE-1)
		return 1;
	else
		return 0;
}

int is_empty(){
	if(top==-1)
		return 1;
	else
		return 0;
}

void push(int item){
	if(is_full()){
		printf("\n\tSTACK OVERFLOW!");
		return;
	}
	stack[++top] = item;
}

int pop(){
	if(is_empty()){
		printf("\n\tSTACK UNDERFLOW!");
		return -1;
	}
	return stack[top--];
}

int items_inside(){
	if(is_empty())
		return 0;
	else
		return top+1;
}

int stack_content(){
	if(is_empty()){
		printf("\n\tSTACK EMPTY");
		return 0;
	}else{
		int i;
		printf("\nSTACK CONTENTS : ");
		for(i=0;i<=top;i++)
			printf(" %d",stack[i]);
			
		return 1;
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
		printf("\n4 CHECK FULL");
		printf("\n5 NUMBER OF ITEMS INSIDE");
		printf("\n6 STACK CONTENT");
		
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
				if(is_full())
					printf("\n\tSTACK IS FULL!");
				else
					printf("\n\tSTACK NOT FULL!");
				break;
			case 5:
				printf("\nNUMBER OF ITEM INSIDE : %d",items_inside());
				break;
			case 6:
				stack_content();
				break;
			default:
				printf("\nINVALID INPUT!");
		}
	}
	return 0;
}
