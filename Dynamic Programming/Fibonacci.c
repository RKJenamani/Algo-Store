//nth Fibonacci number

#include<stdio.h>
#include<stdlib.h>

void multiply(int M[2][2], int a[2][2])
{
	int w=M[0][0]*a[0][0]+M[1][0]*a[0][1];
	int x=M[0][0]*a[0][1]+M[1][0]*a[1][1];
	int y=M[1][0]*a[0][0]+M[1][1]*a[0][1];
	int z=M[1][0]*a[0][1]+M[1][1]*a[1][1];

	M[0][0]=w;
	M[0][1]=x;
	M[1][0]=y;
	M[1][1]=z;
}

void main()
{
	int i,n,M[2][2],a[2][2];
	M[0][0]=M[0][1]=M[1][0]=1;
	M[1][1]=0;
	a[0][0]=a[1][0]=a[0][1]=1;
	a[1][1]=0;
	printf("Input n:");
	scanf("%d",&n);
	for(i=1;i<n-1;i++)
	{
		multiply(M,a);
	}
	printf("%dth Fibonacci number is:%d",n,M[0][0]);
}