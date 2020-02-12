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
int* topological(int **mat,int n){
	int v[100],flag,i,j,l=0,k;
	int* a=malloc(100*sizeof(int));
	for(i=0;i<100;i++){
		v[i]=0;
	}
	while(l!=n){
		for(j=0;j<n;j++){
			flag=0;
			for(i=0;i<n;i++){
				if(mat[i][j]==1||v[j]==1){
					flag=1;
					break;
				}
			}
			if(!flag){
				for(k=0;k<n;k++){
					mat[j][k]=0;
					mat[k][j]=0;
				}
				v[j]=1;
				a[l++]=j;
			}
		}
	}
	return a;
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
	int* s=topological(g->mat,g->n);
	for(i=0;i<vn;i++){
		printf("\n%d",s[i]);
	}
}
