#include<stdio.h>
#include<stdlib.h>
void heapify(int* a,int n,int i){
	int l=2*i;
	int r=2*i+1;
	int largest=i;
	int temp;
	if(l<=n&&a[largest]<a[l])
		largest=l;
	if(r<=n&&a[largest]<a[r])
		largest=r;
	if(largest!=i){
		temp=a[largest];
		a[largest]=a[i];
		a[i]=temp;
		heapify(a,n,largest);
	}
}

void display(int* a,int n){
	int i;
	printf("\n");
	for(i=1;i<=n;i++)
		printf("\t%d",a[i]);
}

void heapsort(int* a,int n){
	int temp,i;
	for(int i=n/2;i>=1;i--){
		heapify(a,n,i);
	}
	display(a,n);
	for(i=0;i<=n-1;i++){
		temp=a[1];
		a[1]=a[n-i];
		a[n-i]=temp;
		heapify(a,n-i-1,1);
	}
}

int main(){

	int n,a[100],i;
	printf("\nEnter number of elements");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	heapsort(a,n);
	display(a,n);
}