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

typedef struct 
{
	node *head ;
} STACK ;

void init(STACK **s)//initializes the head pointer
{
	(*s) = (STACK *)malloc(sizeof(STACK));
	(*s)->head=NULL;
}
int isempty(STACK *s)//prints 1 if the stack is empty, 0 otherwise
{
	int k;
	if( s->head==NULL)
		k=1;
	else
		k=0;
	return k;
}
void push(STACK *s, int d)
{
	list temp;
	temp=(list)malloc(sizeof(node));
	temp->data=d;
	temp->next=s->head;
	s->head=temp;
}
	
int pop(STACK *s)
{
	list temp;
	temp=s->head;
	s->head=temp->next;
	temp->next=NULL;
	return temp->data;
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

void DFS(node *adj_list[],int n)
{
	int i,visited[100];
	int distance[100];
	int parent[100];
	int current;
	int previous;
	node* temp;

	for(i=0;i<n;i++)
	{
		parent[i]=-1;
		visited[i]=0;
		distance[i]=0;
	}

	STACK *s=NULL;
	init(&s);
	push(s,0);
	visited[0]=1;
	distance[0]=0;
	parent[0]=-1;
	printf("\nDFS traversal:");
	current=-1;
	while(!isempty(s))
	{
		previous=current;
		current=pop(s);
		parent[current]=previous;
		printf(" %d",current);
		temp=adj_list[current];
		while(temp)
		{
			if(visited[temp->data]==0)
			{
				visited[temp->data]=1;
				distance[temp->data]=distance[current]+1;
				push(s,temp->data);
			}
			temp=temp->next;
		}
	}
	for(i=0;i<n;i++)
		printf("\n %d=parent(%d)",parent[i],i);
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
	DFS(adj_list,n);



}