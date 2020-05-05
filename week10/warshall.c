#include<stdlib.h>
#include<stdio.h>
int** warshall(int adj[100][100],int n){
	int i,j,k;
	int*** warsh;
	warsh=malloc((n+1)*sizeof(int**));
	for(i=0;i<n+1;i++){
		warsh[i]=malloc(n*sizeof(int*));
	}
	for(i=0;i<n+1;i++){
		for(j=0;j<n;j++){
			warsh[i][j]=malloc(n*sizeof(int));
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			warsh[0][i][j]=adj[i][j];
		}
	}
	for(k=1;k<n+1;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				warsh[k][i][j]=warsh[k-1][i][j]||(warsh[k-1][i][k-1]&&warsh[k-1][k-1][j]);
			}
		}
	}
	return warsh[n];
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