#include<stdio.h>
#include<stdlib.h>

int partition(int a[],int lower,int upper)
{
	int i,j,pivot,temp;
	pivot=a[lower];
	j=lower;
	for(i=lower;i<=upper;i++)
	{
		if(a[i]<pivot)
		{
			temp=a[j];
			a[j]=a[i];
			a[i]=temp;
			j++;
		}
	}
	return j;
}

void quick_sort(int a[],int lower,int upper)
{
	if(lower<upper)
	{
		int pi=partition(a,lower,upper);
		quick_sort(a,lower,pi);
		quick_sort(a,pi+1,upper);
	}
}

void main()
{
	int i,a[100],n;
	printf("Input n:");
	scanf("%d",&n);
	printf("Input array:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quick_sort(a,0,n-1);
	for(i=0;i<n;i++)
		printf(" %d",a[i]);

}