#include<stdio.h>
#include<stdlib.h>

void fibonacci(int n)
{
	int a,b,c;
	a=1;
	b=0;
	if(n>=0)
		printf("%d ",0);
	if(n>=1)
		printf("%d ",1);
	for(int i=2;i<=n;i++)
	{
		printf("%d ",a+b);
		a=a+b;  //a=a+b & b=a
		b=a-b;
	}
}

int main()
{
	int n;
	printf("Enter n: ");
	scanf("%d",&n);
	fibonacci(n);
}