#include<stdio.h>
#include<stdlib.h>
int opcount=0;
int partition(int* a,int start,int n){
	int p=a[start],j=n-1,i=start+1,temp,k;
	while(1){
		while(i<n&&a[i]<p){
			i++;
			opcount++;
		}
		while(a[j]>p){
			j--;
			opcount++;
		}
		if(i<j){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}else{
			break;
		}
		
	}
	temp=a[start];
	a[start]=a[j];
	a[j]=temp;
	return j;
}
void quicksort(int* a,int start,int n){
	if(start<n-1){
		int p=partition(a,start,n);
		quicksort(a,start,p);
		quicksort(a,p+1,n);
	}
}
int main(){
	int i,n,a[100];
	printf("\nEnter number of elements");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n);
	printf("\n");
	for(i=0;i<n;i++){
		printf("\t%d",a[i]);
	}
	printf("\nOpcount is %d",opcount);
}