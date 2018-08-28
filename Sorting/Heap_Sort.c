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
void delete_max(int A[],int *heapSize)
{
	A[1]=A[(*heapSize)--];
	max_heapify(A,heapSize,1);
}
void heap_sort(int A[], int heapSize)
{
	int i,temp;
	build_max_heap(A,&heapSize);
	for(i=(heapSize);i>1;i--)
	{
		temp=A[1];
		delete_max(A,&heapSize);
		A[i]=temp;
	}
}
void main()
{
	int i,a[100],n;
	printf("Input n:");
	scanf("%d",&n);
	printf("Input array:");
	for(i=1;i<n;i++)
		scanf("%d",&a[i]);
	heap_sort(a,n);
	for(i=1;i<n;i++)
		printf(" %d",a[i]);

}