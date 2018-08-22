#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int key;
	struct node* next;
} NODE, * NODEPTR;



void chainhash_input(NODEPTR table[],int len)
{
	int input,index,i,num;
	NODEPTR temp;
	printf("Number of numbers:");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		printf("INPUT NUMBER:");
		scanf("%d",&input);
		index=input%len;	
		printf("%d",index);
		if(table[index]==NULL)
		{
		    table[index]=(NODEPTR)malloc(sizeof(NODE));
	    	table[index]->key=input;
		    table[index]->next=NULL;
		}
		else
		{
    		temp=table[index];
    		while(temp->next!=NULL)
    				temp=temp->next;
    		temp->next=(NODEPTR)malloc(sizeof(NODE));
    		temp->next->key=input;
    		temp->next->next=NULL;
		}
	}
}
void chainhash_display(NODEPTR table[],int len)
{
	int i;
	NODEPTR temp;
	printf("\nPRINTING HASH TABLE:");
	for(i=0;i<len;i++)
	{
		temp=table[i];
		printf("\n::");
		while(temp!=NULL)
		{
			printf("--%d",temp->key);
			temp=temp->next;
		}
	}

}
NODEPTR chainhash_search(NODEPTR table[],int len,int input,NODEPTR *prev)
{
	int index,flag=0;
	NODEPTR temp;
	*prev=NULL;
	index=input%len;
	temp=table[index];
	if(temp==NULL)
		return NULL;
	if(temp->key==input)
	{
		printf("FOUND");
		flag=1;
		(*prev)=NULL;
		return temp;
	}
	while(temp!=NULL)
	{
		if(temp->key==input)
		{
			printf("FOUND");
			flag=1;
			return temp;
		}
		(*prev)=temp;
		temp=temp->next;
	}
	
	if(flag==0)
		printf("NOT FOUND");
	return NULL;

}
void chainhash_delete(NODEPTR table[],int len)
{
	int input,i,flag=0,index;
	NODEPTR temp;
	NODEPTR prev;
	printf("INPUT NUMBER TO DELETE:");
	scanf("%d",&input);
	index=input%len;
	temp=chainhash_search(table,len,input,&prev);
	if(temp!=NULL)
	{
		if(prev==NULL)
		{
			table[index]=temp->next;
		}
		else
		{
			printf("%d--%d",prev->key,temp->key);
			prev->next=temp->next;
			temp->next=NULL;
		}
	}


}


void main()
{
		NODEPTR table[100];
		int i,control=1;
		for(i=0;i<100;i++)
				table[i]=NULL;
		while(control!=0)
		{
			printf("Input 1 to input, 2 to display, 3 to delete, 0 to exit");
			scanf("%d",&control);
			if(control==1)
				chainhash_input(table,5);
			else if(control==2)
				chainhash_display(table,5);
			else if(control==3)
				chainhash_delete(table,5);
			else
				printf("TERMINATING");
		}
}