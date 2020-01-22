#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int op;
int* sieve(int x){
	int i,j;
	if(x<2)
		x=2;
	int* s= malloc((x+1)*sizeof(int));
	s[0]=0;
	s[1]=0;
	for(i=2;i<=x;i++){
		s[i]=1;
	} 
	for(i=2;i*i<x;i++){
		if(s[i]==1){
			for(j=i*i;j<=x;j+=i){
				s[j]=0;
			}
		}
	}
	return s;
}
int* prime(int* s,int x){
	op=0;
	int i;
	int *p=malloc(x*sizeof(int));
	int len=0,c=1;
	for(i=2;i<=x;i++){
		if(s[i]==1){
			p[c++]=i;
			len++;
		}
		op++;
	}
	p[0]=len;
	printf("opcount is %d\n",op);
	return p;
}
int* factors(int* p,int x){
	int i,n;
	int* f=malloc((x+1)*sizeof(int));
	for(i=0;i<=x;i++){
		f[i]=0;
	}
	for(i=1;i<=p[0];i++){
		n=x;
		while(n%p[i]==0){
			n/=p[i];
			f[p[i]]++;
		}
	}
	return f;
}
int power(int x,int y){
	int res=1;
	for(int i=0;i<y;i++){
		res*=x;
	}
	return res;
}
int gcd(int x,int y){
	int i,n;
	int res=1;
	int max=(x>y)?x:y;
	int min=(x<y)?x:y;;
	int*s=sieve(max);
	int*p=prime(s,max);
	int* f1=factors(p,x);
	int* f2=factors(p,y);
	for(i=0;i<=min;i++){
		n=(f1[i]<f2[i])?f1[i]:f2[i];
		res=res*power(i,n);

	}
	return res;
}
int main(){
	int x,y;
	printf("\nEnter numbers");
	scanf("%d %d",&x,&y);
	printf("m+n is %d GCD is %d",x+y,gcd(x,y));
}