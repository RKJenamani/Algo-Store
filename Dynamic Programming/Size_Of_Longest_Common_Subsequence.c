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
	char input1[100],input2[100],output[100];
	int DP[100][100];
	int i,j;
	printf("Input string 1:");
	scanf(" %s",input1);
	printf("Input string 2:");
	scanf(" %s",input2);
	int flag=0;
	for(i=0;i<=strlen(input1);i++)
		for(j=0;j<=strlen(input2);j++)
		{
			if(i==0 || j==0)
				DP[i][j]=0;
			else if(input1[i-1]==input2[j-1])
				DP[i][j]=DP[i-1][j-1]+1;
			else
				DP[i][j]=max(DP[i][j-1],DP[i-1][j]);
		}
	printf("\nLength of LCS is %d",DP[strlen(input1)][strlen(input2)]);
	return 0;
}

//To print the LCS, traverse the 2D array starting from DP[strlen(input1)][strlen(input2)]. Do following for every cell L[i][j]
// 1. If characters (in input1 and input2) corresponding to DP[i][j] are same (Or input1[i-1] == input2[j-1]), then include this character as part of LCS.
// 2. Else compare values of DP[i-1][j] and DP[i][j-1] and go in direction of greater value