#include<stdlib.h>
#include<stdio.h>
int knapsack(int* weight,int* val,int* items,int n,int w){
	int table[100][100];
	int i,j,a,b,k;
	for(i=0;i<=n;i++){
		table[i][0]=0;
	}
	for(i=0;i<=w;i++){
		table[0][i]=0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=w;j++){
			a=table[i-1][j];
			if(j-weight[i-1]>=0)
				b=val[i-1]+table[i-1][j-weight[i-1]];
			else
				b=-1;
			table[i][j]=(a>b)?a:b;
		}
	}
	/*printf("\nTable is \n");
	for(i=0;i<=n;i++){
		for(j=0;j<=w;j++){
			printf("%d\t",table[i][j]);
		}
		printf("\n");
	}*/
	i=n;
	j=w;
	k=1;
	while(i>0){
		if(table[i][j]!=table[i-1][j]){
			items[k++]=i;
			j=j-weight[i-1];
			i--;
		}else{
			i--;
		}
	}
	items[0]=k-1;
	return table[n][w];
}
int main(){
	int n,w,i,j;
	int weight[100];
	int val[100];
	int items[100];
	printf("\nEnter number of items and weight of the knapsack");
	scanf("%d%d",&n,&w);
	printf("Enter enter weights and values");
	for(i=0;i<n;i++)
		scanf("%d",&weight[i]);
	for(i=0;i<n;i++)
		scanf("%d",&val[i]);
	int res=knapsack(weight,val,items,n,w);
	printf("\nThe max value is %d",res);
	printf("\nItems chosen are \n");
	for(i=1;i<=items[0];i++){
		printf("%d\t",items[i]);
	}
	return 0;
}