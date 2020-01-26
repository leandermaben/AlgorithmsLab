#include<stdio.h>
#include<stdlib.h>
void bubble(int* a,int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
int main(){
	int n,i;
	printf("\nEnter number of elements.");
	scanf("%d",&n);
	int*a=malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	bubble(a,n);
	printf("\n");
	for(i=0;i<n;i++){
		printf("\t%d",a[i]);
	}
}