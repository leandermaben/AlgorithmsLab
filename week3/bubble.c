#include<stdio.h>
#include<stdlib.h>
int opcount=0;
void bubble(int* a,int n){
	int i,j,temp;
	opcount=0;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				opcount++;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
int main(){
	int n,i;
	int a[100];
	//printf("\nEnter number of elements.");
	//scanf("%d",&n);
	//int*a=malloc(n*sizeof(int));
	/*for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}*/
	for(i=1;i<21;i++){
		for(int j=0;j<i;j++){
			a[j]=i-j;
		}
		bubble(a,i);
		printf("\nopcount: %d \tn: %d",opcount,i);
	}
	
	printf("\n");
	/*for(i=0;i<n;i++){
		printf("\t%d",a[i]);
	}*/
}