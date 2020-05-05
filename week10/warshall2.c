#include<stdlib.h>
#include<stdio.h>
int** warshall(int adj[100][100],int n){
	int i,j,k;
	int** warsh;
	warsh=malloc(n*sizeof(int*));
	for(i=0;i<n;i++){
			warsh[i]=malloc(n*sizeof(int));
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			warsh[i][j]=adj[i][j];
		}
	}
	for(k=1;k<=n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				warsh[i][j]=warsh[i][j]||(warsh[i][k-1]&&warsh[k-1][j]);
			}
		}
	}
	return warsh;
}
int main(){
	int n,i,j;
	int adj[100][100];
	int **res;
	printf("\nEnter Number of vertices");
	scanf("%d",&n);
	printf("\nEnter adjacency matrix");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&adj[i][j]);
		}
	}
	res=warshall(adj,n);
	printf("\nTransitive closure matrix is:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",res[i][j]);
		}
		printf("\n");
	}
}