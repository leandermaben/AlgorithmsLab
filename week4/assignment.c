#include<stdio.h>
#include <stdlib.h>
void exhaustive(int** s,int c[][100],int* t,int k,int n,int sum,int* x){
	int i;
	for(i=0;i<n;i++){
		if(k==n-1){
			if(t[i]==0){
				s[*x][k+1]=sum+c[k][i];
				s[*x++][k]=c[k][i];
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
	exhaustive(s,c,t,0,n,0,&x);
	int max=s[0][n],ind=0;
	for(i=1;i<lim;i++){
		if(max<s[i][n]){
			max=s[i][n];
			ind=i;
		}
	}
	for(i=0;i<n;i++){
		printf("\t%d",s[ind][i]);
	}
	printf("\nMax is %d",s[ind][n]);
}