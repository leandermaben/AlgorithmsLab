#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

void search(node** root,int k){
	node *cur,*prev;
	node* x = malloc(sizeof(node));
		x->data=k;
		x->left=NULL;
		x->right=NULL;
	if(!(*root)){
		*root=x;
		return;
	}
	cur=*root;
	while(cur){
		prev=cur;
		if(k<cur->data)
			cur=cur->left;
		else if(k==cur->data){
			printf("Value Found");
			return;
		}
		else{
			cur=cur->right;
			}
		}
		if(k<prev->data)
			prev->left=x;
		else
			prev->right=x;

}
void preorder(node* root){
	if(!root){
		return;
	}
	printf("\t%d",root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(node* root){
	if(!root){
		return;
	}
	inorder(root->left);
	printf("\t%d",root->data);
	inorder(root->right);
}
void postorder(node* root){
	if(!root){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("\t%d",root->data);
}
int main(){
	int n,x;
	node* root=NULL;
	printf("Enter number of entries");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		search(&root,x);
	}
	printf("\n");
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
}