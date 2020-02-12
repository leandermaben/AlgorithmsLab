#include<stdio.h>
#include<stdlib.h>
typedef struct graph{
	int n;
	int **mat;
}graph;
typedef struct{
	int a[200];
	int tos;
}stack;
void matrix(graph* g,int vn,int en,int e[][2]){
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
void dfs(int** mat,int* v,int n,int u,stack *s){
	v[u]=1;
	for(int i=0;i<n;i++){
		if(mat[u][i]==1){
			if(v[i]!=1){
				v[i]=1;
				dfs(mat,v,n,i,s);
			}
		}
	}
	s->a[++(s->tos)]=u;

}
stack topological(int** mat,int n){
	int v[100],i;
	stack s;
	s.tos=-1;
	for(int i=0;i<n;i++){
		v[i]=0;
	}
	for(i=0;i<n;i++){
		if(v[i]==0)
			dfs(mat,v,n,i,&s);
	}
	return s;
}

int main(){
	int vn,en,i,j,source;
	graph* g=malloc(sizeof(graph));
	int v[100],e[100][2];
	printf("\nEnter number of vertices and edges");
	scanf("%d %d",&vn,&en);
	printf("\n Enter edges");
	for(i=0;i<en;i++){
		scanf("%d %d",&e[i][0],&e[i][1]);
	}
	matrix(g,vn,en,e);
	printf("\nMatrix\n");
	for(i=0;i<vn;i++){
		for(j=0;j<vn;j++){
			printf("\t%d",g->mat[i][j]);
		}
		printf("\n");
	}
	stack s=topological(g->mat,g->n);
	for(;s.tos!=-1;){
		printf("\n%d",s.a[(s.tos)--]);
	}
}
