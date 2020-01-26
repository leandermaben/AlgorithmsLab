#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int match(char* s,char* sub){
	int i,j;
	for(i=0;i<strlen(s);i++){
		for(j=0;j<strlen(sub);j++){
			if(s[i+j]!=sub[j])
				break;
		}
		if(j==strlen(sub))
			return i;
	}
	return -1;
}
int main(){
	char s[100],sub[100];
	printf("\nEnter string and substring");
	scanf("%s",s);
	scanf("%s",sub);
	int x=match(s,sub);
	if(x==-1){
		printf("\nNot Found");
	}else{
		printf("\nFound at %d",x);
	}
}