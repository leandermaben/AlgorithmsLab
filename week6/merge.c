#include<stdio.h>
#include<stdlib.h>
int opcount=0;
void merge(int*f,int fn,int* l,int ln,int*a,int n){
	int i=0,j=0,k=0,m;
	while(j!=fn&&k!=ln){
		if(f[j]<l[k]){
			a[i++]=f[j++];
			opcount++;
		}else if(f[j]==l[k]){
			a[i++]=f[j++];
			a[i++]=l[k++];
			opcount++;
		}else{
			opcount++;
			a[i++]=l[k++];
		}
	}
	if(j!=fn){
		for(m=j;m<fn;m++){
			a[i++]=f[m];
		}
	}else if(k!=ln){
		for(m=k;m<ln;m++){
			a[i++]=l[m];
		}
	}
}
void mergesort(int* a,int n){
	int f[100],l[100],i,k=0;
	if(n==1)
		return;
	for(i=0;i<n/2;i++){
		f[i]=a[i];
	}
	for(i=n/2;i<n;i++){
		l[k++]=a[i];
	}
	mergesort(f,n/2);
	mergesort(l,n-n/2);
	merge(f,n/2,l,n-n/2,a,n);
}
int main(){
	int i,n,a[100];
	printf("\nEnter number of elements");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	mergesort(a,n);
	printf("\n");
	for(i=0;i<n;i++){
		printf("\t%d",a[i]);
	}
	printf("\nOpcount is %d",opcount);
}