#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* link;
}node;
typedef struct graph{
	int n;
	int** mat;
	node** list;
}graph;
typedef struct queue{
	int a[100];
	int front;
	int rear;
}queue;
int** createMat(int edge[][2],int v,int e){
	int i,j,r,c;
	int ** mat =malloc(v*sizeof(int*));
	for(i=0;i<v;i++){
		mat[i]=malloc(v*sizeof(int));
	}
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			mat[i][j]=0;
		}
	}
	for(i=0;i<e;i++){
		r=edge[i][0];
		c=edge[i][1];
		mat[r][c]=1;
	}
	return mat;
}
node** createList(int edge[][2],int v,int e){
	int i,r,c;
	node** list=malloc(v*sizeof(node*));
	node *temp,*trav;
	for(i=0;i<v;i++){
		list[i]=malloc(sizeof(node));
		list[i]->data=i;
		list[i]->link=NULL;
	}
	for(i=0;i<e;i++){
		r=edge[i][0];
		c=edge[i][1];
		temp=malloc(sizeof(node));
		temp->data=c;
		temp->link=NULL;
		for(trav=list[i];trav->link;trav=trav->link);
			trav->link=temp;
	}
	return list;
}
int bipartite_bfs(graph* g){
	int color[100],cur,k,i,j;
	queue q;
	q.front=q.rear=0;
		for(i=0;i<g->n;i++){
			color[i]=-1;
		}
		for(k=0;k<g->n;k++){
			if(color[k]!=-1)
				continue;
			color[k]=0;
			q.a[++(q.rear)]=k;
			while(q.front!=q.rear){
				cur=q.a[++(q.front)];
				for(i=0;i<g->n;i++){
					if(g->mat[i][i])
						return 0;
					if(g->mat[cur][i]==1&&color[i]==-1){
						color[i]=1-color[cur];
						q.a[++(q.rear)]=i;
					}else if(g->mat[cur][i]==1&&color[i]==color[cur])
						return 0;
				}
			}
		}
		return 1;
}
int dfs(graph* g,int* color,int i,int c){
	color[i]=c;
	for(int j=0;j<g->n;j++){
		if(g->mat[i][j]&&color[j]==-1){
			dfs(g,color,j,1-c);
		}else if(g->mat[i][j]&&color[j]==c){
			return 0;
		}
	}
	return 1;
}
int bipartite_dfs(graph* g){
	int color[100],i,res=1;
	for(i=0;i<g->n;i++){
		color[i]=-1;
	}
	for(i=0;i<g->n;i++){
		if(color[i]!=-1)
			continue;
		printf("\n%d",i);
		res&=dfs(g,color,i,0);
	}
	return res;
}
int main(){
	graph g;
	int v,e,edge[100][2],i,j;
	printf("\nEnter number of vertices and edges");
	scanf("%d%d",&v,&e);
	for(i=0;i<e;i++){
		scanf("%d%d",&edge[i][0],&edge[i][1]);
	}
	g.n=v;
	g.mat=createMat(edge,v,e);
	//g.list=createList(edge,v,e);
	printf("\nMatrix\n");
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			printf("\t%d",g.mat[i][j]);
		}
		printf("\n");
	}
	if(bipartite_bfs(&g))
		printf("\nTrue");
	else
		printf("\nFalse");
	if(bipartite_dfs(&g))
		printf("\nTrue");
	else
		printf("\nFalse");
}