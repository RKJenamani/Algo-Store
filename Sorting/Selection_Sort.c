#include<stdio.h>
#include<stdlib.h>

int selection_sort(int a[],int n)
{
	int i,j,min,index;
	for(i=0;i<n-1;i++)
	{
		min=a[i];
		index=i;
		for(j=i+1;j<n;j++)
			if(a[j]<min)
			{
				min=a[j];
				index=j;
			}
		a[index]=a[i];
		a[i]=min;
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
	selection_sort(a,n);
	for(i=0;i<n;i++)
		printf(" %d",a[i]);

}