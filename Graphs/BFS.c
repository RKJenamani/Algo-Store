#include<stdlib.h>
#include<stdio.h>
#include<math.h>

typedef struct _edg
{
	int first;
	int second;
} edg;

typedef struct _node
{
	int data;
	struct _node* next;
}node,*list;

typedef struct q
{
	node *front, *rear ;
} QUEUE ;

void init(QUEUE **qP)//initializes the front and rear pointers
{
	(*qP) = (QUEUE *)malloc(sizeof(QUEUE));
	(*qP)->front=NULL;
	(*qP)->rear=NULL;
}
int isempty(QUEUE *qP)//prints 1 if the queue is emptry, else 0
{
	int k;
	if( qP->front==NULL && qP->rear==NULL)
		k=1;
	else
		k=0;
	return k;

}
void enqueue(QUEUE *qP, int data)
{
	list temp;
	temp=(list)malloc(sizeof(node));
	temp->data=data;
	temp->next=NULL;
	if(qP->front==NULL)
		qP->front=qP->rear=temp;
	else
	{
		(qP->rear)->next=temp;
		qP->rear=temp;
	}
}
int dequeue(QUEUE *qP)
{
	if (qP->front == NULL)
		printf("Queue Empty ");
	else
	{
		list temp;
		int val;
		temp = qP->front;
		val=(qP->front)->data;
		qP->front = (qP->front)->next;
		temp->next = NULL;
		if (qP->front == NULL)
			qP->rear = NULL;
		return val;
	}
}
void create_list(node *adj_list[],int n, edg edges[], int m)
{
	int i,j;
	node* temp;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(edges[j].first==i)
			{
				if(adj_list[i]==NULL)
				{	
					adj_list[i]=(node *)malloc(sizeof(node));
					adj_list[i]->data=edges[j].second;
					adj_list[i]->next=NULL;
				}	
				else
				{
					temp=(node*)malloc(sizeof(node));
					temp->data=edges[j].second;
					temp->next=adj_list[i];
					adj_list[i]=temp;
				}
			}
			else if(edges[j].second==i)
			{
				if(adj_list[i]==NULL)
				{	
					adj_list[i]=(node *)malloc(sizeof(node));
					adj_list[i]->data=edges[j].first;
					adj_list[i]->next=NULL;
				}	
				else
				{
					temp=(node*)malloc(sizeof(node));
					temp->data=edges[j].first;
					temp->next=adj_list[i];
					adj_list[i]=temp;
				}
			}
	printf("PRINTING ADJACENCY LIST: ");
	for(i=0;i<n;i++)
	{
		printf("\n%d::",i);
		temp=adj_list[i];
		while(temp)
		{
			printf("-->%d",temp->data);
			temp=temp->next;
		}
	}
}

void BFS(node *adj_list[],int n)
{
	int i,visited[100];
	int distance[100];
	int parent[100];
	int current;
	node* temp;

	for(i=0;i<n;i++)
	{
		parent[i]=-1;
		visited[i]=0;
		distance[i]=0;
	}

	QUEUE *qP=NULL;
	init(&qP);
	enqueue(qP,0);
	visited[0]=1;
	distance[0]=0;
	parent[0]=-1;
	printf("\nBFS Traversal:");
	while(!isempty(qP))
	{
		current=dequeue(qP);
		printf(" %d",current);
		temp=adj_list[current];
		while(temp)
		{
			if(visited[temp->data]==0)
			{
				visited[temp->data]=1;
				parent[temp->data]=current;
				distance[temp->data]=distance[current]+1;
				enqueue(qP,temp->data);
			}
			temp=temp->next;
		}
	}
}

int main()
{
	edg edges[100];
	node *adj_list[100];
	int i,m,n;
	printf("Input number of vertices:");
	scanf("%d",&n);
	for(i=0;i<100;i++)
		adj_list[i]=NULL;
	printf("Input number of edges:");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		printf("Input Edge:");
		scanf(" %d",&edges[i].first);
		scanf(" %d",&edges[i].second);
	}
	create_list(adj_list,n,edges,m);
	BFS(adj_list,n);



}