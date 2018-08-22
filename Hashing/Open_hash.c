#include<stdlib.h>
#include<stdio.h>

//1->number present 0->empty -1->number deleted

void openhash_insert(int table[],int tracker[],int len)
{
	int n,i,input,index;
	printf("Input number of insertions");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Input Number:");
		scanf("%d",&input);
		index=input%len;
		while(tracker[index]==1)
		{
			index=(index+1)%len;
		}
		tracker[index]=1;
		table[index]=input;
	}
}

int openhash_search(int table[],int tracker[],int len,int input)
{
	int i,index;
	index=input%len;
	while(tracker[index]==1 || tracker[index]==-1)
	{
		if(tracker[index]==1 && table[index]==input)
			return index;
		index=(index+1)%len;
	}
	return -1;
}

void openhash_delete(int table[],int tracker[],int len)
{
	int i,input,index;
	printf("Input Number:");
	scanf("%d",&input);
	index=openhash_search(table,tracker,len,input);
	if(index==-1)
		printf("Number not found");
	else
		tracker[index]=-1;
}

void openhash_display(int table[],int tracker[],int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		if(tracker[i]==1)
			printf("\n%d",table[i]);
		else
			printf("\n");
	}
}

void main()
{
	int table[25],tracker[25],len,i,control=1;
	printf("Input size of table:");
	scanf("%d",&len);
	for(i=0;i<len;i++)
		tracker[i]=0;
	while(control!=0)
	{
		printf("Input 1 to input, 2 to display, 3 to delete, 0 to exit");
		scanf("%d",&control);
		if(control==1)
			openhash_insert(table,tracker,len);
		else if(control==2)
			openhash_display(table,tracker,len);
		else if(control==3)
			openhash_delete(table,tracker,len);
		else
			printf("TERMINATING");
	}
}