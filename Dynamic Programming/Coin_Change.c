//coin change

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int S[100];
	int a[100][100];
	int n,x,y,m,i,j;
	printf("Input value of n:");
	scanf("%d",&n);
	printf("Input value of m:");
	scanf("%d",&m);
	printf("Input values of available coins:");
	for(i=1;i<=m;i++)
		scanf(" %d",&S[i]);
	for(i=1;i<n;i++)
		a[0][i]=1;
	for(i=1;i<=n+1;i++)
	{
		if(i%S[1]==0)
			a[i][1]=1;
		else
			a[i][1]=0;
	}
	for(j=2;j<=n;j++)
		for(i=1;i<=(n+1);i++)
		{
			x=(j>1)?a[i][j-1]:0;
			y=((i-S[j])>=0)?a[i-S[j]][j]:0;
			a[i][j]=x+y;
			//printf("(%d,%d)=(%d,%d)+(%d,%d)--%d--%d--%d\n",i,j,i,j-1,i-S[j],j,x,y,a[i][j]);
		}
	/*for(i=1;i<=(n+1);i++)
	{
		for(j=1;j<=n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}*/
	printf("Number of ways to make change:%d",a[n][m]);
}