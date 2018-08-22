//Print the nth ugly number

#include<stdio.h>
#include<stdlib.h>

int min(int a,int b)
{
	if(a>b)
		return b;
	else
		return a;
}

void main()
{
	int ugly[1000];
	int i,n,i2=0,i3=0,i5=0,next_ugly_2=2,next_ugly_3=3,next_ugly_5=5;
	printf("Input n");
	scanf("%d",&n);
	ugly[0]=1;
	for(i=1;i<n;i++)
	{
		ugly[i]=min(next_ugly_2,min(next_ugly_3,next_ugly_5));
		if(ugly[i]==next_ugly_2)
			next_ugly_2=ugly[++i2]*2;
		if(ugly[i]==next_ugly_3)
			next_ugly_3=ugly[++i3]*3;
		if(ugly[i]==next_ugly_5)
			next_ugly_5=ugly[++i5]*5;
	}
	printf("%dth ugly number is:%d",n,ugly[n-1]);
}