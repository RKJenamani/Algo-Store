#include<stdio.h>
#include<stdlib.h>

int counting_sort(int a[],int b[],int n,int m)
{
	int i,j=0,output[100];
	for(i=0;i<=n;i++)
		b[i]=0;
	for(i=0;i<m;i++)
	{
		printf("%d\n",a[i]);
		b[a[i]]++;
	}
	for(i=1;i<=n;i++)
		b[i]=b[i-1]+b[i];
	for(i=m-1;i>=0;i--)
			output[--b[temp[i]]]=a[i];
	for(i=0;i<m;i++)
		a[i]=output[i];
}

void main()
{
	int a[100],b[100];
	int i,m,n;
	printf("Input upper range:");
	scanf("%d",&n);
	printf("Input number of numbers:");
	scanf("%d",&m);
	printf("Input numbers between 0 and %d:",n);
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
	counting_sort(a,b,n,m);
	for(i=0;i<m;i++)
		printf("%d ",a[i]);
}
