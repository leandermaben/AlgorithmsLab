#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
	int height;
}node;
typedef struct stack{
	node* a[100];
	int tos;
}stack;
int max(int a,int b){
	return a>b?a:b;
}
int height(node* x){
	if(!x)
		return 0;
	else 
		return x->height;
}
int balance_factor(node* ancs){
	return height(ancs->left)-height(ancs->right);
}
void leftRotate(node* cur,node** root,node* par){
	node* temp=cur->right->left;
	node* temp2=cur->right;
	cur->height=1+max(height(cur->left),height(temp));
	cur->right->height=1+max(cur->height,height(temp2->right));
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
	cur->height=1+max(height(cur->right),height(temp));
	cur->right->height=1+max(cur->height,height(temp2->left));
	cur->left->right=cur;
	cur->left=temp;
	if(*root==cur)
		*root=temp2;
	else if(cur->data<par->data)
		par->left=temp2;
	else
		par->right=temp2;
}
void balance(int key,node** root,node* cur,node* par){
	int fac;
	fac=balance_factor(cur);
	if(fac==0)
		return;
	else if(fac>1&&key<cur->left->data){
		rightRotate(cur,root,par);
	}
	else if(fac>1&&key>cur->left->data){
		leftRotate(cur->left,root,cur);
		rightRotate(cur,root,par);
	}else if(fac<-1&&key>cur->right->data){
		leftRotate(cur,root,par);
	}
	else if(fac>1&&key<cur->right->data){
		rightRotate(cur->right,root,cur);
		leftRotate(cur,root,par);
	}
}
void update(node* cur){
	cur->height=1+max(height(cur->left),height(cur->right));
}
void insert(node** root,int data){
	node* temp=malloc(sizeof(node));
	node *trav=NULL,*prev=NULL;
	stack s;
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
		node* par=s.a[(s.tos)--];
		while(s.tos!=-1){
			trav=par;
			par=s.a[(s.tos)--];
			update(trav);
			balance(data,root,trav,par);
		}
		update(par);
		balance(data,root,par,NULL);
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