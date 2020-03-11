#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int n;
	int data[2];
	struct node* link[3];
}node;
int isleaf(node* cur){
	int i;
	for(i=0;i<3;i++){
		if(cur->link[i])
			return 0;
	}
	return 1;
}
node* getnode(int data){
	node* temp=malloc(sizeof(node));
	temp->data[0]=data;
	temp->n=1;
	temp->link[0]=NULL;
	temp->link[1]=NULL;
	temp->link[2]=NULL;
	return temp;
}
void move(node* cur,node*temp){

}
node* insert(node* root,int data){
	node *cur,*stack[100],*temp,*temp2;
	int tos=-1,flag=0,push,ind;
	if(!root){
		return getnode(data);
	}
	cur=root;
	while(1){
		stack[++tos]=cur;
		if(isleaf(cur))
			break;
		if(cur->n==1){
			if(data<cur->data[0]){
				cur=cur->link[0];
				ind=0;
			}
			else{
				cur=cur->link[1];
				ind=1;
			}
		}else{
			if(data<cur->data[0]){
				cur=cur->link[0];
				ind=0;
			}
			else if(data<cur->data[1]){
				cur=cur->link[1];
				ind=1;
			}
			else{
				cur=cur->link[2];
			}
		}
	}
	temp=NULL;
	while(tos!=-1){
		flag=0;
		cur=stack[tos--];
		if(cur->n==1){
			cur->n=2;
			if(data<cur->data[0]){
				cur->data[1]=cur->data[0];
				cur->data[0]=data;
				return root;
			}else if(data>cur->data[0]){
				cur->data[1]=data;
				return root;
			}else
				return root;
		}else{
			flag=1;
			temp2=temp;
			temp=getnode(0);
			if(data<cur->data[0]){
				push=cur->data[0];
				cur->data[0]=data;
				cur->n=1;
				temp->data[0]=cur->data[1];
				temp->link[0]=cur->link[1];
				temp->link[2]=cur->link[2];
				cur->link[1]=temp2;
			}else if(data<root->data[1]){
				cur->n=1;
				push=data;
				temp->data[0]=cur->data[1];
				temp->link[0]=cur->link[1];
				temp->link[2]=cur->link[2];
				cur->link[1]=temp2;
			}else{
				push=root->data[1];
				cur->n=1;
				temp->data[0]=data;
				temp->data[0]=cur->data[1];
				temp->link[0]=cur->link[1];
				temp->link[2]=cur->link[2];
				cur->link[1]=temp2;
			}
		}
		if(!flag)
			break;
		data=push;
	}
	if(flag){
		temp2=temp;
		temp=getnode(data);
		temp->n=2;
		temp->link[0]=root;
		temp->link[1]=temp2;
		return temp;
	}
	return root;
}
void inorder(node* root){
	if(!root)
		return;
		inorder(root->link[0]);
		printf("\t%d",root->data[0]);
		inorder(root->link[1]);
		printf("\t%d",root->data[1]);
		inorder(root->link[2]);
}
int main(){
	int i,n,temp;
	node* root=NULL;
	printf("\nEnter number of keys");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&temp);
		root=insert(root,temp);
	}
	printf("\n\n\n\n\nHere");
	printf("\nInorder");
	inorder(root);
}