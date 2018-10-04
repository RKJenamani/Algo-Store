//nth Bell Number and Bell Triangle

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int n,i,j,stirling[100][100];
	printf("Input value of n:");
	scanf("%d",&n);
	stirling[0][0]=1;
	for(i=1;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			if( j==0 )
				stirling[i][j]=stirling[i-1][i-1];
			else
				stirling[i][j]=stirling[i-1][j-1]+stirling[i][j-1];
		}
	}
	printf("Bell Triangle: \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
			printf("%d ",stirling[i][j]);
		printf("\n");
	}
	printf("%dth Bell Number is:%d",n,stirling[n-1][n-1]);

}