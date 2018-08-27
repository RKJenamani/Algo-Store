#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	float value;
	struct node* next;
} NODE, *NODEPTR;

void bucket_sort( NODEPTR table[],float a[],int n,int m)
{
	int i,index;
	NODEPTR new,temp,insert;
	for(i=0;i<n;i++)
	{
		new=(NODEPTR)malloc(sizeof(NODE));
		new->value=a[i];
		new->next=NULL;
		index=a[i]*m;
		if(table[index]==NULL)
		{
			table[index]=new;
		}
		else
		{
			temp=table[index];
			if(a[i]<temp->value)
			{
				new->next=temp;
				table[index]=new;
			}
			else
			{
				while(temp->next!=NULL && temp->next->value < a[i])
				{	
					temp=temp->next;
				}
			
				if(temp->next==NULL)
					temp->next=new;
				else
				{
					new->next=temp->next;
					temp->next=new;
			}	}
		}
	}
	index=0;
	for(i=0;i<m;i++)
	{
		temp=table[i];
		while(temp!=NULL)
		{
			a[index++]=temp->value;
			temp=temp->next;
		}
	}
}

void main()
{
	float a[100];
	NODEPTR table[100];
	int i,m,n;
	printf("Input multiplying coefficient:");
	scanf("%d",&m);
	printf("Input number of numbers:");
	scanf("%d",&n);
	printf("Input numbers between 0 and 1:");
	for(i=0;i<n;i++)
		scanf("%f",&a[i]);
	for(i=0;i<m;i++)
	    table[i]=NULL;
	bucket_sort(table,a,n,m);
	for(i=0;i<n;i++)
		printf("%f ",a[i]);
}
