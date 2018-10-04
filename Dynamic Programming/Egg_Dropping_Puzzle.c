#include<stdio.h>
#include<stdlib.h>

int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int main()
{
	int DP[100][100];
	int n,f,i,j,min,k;
	printf("Input number of floors: ");
	scanf("%d",&n);
	printf("Input number of eggs: ");
	scanf("%d",&f);
	for(i=1;i<=f;i++)
	{
		DP[i][0]=0;
		DP[i][1]=1;
	}
	for(i=1;i<=n;i++)
		DP[1][i]=i;
	for(i=2;i<=f;i++)
	{
		for(j=2;j<=n;j++)
		{
			min=1000;
			for(k=1;k<=j;k++)
			{
				if(min>max(DP[i][j-k],DP[i-1][k-1]))
					min=max(DP[i][j-k],DP[i-1][k-1]);
			}
			DP[i][j]=min+1;
		}
	}
	printf("The minimum number of trials required is: %d",DP[f][n]);
}