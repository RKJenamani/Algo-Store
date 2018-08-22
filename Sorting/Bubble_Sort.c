#include<stdio.h>
#include<stdlib.h>

int bubble_sort(int a[],int n)
{
	int i,j,flag,temp;
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
			{
				flag=1;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		if(flag==0)
			break;
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
	bubble_sort(a,n);
	for(i=0;i<n;i++)
		printf(" %d",a[i]);

}