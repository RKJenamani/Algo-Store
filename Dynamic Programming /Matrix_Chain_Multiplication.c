#include<stdio.h>
#include<stdlib.h>

void print_brackets(int brackets[100][100],int i, int j)
{
	if(i==j)
		printf("A");
	else
	{
		printf("(");
		print_brackets(brackets,i,brackets[i][j]);
		print_brackets(brackets,brackets[i][j]+1,j);
		printf(")");
	}
}

int main()
{
	int a[100];
	int DP[100][100],brackets[100][100];
	int i,j,k,n,l,q;
	printf("Input number of matrices: ");
	scanf("%d",&n);
	printf("Input array of Dimensions (%d dimensions): ",n+1);
	for(i=0;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		DP[i][i]=0;
	for(l=2;l<=n;l++)
		for(i=1;i<=n-l+1;i++)
		{
			j=l+i-1;
			DP[i][j]=100000;
			for(k=i;k<j;k++)
			{
				q=a[i-1]*a[k]*a[j]+DP[i][k]+DP[k+1][j];
				if(q<DP[i][j])
				{
					DP[i][j]=q;
					brackets[i][j]=k;
				}
			}
		}
	printf("\nMinimum number of operations required is: %d",DP[1][n]);
	printf("\nThe brackets must be printed in the order: ");
	print_brackets(brackets,1,n);
	return 0;
}
