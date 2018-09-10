#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int price[100],DP[100];
	int n,i,j,max;
	printf("Input length: ");
	scanf("%d",&n);
	printf("Input prices: ");
	for(i=1;i<=n;i++)
		scanf("%d",&price[i]);
	DP[1]=price[1];
	for(i=2;i<=n;i++)
	{
		max=DP[1]+DP[i-1];
		for(j=2;j<=(i/2);j++)
			if(DP[j]+DP[i-j]>max)
				max=DP[j]+DP[i-j];
		if(max>price[i])
			DP[i]=max;
		else
			DP[i]=price[i];
	}
	printf("Maximum obtainable value: %d",DP[n]);


	return 0;
}