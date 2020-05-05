#include<stdlib.h>
#include<stdio.h>
int max(int a,int b){
	return a>b?a:b;
}
int knapsack(int table[][100],int* weight,int* val,int n,int w){
	if(table[n][w]==-1)
		if(weight[n-1]>w)
			table[n][w]=table[n-1][w];
		else
			table[n][w]=max(knapsack(table,weight,val,n-1,w),val[n-1]+knapsack(table,weight,val,n-1,w-weight[n-1]));
	return table[n][w];
}
int main(){
	int n,w,i,j;
	int weight[100];
	int val[100];
	int items[100],table[100][100];
	printf("\nEnter number of items and weight of the knapsack");
	scanf("%d%d",&n,&w);
	for(i=0;i<=n;i++){
		table[i][0]=0;
	}
	for(i=0;i<=w;i++){
		table[0][i]=0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=w;j++){
			table[i][j]=-1;
		}
	}
	printf("Enter enter weights and values");
	for(i=0;i<n;i++)
		scanf("%d",&weight[i]);
	for(i=0;i<n;i++)
		scanf("%d",&val[i]);
	int res=knapsack(table,weight,val,n,w);
	printf("\nThe max value is %d",res);
	
	return 0;
}