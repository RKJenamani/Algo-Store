#include<stdio.h>
#include<stdlib.h>

int main()
{
	int m,n,K,i,j,k,TS[100][100];
	printf("Input height");
	scanf("%d",&n);
	printf("Input the maximum value of tile");
	scanf("%d",&m);
	printf("Input maximum occurrences of a tile");
	scanf("%d",&K);
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)
		{
			if(i==0 || j==0)
				TS[i][j]=1;
			else
			{
				TS[i][j]=0;
				for(k=0;k<=K;k++)
					if(i>=k)
						TS[i][j]=TS[i][j]+TS[i-k][j-1];
			}
		}
	for(i=0;i<=n;i++)
	{ 
		printf("\n");
		for(j=0;j<=m;j++)
			printf(" %d",TS[i][j]);
	}
	printf("%d",TS[n][m]);
}

