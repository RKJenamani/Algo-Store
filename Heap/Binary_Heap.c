#include<stdio.h>
#include<stdlib.h>

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
void max_heapify(int A[],int *heapSize,int x)
{
	int l=left(x);
	int r=right(x);
	int largest=x;
	if(l<=(*heapSize) && A[l]>A[x])
		largest=l;
	if(r<=(*heapSize) && A[r]>A[largest])
		largest=r;
	if(largest!=x)
	{
		int temp=A[largest];
		A[largest]=A[x];
		A[x]=temp;
		max_heapify(A,heapSize,largest);
	}
}
void build_max_heap(int A[],int *heapSize)
{
	int i;
	int k=((*heapSize)/2);
	for(i=k;i>=1;i--)
		max_heapify(A,heapSize,i);
}
int find_max(int A[],int *heapSize)
{
	return A[1];
}
void delete_max(int A[],int *heapSize)
{
	A[1]=A[(*heapSize)--];
	max_heapify(A,heapSize,1);
}
void insert(int A[],int *heapSize)
{
	int x,i;
	int temp;
	printf("Input Element:");
	scanf("%d",&x);
	A[++(*heapSize)]=x;
	i=(*heapSize);
	while(parent(i)>0)
	{
		if(A[parent(i)]<A[i])
		{
			temp=A[parent(i)];
			A[parent(i)]=A[i];
			A[i]=temp;
			i=parent(i);
		}
		else
			break;
	}
}
void delete(int A[],int *heapSize)
{
	int i,x,temp;
	printf("Input Number to be deleted:");
	scanf("%d",&x);
	for(i=1;i<=(*heapSize);i++)
		if(A[i]==x)
			break;
	A[i]=10000;
	while(parent(i)>0)
	{
		if(A[parent(i)]<A[i])
		{
			temp=A[parent(i)];
			A[parent(i)]=A[i];
			A[i]=temp;
			i=parent(i);
		}
		else
			break;
	}
	delete_max(A,heapSize);

}

void main()
{
	int n,max,i;
	int A[100];
	printf("Input number of elements:");
	scanf("%d",&n);
	printf("Input Numbers:");
	for(i=1;i<=n;i++)
		scanf("%d",&A[i]);
	build_max_heap(A,&n);
	printf("\nHeap:");
	for(i=1;i<=n;i++)
		printf("%d ",A[i]); 
	int a=1;
	while(a)
	{
		printf("\n\nInput: \n\n 0.Exit \n 1.Insert Element \n 2.Delete Element \n 3.Delete Max \n 4.Print Max \n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: insert(A,&n);
					printf("\nHeap:");
					for(i=1;i<=n;i++)
						printf("%d ",A[i]); 
					break;
			case 2: delete(A,&n);
					printf("\nHeap:");
					for(i=1;i<=n;i++)
						printf("%d ",A[i]); 
					break;
			case 3: delete_max(A,&n);
					printf("\nHeap:");
					for(i=1;i<=n;i++)
						printf("%d ",A[i]); 
					break;
			case 4: max=find_max(A,&n);
					printf("\n%d",max);
					break;
		}
	}

}

