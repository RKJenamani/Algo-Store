#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
	int vno;
	int weight;
	struct _node *next;
} node;

typedef struct _vertex
{
	int number;
	node *adjlist;
	int dist;
	int parent; // stores articulation points
} vertex;

typedef vertex *graph;

int parent(int i)
{
	return i/2;
}
int left(int i)
{
	return 2*i;
}
int right(int i)
{
	return 2*i+1;
}
int swap(int *a,int *b)
{
	int temp;
	temp=(*a);
	(*a)=(*b);
	(*b)=temp;
}
void min_heapify(vertex A[],int *heapSize,int position[],int x)
{
	int l=left(x);
	int r=right(x);
	int smallest=x;
	if(l<=(*heapSize) && A[l].dist<A[x].dist)
		smallest=l;
	if(r<=(*heapSize) && A[r].dist<A[smallest].dist)
		smallest=r;
	if(smallest!=x)
	{
		swap(&position[A[smallest].number],&position[A[x].number]);
		vertex temp=A[smallest];
		A[smallest]=A[x];
		A[x]=temp;
		min_heapify(A,heapSize,position,smallest);
	}
}
void build_min_heap(vertex A[],int *heapSize, int position[])
{
	int i;
	int k=((*heapSize)/2);
	for(i=k;i>=1;i--)
		min_heapify(A,heapSize,position,i);
}

vertex extract_min(vertex A[],int *heapSize,int position[])
{
	vertex temp=A[1];
	position[A[(*heapSize)].number]=1;
	position[A[1].number]=-1;
	A[1]=A[(*heapSize)--];
	min_heapify(A,heapSize,position,1);
	return temp;
}
void decrease_key(vertex A[],int *heapSize,int position[],int v,int amt)
{
	int i;
	vertex temp;
	A[position[v]].dist=amt;
	i=position[v];
	while(parent(i)>0)
	{
		if(A[parent(i)].dist>A[i].dist)
		{
			swap(&position[A[parent(i)].number],&position[A[i].number]);
			temp=A[parent(i)];
			A[parent(i)]=A[i];
			A[i]=temp;
			i=parent(i);
		}
		else
			break;
	}
}
void primsMST( vertex G[], int n)
{
	int i;
	vertex H[n+1];
	int position[n+1];
	node *temp;
	vertex temp_vertex;
	int heapSize=n;
	for(i=1;i<=n;i++)
		H[i]=G[i-1];
	for(i=0;i<n;i++)
		position[i]=i+1;
	H[1].dist=0;
	while(heapSize>=1)
	{

		printf("\n");
		for(i=1;i<=heapSize;i++)
			printf("\n For node %d : parent=%d",H[i].number,H[i].parent);
		printf("\n");
		for(i=0;i<n;i++)
			printf("%d ",position[i]);
		temp_vertex=extract_min(H,&heapSize,position);
		G[temp_vertex.number]=temp_vertex;
		printf("\n Minimum vertex number:%d ",temp_vertex.number);
		temp=temp_vertex.adjlist;
		while(temp)
		{			
			if(position[temp->vno]!=(-1) && H[position[temp->vno]].dist>temp->weight)
			{
				printf(" -%d",temp->vno);
				H[position[temp->vno]].parent=temp_vertex.number;
				decrease_key(H,&heapSize,position,temp->vno,temp->weight);
			}
			temp=temp->next;
		}
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("\n For node %d : parent=%d",i,G[i].parent);
	}

}

int main()
{
	int n,e,degree,i,k,l,w;
	graph G;
	node *temp;
	printf("Enter the number of vertices and edges: ");
	scanf(" %d",&n);
	scanf(" %d",&e);
	G=(graph)malloc(n*sizeof(vertex));
	for(i=0;i<n;i++)
	{
		G[i].number=i;
		G[i].adjlist=NULL;
		G[i].dist=10000;
		G[i].parent=-1;
	}
	printf("Enter the neighbors for each of the vertex:\n");
	for(i=0;i<n;i++)
	{
		printf("Degree of vertex %d: ",i);
		scanf(" %d",&degree);
		printf("Neighbors of %d: ",i);
		while(degree--)
		{
			scanf(" %d",&k);
			printf(" Weight of edge %d--%d :",i,k);
			scanf(" %d",&w);
			if(G[i].adjlist==NULL)
			{
				G[i].adjlist=(node*)malloc(sizeof(node));
				G[i].adjlist->vno=k;
				G[i].adjlist->weight=w;
				G[i].adjlist->next=NULL;
			}
			else
			{
				temp=(node*)malloc(sizeof(node));
				temp->vno=k;
				temp->weight=w;
				temp->next=G[i].adjlist;
				G[i].adjlist=temp;
			}
		}
	}
	printf("\nAdjacency list of the graph:");
	for(i=0;i<n;i++)
	{
		printf("\nVertex %d: ",i);
		temp=G[i].adjlist;
		while(temp)
		{
			printf("%d--%d ",temp->vno,temp->weight);
			temp=temp->next;
		}
	}
	printf("\n");
	primsMST(G,n);
	free(G);
	return 0;
}
	


































