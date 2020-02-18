#include<stdio.h>
#include<stdlib.h>
int opcount=0;
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;
void create(node** root,int data){
	char c;
	if(!(*root)){
		*root=malloc(sizeof(node));
		(*root)->left=NULL;
		(*root)->right=NULL;
	}else{
		printf("\nEnter l or r");
		scanf("\n%c",&c);
		if(c=='l'){
			create(&((*root)->left),data);
		}else{
			create(&((*root)->right),data);
		}
	}
}
int inorder(node* root){
	int count=0;
	opcount++;
	if(!root)
		return 0;
	else{
		count+=inorder(root->left);
		count=count+1;
		count+=inorder(root->right);
		return count;
	}
}
int main(){
	int d,i,n;
	node* root=NULL;
	printf("\nEnter number of nodes");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\nEnter value");
		scanf("%d",&d);
		create(&root,d);
	}
	printf("\nNumber of nodes are %d",inorder(root));
	printf("\nOpcount is %d",opcount);
}