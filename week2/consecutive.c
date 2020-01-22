#include<stdio.h>
#include<stdlib.h>
int gcd(int x,int y){
	int max=1;
	int lim=(x<y)?x:y;
	int op=0;
	for(int i=2;i<=lim;i++){
		if(x%i==0&&y%i==0)
			max=i;
		op++;
	}
	printf("opcount is %d\n",op);
	return max;
}
int main(){
	int x,y;
	printf("\nEnter numbers");
	scanf("%d %d",&x,&y);
	printf("m+n is %d GCD is %d",x+y,gcd(x,y));
}