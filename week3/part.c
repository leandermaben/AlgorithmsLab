#include<stdio.h>
#include<stdlib.h>
int power(int n){
	int prod=1;
	for(int i=0;i<n;i++){
		prod*=2;
	}
	return prod;
}
int partition(int* a,int n){
	int lim=power(n)-1;
	int i,x,sum=0,c=0,cum=0;
	for(i=0;i<n;i++){
		sum+=a[i];
	}
	for(i=0;i<=lim;i++){
		x=i;
		c=0;
		cum=0;
		while(x){
			if((x&1)==1){
				cum=cum+a[c];
			}
			c++;
			x=x>>1;
		}
		if(cum==sum/2.0){
			return i;
		}
	}
	return -1;

}
int main(){
	int n,i,c=0;
	printf("\nEnter number of elements");
	scanf("%d",&n);
	int* a=malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int x=partition(a,n);
	if(x==-1){
		printf("No Partition Exists.");
		return 0;
	}
	int y=x;
	while(x){
		if((x&1)==1){
				printf("\t%d",a[c]);
			}
			c++;
			x=x>>1;
	}printf("\n");
	c=0;
	while(c!=n){
		if((y&1)==0)
			printf("\t%d",a[c]);
		c++;
		y=y>>1;
	}
}