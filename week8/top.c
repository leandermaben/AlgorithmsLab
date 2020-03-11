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
int* build(int* a,int n){
	int i,j;
	int* heap = malloc((n+1)*sizeof(int));
	for(i=1;i<=n;i++){
		heap[i]=a[i];
		for(j=i;j>=1;j--){
			heapify(heap,i,j);
		}
	}
	return heap;
}
int main(){

	int n,a[100],i;
	printf("\nEnter number of elements");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int* heap=build(a,n);
	display(heap,n);
}