#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	int DP[100];
	int n,i;
	printf("Input n: ");
	scanf("%d",&n);
	DP[0]=1;
	DP[1]=1;
	for(i=2;i<=n;i++)
	{
		DP[i]=2*DP[i-1]+DP[i-2];
	}
	printf("%dth Newman Shanks Williams prime is %d",n,DP[n]);
	return 0;
}