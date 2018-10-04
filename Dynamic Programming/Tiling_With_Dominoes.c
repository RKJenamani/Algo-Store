#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n,i;
	int A[100],B[100];
	printf("Input n: ");
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		A[i]=0;
		B[i]=0;
	}
	A[2]=3;
	B[1]=1;
	for(i=3;i<=n;i++)
	{
		if(i%2==0)
			A[i]=A[i-2]+2*B[i-1];
		else
			B[i]=B[i-2]+A[i-1];
	}
	printf("Number of ways to tile the board: %d",A[n]);
	return 0;
}
