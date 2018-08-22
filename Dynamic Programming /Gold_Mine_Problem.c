//Gold_Mine_Problem
#include<stdio.h>
#include<stdlib.h>

int max(int a, int b)
{
	if(a>b)
		return a;
	return b;
}

void main()
{
	int mat[100][100],a[100][100];
	int n,i,j,max_value=0,right,right_up,right_down;
	printf("Input value of n:");
	scanf("%d",&n);
	printf("Input Matrix:");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf(" %d",&mat[i][j]);
		}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf(" %d",mat[i][j]);
		printf("\n");
	}
	for(i=1;i<=n;i++)
		a[i][n]=mat[i][n];
	for(j=n-1;j>0;j--)
		for(i=n;i>0;i--)
		{
			right=a[i][j+1];
			right_up=((i-1)>0)?a[i-1][j+1]:0;
			right_down=((i+1)<=n)?a[i+1][j+1]:0;
			a[i][j]=mat[i][j]+max(right,max(right_up,right_down));
		}
	for(i=1;i<=n;i++)
	{
		max_value=max(max_value,a[i][1]);
	}
	printf("Answer:%d",max_value);


}