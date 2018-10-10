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
void DFS_visit(node *adj_list[],int n, int *time, int discovery_time[], int finishing_time[], int parent[], int visited[],int vertex)
{
	printf("%d ", vertex);
	visited[vertex]=1;
	(*time)=(*time)+1;
	discovery_time[vertex]=(*time);
	node *temp=adj_list[vertex];
	while(temp)
	{
		if(visited[temp->data]==0)
		{
			parent[temp->data]=vertex;
			DFS_visit(adj_list,n,time,discovery_time,finishing_time,parent,visited,temp->data);
		}
		temp=temp->next;
	}
	(*time)=(*time)+1;
	finishing_time[vertex]=(*time);

}

void DFS(node *adj_list[],int n)
{
	int i,visited[100];
	int discovery_time[100];
	int finishing_time[100];
	int parent[100];
	int time;
	node* temp;

	for(i=0;i<n;i++)
	{
		parent[i]=-1;
		visited[i]=0;
		discovery_time[i]=0;
		finishing_time[i]=0;
	}
	printf("k");
	time=0;
	for(i=0;i<n;i++)
		if(visited[i]==0)
			DFS_visit(adj_list,n,&time,discovery_time,finishing_time,parent,visited,i);	
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