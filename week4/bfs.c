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
typedef struct queue{
	int a[100];
	int front;
	int rear;
}queue;
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
void bfs(int** mat,int* s,int n,int u,int **t,int *x){
	int k=0,count,v[100],j=0,i;
	queue q;
	for(i=0;i<100;i++){
		v[i]=0;
	}
	q.front=q.rear=0;
	count=1;
	do{	
		if(v[u]!=1){
			v[u]=1;
			q.a[++(q.rear)]=u;
			s[count++]=u;
			while(q.front!=q.rear){
				u=q.a[++(q.front)];
				for(i=0;i<n;i++){
					if(mat[u][i]==1){
						if(v[i]==0){
							s[count++]=i;
							v[i]=1;
							q.a[++(q.rear)]=i;
							t[k][0]=u;
							t[k++][1]=i;
						}
					}
				}
			}
		}
		
		u=j++;
	}while(j<n);
	*x=k;
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
	int x;
	bfs(g->mat,s,g->n,source,t,&x);
	for(i=0;i<x;i++){
		printf("%d\t%d",t[i][0],t[i][1]);
		printf("\n");
	}
	for(i=0;i<=g->n;i++){
		printf("%d",s[i]);
	}
}