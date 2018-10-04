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
	char input[100],output[100];
	int DP[100][100];
	int i,j;
	printf("Input string: ");
	scanf(" %s",input);
	int flag=0;
	for(i=0;i<=strlen(input);i++)
		for(j=0;j<=strlen(input);j++)
		{
			if(i==0 || j==0)
				DP[i][j]=0;
			else if(input[i-1]==input[j-1] && i!=j)
				DP[i][j]=DP[i-1][j-1]+1;
			else
				DP[i][j]=max(DP[i][j-1],DP[i-1][j]);
		}

	int temp=DP[strlen(input)][strlen(input)];
	i=strlen(input);
	i=strlen(input);
	int k=0;
	while(i>0 && j>0)
	{
		if(input[i-1]==input[j-1] && i!=j)
		{
			output[k++]=input[i-1];
			i--;
			j--;
		}
		else if(DP[i][j-1]>DP[i-1][j])
			j--;
		else
			i--;
	}
	printf("\nLength of LRS is %d",DP[strlen(input)][strlen(input)]);
	printf("\nLRS: ");
	for(i=k-1;i>=0;i--)
		printf("%c",output[i]);
	return 0;
}
