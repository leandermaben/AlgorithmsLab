#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int vertex;
	int distance;
	int tree;
} node;

typedef struct pqueue{
	int index[1000];
	node** arr;
	int length; 
}pqueue;

void initialize(pqueue* pq){
	pq->arr=malloc(1000*sizeof(node*));
	pq->length=0;
}
void heapify(pqueue* pq,int index){
	int l=2*index;
	int r=l+1;
	int smallest=index;
	node* temp;
	if(l<=pq->length&&pq->arr[l]<pq->arr[smallest])
		smallest=l;
	if(r<=pq->length&&pq->arr[r]<pq->arr[smallest])
		smallest=r;
	if(smallest!=index){
		pq->index[pq->arr[index]->vertex]=smallest;
		pq->index[pq->arr[smallest]->vertex]=index;
		temp=pq->arr[smallest];
		pq->arr[smallest]=pq->arr[index];
		pq->arr[index]=temp;
		heapify(pq,smallest);
	}
}

void addVertex(pqueue* pq,node* v){
	int par=(pq->length+1)/2;
	int cur=pq->length+1;
	node* temp;
	pq->arr[pq->length+1]=v;
	pq->index[pq->length]=pq->length+1;
	pq->length=pq->length+1;
	//Next part not required
	while(par&&pq->arr[par]->distance>pq->arr[cur]->distance){
		pq->index[pq->arr[par]->vertex]=cur;
		pq->index[pq->arr[cur]->vertex]=par;
		temp=pq->arr[par];
		pq->arr[par]=pq->arr[cur];
		pq->arr[cur]=temp;
		cur=par;
		par=cur/2;
	}
}
node* dequeue(pqueue* pq){
	if(pq->length==0)
		return NULL;
	pq->index[pq->arr[1]->vertex]=-1;
	pq->index[pq->arr[pq->length]->vertex]=1;
	node* temp=pq->arr[1];
	pq->arr[1]=pq->arr[pq->length];
	pq->length=pq->length-1;
	heapify(pq,1);
	return temp;
}
node* decrease(pqueue* pq,int v,int d,int tree){
	pq->arr[pq->index[v]]->distance=d;
	pq->arr[pq->index[v]]->tree=tree;
	heapify(pq,pq->index[v]);
} 
int main(){
	int i,j,n,s,d,weight[1000][1000],dist[1000],p[1000];
	node *temp,*cur;
	pqueue pq;
	initialize(&pq);
	printf("\nEnter number of vertices");
	scanf("%d",&n);
	printf("\nEnter weight matrix");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&weight[i][j]);
		}
	}
	for(i=0;i<n;i++){
		temp=malloc(sizeof(node));
		temp->vertex=i;
		temp->distance=10000;
		temp->tree=-1;
		addVertex(&pq,temp);
	}
	printf("Enter source vertex");
	scanf("%d",&s);
	decrease(&pq,s,0,s);
	for(i=0;i<n;i++){
		cur=dequeue(&pq);
		p[cur->vertex]=cur->tree;
		dist[cur->vertex]=cur->distance;
		for(j=1;j<=pq.length;j++){
			if(weight[cur->vertex][pq.arr[j]->vertex]!=10000){
				d=weight[cur->vertex][pq.arr[j]->vertex]+cur->distance;
				if(d<pq.arr[j]->distance)
					decrease(&pq,pq.arr[j]->vertex,d,cur->vertex);
			}
		}
	}
	printf("\n vertex distance tree\n");
	for(i=0;i<n;i++){
		printf("%d %d %d\n",i,dist[i],p[i]);
	}
	return 0;
}