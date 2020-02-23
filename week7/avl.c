#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
	int height;
}node;
typedef struct post{
	node* cur;
	int flag;
}post;
typedef struct stack{
	node* a[100];
	int tos;
}stack;
int max(int a,int b){
	return a>b?a:b;
}
int balance_factor(node* ancs){
	int left,right;
	if(ancs->left==NULL)
		left=0;
	else
		left=ancs->left->height;
	if(ancs->right==NULL)
		right=0;
	else
		right=ancs->right->height;
	return left-right;
}
void leftRotate(node* cur,node** root,node* par){
	node* temp=cur->right->left;
	node* temp2=cur->right;
	int left,right;
	if(cur->left)
		left=cur->left->height;
	else 
		left=0;
	if(cur->right->left)
		right=cur->right->left->height;
	else
		right=0;
	cur->height=1+max(left,right);
	if(cur->right->right)
		right=cur->right->right->height;
	else
		right=0;
	cur->right->height=1+max(cur->height,right);
	cur->right->left=cur;
	cur->right=temp;
	if(*root==cur)
		*root=temp2;
	else if(cur->data<par->data)
		par->left=temp2;
	else
		par->right=temp2;
}
void rightRotate(node* cur,node** root,node* par){
	node* temp=cur->left->right;
	node* temp2=cur->left;
	int right,left;
	if(cur->right)
		right=cur->right->height;
	else 
		right=0;
	if(cur->left->right)
		left=cur->left->right->height;
	else
		left=0;
	cur->height=1+max(left,right);
	if(cur->left->left)
		left=cur->left->left->height;
	else
		left=0;
	cur->left->height=1+max(cur->height,left);
	cur->left->right=cur;
	cur->left=temp;
	if(*root==cur)
		*root=temp2;
	else if(cur->data<par->data)
		par->left=temp2;
	else
		par->right=temp2;
}
void balance(int key,node** root,stack* s){
	int fac;
	node *temp1=NULL,*par;
	do{
		temp1=s->a[(s->tos)--];
		fac=balance_factor(temp1);
	}while(fac<2 && fac>-2&&s->tos!=-1);
	if(s->tos!=-1)
		par=s->a[(s->tos)--];
	else
		par=NULL;
	if(fac==0)
		return;
	else if(fac>1&&key<temp1->left->data){
		rightRotate(temp1,root,par);
	}
	else if(fac>1&&key>temp1->left->data){
		leftRotate(temp1->left,root,temp1);
		rightRotate(temp1,root,par);
	}else if(fac<-1&&key>temp1->right->data){
		leftRotate(temp1,root,par);
	}
	else if(fac>1&&key<temp1->right->data){
		rightRotate(temp1->right,root,temp1);
		leftRotate(temp1,root,par);
	}
}
void update(node* root){
	int left,right;
	if(!root)
		return;
	update(root->left);
	update(root->right);
	if(root->left==NULL)
		left=0;
	else
		left=root->left->height;
	if(root->right==NULL)
		right=0;
	else
		right=root->right->height;
	root->height=1+max(left,right);
}
void update1(node* root,stack* s){
	node* temp;
	int right,left;
	while(s->tos!=-1){
		temp=s->a[(s->tos)--];
		if(temp->left)
			left=temp->left->height;
		else
			left=0;
		if(temp->right)
			right=temp->right->height;
		else
			right=0;
		temp->height=1+max(left,right);
		printf("\n%d-%d",temp->data,temp->height);
	}
}
void insert(node** root,int data){
	node* temp=malloc(sizeof(node));
	node *trav=NULL,*prev=NULL;
	stack s,t,t2;
	s.tos=-1;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	temp->height=1;
	if(!(*root)){
		*root=temp;
	}else{
		trav=*root;
		for(;trav;){
			s.a[++(s.tos)]=trav;
			prev=trav;
			if(data<trav->data)
				trav=trav->left;
			else
				trav=trav->right;
		}
		if(data<prev->data)
			prev->left=temp;
		else
			prev->right=temp;
		t=s;
		t2=s;
		t2.a[++(t2.tos)]=temp;
		update1(*root,&t);
		balance(data,root,&s);
	}
}
void inorder(node* root){
	if(!root)
		return;
	inorder(root->left);
	printf("\t%d",root->data);
	inorder(root->right);
}
void preorder(node* root){
	if(!root)
		return;
	printf("\t%d",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(node* root){
	if(!root)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("\t%d",root->data);
}
int main(){
	node* root=NULL;
	int n,data,i;
	printf("\nEnter number of nodes");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&data);
		insert(&root,data);
	}
	printf("\nPre order\n");
	preorder(root);
	printf("\nIn order\n");
	inorder(root);
	printf("\nPost order\n");
	postorder(root);
}