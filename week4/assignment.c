#include<stdio.h>
#include <stdlib.h>
int opcount;
void exhaustive(int** s,int c[][100],int* t,int k,int n,int sum,int* x){
	int i;
	for(i=0;i<n;i++){
		opcount++;
		if(k==n-1){
			if(t[i]==0){
				s[*x][k+1]=sum+c[k][i];
				s[*x][k]=c[k][i];
				*x=*x+1;
				return;
			}
		}
		else if(k<n-1&&t[i]==0){
			t[i]=1;
			s[*x][k]=c[k][i];
			exhaustive(s,c,t,k+1,n,sum+c[k][i],x);
			t[i]=0;
		}
	}
}
long fact(int x){
	if(x<2)
		return 1;
	return x*fact(x-1);
}
int main(){
	opcount=0;
	int n,c[100][100],i,j;
	printf("\nEnter number of elements");
	scanf("%d",&n);
	long lim=fact(n);
	int** s=malloc(sizeof(int*)*lim);
	for(i=0;i<lim;i++){
		s[i]=malloc((n+1)*sizeof(int));
	}
	printf("Enter costs");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	int* t=malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		t[i]=0;
	int x=0;
	for(i=0;i<lim;i++){
		for(int j=0;j<n+1;j++){
			s[i][j]=-1;
		}
	}
	exhaustive(s,c,t,0,n,0,&x);
	int min=s[0][n],ind=0;
	for(i=1;i<lim;i++){
		if(min>s[i][n]){
			min=s[i][n];
			ind=i;
		}
	}
	for(i=0;i<lim;i++){
		for(int j=0;j<n+1;j++){
			if(s[i][j]==-1)
				s[i][j]=s[i-1][j];
			printf("\t%d",s[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	for(i=0;i<n;i++){
		printf("\t%d",s[ind][i]);
	}
	printf("\nMin is %d",s[ind][n]);
	printf("opcount is %d",opcount);
}