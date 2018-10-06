#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[100];
	int DP[100][100];
	int i,j,k,n,min,h;
	printf("Input number of matrices+1: ");
	scanf("%d",&n);
	printf("Input array of Dimensions: ");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		DP[i][i]=0;
	for(h=1;h<n-1;h++)
		for(i=1;i<=n-h-1;i++)
		{
			j=i+h;
			min=DP[i][i]+DP[i+1][j]+a[i]*a[i+1]*a[j+1];
			for(k=i+1;k<j;k++)
			{
				if((DP[i][k]+DP[k+1][j]+a[i]*a[k+1]*a[j+1])<min)
					min=(DP[i][k]+DP[k+1][j]+a[i]*a[k+1]*a[j+1]);
			}
			DP[i][j]=min;
		}
	printf("\nMinimum number of operations required is: %d",DP[1][n-1]);
	return 0;
}