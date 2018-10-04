#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[100],DP[100];
	int i,n,j,max;
	printf("Input size:");
	scanf(" %d",&n);
	printf("Input numbers:");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	DP[1]=1;
	for(i=2;i<=n;i++)
	{
		max=0;
		for(j=1;j<i;j++)
			if(a[i]>a[j] && DP[j]>max)
				max=DP[j];
		DP[i]=max+1;
	}
	max=DP[1];
	for(i=2;i<=n;i++)
		if(DP[i]>max)
			max=DP[i];
	printf("Length of LIS is %d",max);
	return 0;
}