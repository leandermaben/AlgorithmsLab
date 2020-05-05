#include<stdlib.h>
#include<stdio.h>
int** floyd(int weight[100][100],int n){
	int i,j,k,a,b;
	int** flo;
	flo=malloc(n*sizeof(int*));
	for(i=0;i<n;i++){
			flo[i]=malloc(n*sizeof(int));
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			flo[i][j]=weight[i][j];
		}
	}
	for(k=1;k<=n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				a=flo[i][j];
				b=flo[i][k-1]+flo[k-1][j];
				flo[i][j]=(a<b)?a:b;
			}
		}
	}
	return flo;
}
int main(){
	int n,i,j;
	int weight[100][100];
	int **res;
	printf("\nEnter Number of vertices");
	scanf("%d",&n);
	printf("\nEnter weight matrix");
	printf("\nEnter 10000 for no direct path exists (Here we assume all valid paths have length less than 10000)");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&weight[i][j]);
		}
	}
	res=floyd(weight,n);
	printf("\nMinimum Path matrix is:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(res[i][j]==10000)
				printf("inf\t");
			else
				printf("%d\t",res[i][j]);
		}
		printf("\n");
	}
}