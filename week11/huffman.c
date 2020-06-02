#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	float prob;
	char c;
	stuct node* left;
	stuct node* right;
}node;
typedef struct pqueue{
	node* arr[1000];
	int length;
}pqueue;
void initialize(pqueue* pq){
	pq->length=0;
}
void heapify(pqueue* pq,int index){
	int l=2*index;
	int r=l+1;
	int smallest=index;
	node* temp;
	if(l<=pq->length&&pq->arr[l]->prob<pq->arr[index]->prob)
		smallest=l;
	if(r<=pq->length&&pq->arr[r]->prob<pq->arr[index]->prob)
		smallest=r;
	if(smallest!=index){
		temp=pq->arr[index];
		pq->arr[index]=pq->arr[smallest];
		pq->arr[smallest]=temp;
		heapify(pq,smallest);
	}
}
void createHeap(pqueue* pq,node** arr,int n){
	int n;
	for(i=1;i<=n;i++){
		pq->arr[i]=arr[i-1];
		pq->length=pq->length+1;
	}
	pq->length=n;
	for(i=n/2;i>0;i--){
		heapify(pq,i);
	}
}
void enqueue(pqueue* pq,node* n){
	pq->length=pq->length+1;
	pq->arr[pq->length]=n;
	cur=pq->length;
	 par=pq->length/2;
	lli temp;
	while(par&&pq->arr[cur]<pq->arr[par]){
		temp=pq->arr[cur];
		pq->arr[cur]=pq->arr[par];
		pq->arr[par]=temp;
	}
}
node* dequeue(pqueue* pq){
	if(pq->length==0)
		return NULL;
	node* temp=pq->arr[1];
	pq->arr[1]=pq->arr[pq->length];
	pq->length=pq->length-1;
	heapify(pq,1);
}
void initQueue(pqueue* pq,char s[]){
	int i,k=0,count=0,hash[300];
	node* list[300];
	for(i=0;i<300;i++)
		hash[i]=0;
	for(i=0;s[i]!='\0';i++){
		if(hash[s[i]]==0)
			count++;
		hash[s[i]]++;
	}
	for(i=0;i<300;i++){
		if(hash[i]){
			list[k]=malloc(sizeof(node));
			list[k]->left=NULL;
			list[k]->right=NULL;
			list[k]->c=i;
			list[k]->prob=(float)hash[i]/count;
			k++;
		}
	}
	initialize(pq);
	createHeap(pq,list,k);
}
node* createTree(pqueue* pq){
	node *first,*second,*temp;
	if(pq->length==0)
		return NULL;
	while(pq->length!=1){
		first=dequeue(pq);
		second=dequeue(pq);
		temp=malloc(sizeof(node));
		temp->prob=first->prob+second->prob;
		temp->left=first;
		temp->right=second;
		enqueue(pq,temp);
	}
	return dequeue(pq);
}
int main(){

}