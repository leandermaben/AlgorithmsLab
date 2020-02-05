#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* next;
}node;
typedef struct graph{
	int n;
	int **mat;
	node** list;
}graph;
void matrix(graph* g,int vn,int en,int* v,int e[][2]){
	int i,j,r,c;
	g->n=vn;
	int** adjMat=malloc(vn*sizeof(int*));
	for(i=0;i<vn;i++){
		adjMat[i]=malloc(vn*sizeof(int));
	}
	for(i=0;i<vn;i++){
		for(j=0;j<vn;j++){
			adjMat[i][j]=0;
		}
	}
	for(i=0;i<en;i++){
		r=e[i][0];
		c=e[i][1];
		adjMat[r][c]=1;
	}
	g->mat=adjMat;
}
void list(graph* g,int vn,int en,int* v,int e[][2]){
	int i,r,c;
	node** l=malloc(vn*sizeof(node*));
	node *trav,*x;
	for(i=0;i<vn;i++){
		l[i]=malloc(sizeof(node));
		l[i]->data=v[i];
		l[i]->next=NULL;
	}
	for(i=0;i<en;i++){
		r=e[i][0];
		c=e[i][1];
		for(trav=l[r];trav->next;trav=trav->next);
		x=malloc(sizeof(node));
		x->data=c;
		x->next=NULL;
		trav->next=x;
	}
	g->list=l;
}
void dfs(int** mat,int* s,int n,int u,int **t,int* k){
	s[u]=1;
	printf("\nPushing %d",u);
	for(int j=0;j<n;j++){
		if(mat[u][j]==1){
			if(s[j]!=1){
				t[*k][0]=u;
				t[*k][1]=j;
				(*k)++;
				dfs(mat,s,n,j,t,k);
				printf("\nPopping %d",j);
			}
		}
	}
}
int main(){
	int vn,en,i,j,source;
	node* trav;
	graph* g=malloc(sizeof(graph));
	int v[100],e[100][2];
	printf("\nEnter number of vertices and edges");
	scanf("%d %d",&vn,&en);
	printf("\n Enter vertices");
	for(i=0;i<vn;i++){
		scanf("%d",&v[i]);
	}
	printf("\n Enter edges");
	for(i=0;i<en;i++){
		scanf("%d %d",&e[i][0],&e[i][1]);
	}
	matrix(g,vn,en,v,e);
	printf("\nMatrix\n");
	for(i=0;i<vn;i++){
		for(j=0;j<vn;j++){
			printf("\t%d",g->mat[i][j]);
		}
		printf("\n");
	}
	/*printf("\nList\n");
	list(g,vn,en,v,e);
	for(i=0;i<vn;i++){
		printf("\n %d\t->",g->list[i]->data);
		for(trav=g->list[i]->next;trav;trav=trav->next){
			printf("\t%d",trav->data);
		}
	}*/
	int s[100];
	int** t;
	t=malloc(100*sizeof(int*));
	for(i=0;i<100;i++){
		t[i]=malloc(2*sizeof(int));
	}
	int k;
	printf("\nEnter source");
	scanf("%d",&source);
	k=0;
	for(i=0;i<vn;i++){
		s[i]=0;
	}
	dfs(g->mat,s,g->n,source,t,&k);
	for(int i=0;i<vn;i++){
		if(i!=source)
			dfs(g->mat,s,g->n,i,t,&k);
	}
	for(i=0;i<k;i++){
		printf("%d\t%d",t[i][0],t[i][1]);
		printf("\n");
	}
}