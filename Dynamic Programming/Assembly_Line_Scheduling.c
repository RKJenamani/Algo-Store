#include<stdlib.h>
#include<stdio.h>

int min(int a, int b)
{
	if(a<b)
		return a;
	else
		return b;
}
int main()
{
	int n,i;
	int s[2][100],t[2][100],e[2],x[2];
	int T1[100],T2[100];
	printf("Input number of stations:");
	scanf(" %d",&n);
	printf("Input line 1: ");
	for(i=1;i<=n;i++)
		scanf(" %d",&s[0][i]);
	printf("Input line 2: ");
	for(i=1;i<=n;i++)
		scanf(" %d",&s[1][i]);
	printf("Input starttimes: ");
	for(i=0;i<=1;i++)
		scanf(" %d",&e[i]);
	printf("Input endtimes: ");
	for(i=0;i<=1;i++)
		scanf(" %d",&x[i]);
	printf("Input time for transferring for line 1 to line 2:");
	for(i=1;i<=n-1;i++)
		scanf(" %d",&t[0][i]);
	printf("Input time for transferring for line 2 to line 1:");
	for(i=1;i<=n-1;i++)
		scanf(" %d",&t[1][i]);
	T1[1]=e[0]+s[0][1];
	T2[1]=e[1]+s[1][1];
	for(i=2;i<=n;i++)
	{
		T1[i]=min(T1[i-1]+s[0][i],T2[i-1]+s[0][i]+t[1][i-1]);
		T2[i]=min(T2[i-1]+s[1][i],T1[i-1]+s[1][i]+t[0][i-1]);
	}
	printf("Minimum time: %d",min(T1[n]+x[0],T2[n]+x[1]));
	return 0;
}