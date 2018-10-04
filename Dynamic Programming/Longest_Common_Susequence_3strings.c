#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int main()
{
	char input1[100],input2[100],input3[100];
	int DP[100][100][100];
	int i,j,k;
	printf("Input string 1:");
	scanf(" %s",input1);
	printf("Input string 2:");
	scanf(" %s",input2);
	printf("Input string 3:");
	scanf(" %s",input3);
	for(i=0;i<=strlen(input1);i++)
		for(j=0;j<=strlen(input2);j++)
			for(k=0;k<=strlen(input3);k++)
			{
				if(i==0 || j==0 || k==0)
					DP[i][j][k]=0;
				else if(input1[i-1]==input2[j-1] && input2[j-1]==input3[k-1])
					DP[i][j][k]=DP[i-1][j-1][k-1]+1;
				else
					DP[i][j][k]=max(DP[i][j][k-1],max(DP[i][j-1][k],DP[i-1][j][k]));
		}
	printf("\nLength of LCS is %d",DP[strlen(input1)][strlen(input2)][strlen(input3)]);
	return 0;
}
