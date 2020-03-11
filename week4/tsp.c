#include<stdio.h>
#include<stdlib.h>
int fact(int a){
	if(a==0)
		return 1;
	return a*fact(a-1);
}
int permutations(int n,int* t,int k,int* x,int p[][100]){
	int i;
	for(i=1;i<n;i++){
		if(k==n-2&&t[i]!=1){
			p[*x][k]=i;
			(*x)=(*x)+1;
		}else if(t[i]!=1){
			t[i]=1;
			p[*x][k]=i;
			permutations(n,t,k+1,x,p);
			t[i]=0;
		}
	}
}
int main(){
	int i,n,p[100][100],x=0,t[100],j,dist[100][100],f,min,sum;
	printf("\nEnter number of vertices");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		t[i]=0;
	permutations(n,t,0,&x,p);
	for(i=0;i<fact(n-1);i++){
		for(j=0;j<n-1;j++){
			if(p[i][j]==0)
				p[i][j]=p[i-1][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&dist[i][j]);
		}
	}
	min=5000;
	for(i=0;i<fact(n-1);i++){
		f=0;
		sum=0;
		for(j=0;j<n-1;j++){
				sum+=dist[f][p[i][j]];
				f=p[i][j];
		}
		sum+=dist[f][0];
		if(min>sum)
			min=sum;
	}
	printf("\n%d",min);

}