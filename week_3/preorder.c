#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node *left, *right;
	int data;
} *root=NULL;
int *in, *post, size;

int findnextnode(int start, int end){
    int i,j;
    for(i=size-1; i>=0;i--){
        for(j=start;j<=end;j++){
            if(post[i]==in[j]) return j;
        }
    }
    return -1;
}

struct node* buildtree(struct node* root, int start, int end){
    if(start>end) return NULL;

    root = (struct node*)malloc(sizeof(struct node));
    root->left=root->right=NULL;
    
    int index = findnextnode(start,end);
    root->data = in[index];
    printf(" index : %d  Val: %d \n",index,in[index]);

    if (start==end) {
        printf(" start==end : return root \n");
        return root;
    }

    root->left=buildtree(root->left,start,index-1);
    root->right=buildtree(root->right,index+1,end);

    return root;
}

void preorder(struct node* root){
	if(root!=NULL){
        printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}


int main(){

    size=7;

    in = (int*)malloc(sizeof(int)*size);
    post = (int*)malloc(sizeof(int)*size);
    in[0]=4;
    in[1]=2;
    in[2]=5;
    in[3]=1;
    in[4]=6;
    in[5]=3;
    in[6]=7;

    post[0]=4;
    post[1]=5;
    post[2]=2;
    post[3]=6;
    post[4]=7;
    post[5]=3;
    post[6]=1;

    root = buildtree(root,0,size-1);
    preorder(root);

    // printf("root : %d\n",root->data);
    // root = root->right;
    // printf("root : %d\n",root->data);
    // root = root->left;
    // printf("root : %d\n",root->data);
    
    return 0;
}
