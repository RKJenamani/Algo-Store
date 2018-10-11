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

void create_undirected_list(node *adj_list[],int n, edg edges[], int m)
{
	int i,j;
	node* temp;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
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
		}
	printf("\nPRINTING UNDIRECTED ADJACENCY LIST: ");
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

void create_directed_list(node *adj_list[],int n, edg edges[], int m)
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
	printf("\nPRINTING DIRECTED ADJACENCY LIST: ");
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
	create_directed_list(adj_list,n,edges,m);
	create_undirected_list(adj_list,n,edges,m);



}