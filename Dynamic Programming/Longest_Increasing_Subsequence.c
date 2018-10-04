#include<stdio.h>
#include<stdlib.h>

typedef struct _set
{
	int array[100];
	int size;
} set;

int main()
{
	int a[100];
	set DP[100];
	int i,n,j,max,index;
	printf("Input size:");
	scanf(" %d",&n);
	printf("Input numbers:");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	DP[1].size=1;
	DP[1].array[1]=a[1];
	for(i=2;i<=n;i++)
	{
		max=0;
		for(j=1;j<i;j++)
			if(a[i]>a[j] && DP[j].size>max)
			{
				index=j;
				max=DP[j].size;
			}
		for(j=1;j<=DP[index].size;j++)
			DP[i].array[j]=DP[index].array[j];
		DP[i].array[j]=a[i];
		DP[i].size=j;
	}
	max=DP[1].size;
	index=1;
	for(i=2;i<=n;i++)
	{
		if(DP[i].size>max)
		{
			max=DP[i].size;
			index=i;
		}
	}
	printf("\nLength of LIS is %d",DP[index].size);
	printf("\nLIS: ");
	for(i=1;i<=DP[index].size;i++)
		printf("%d ",DP[index].array[i]);
	return 0;
}
