//Subset Sum is divisible by n

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[100],n,m,table[100],temp[100],i,j,flag=0;
	printf("Input n:");
	scanf("%d",&n);
	printf("Input numbers into array:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Input sum:");
	scanf("%d",&m);

	if(n>m)
	{
		printf("Divisible subset is present.");
		return 0;
	}
	for(i=0;i<m;i++)
		table[i]=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			temp[j]=0;
		for(j=0;j<m;j++)
		{
			if (table[j]==1)
			{
				if(table[(j+a[i])%m]==0)
					temp[(j+a[i])%m]=1;
			}
		}
		for(j=0;j<m;j++)
			if(temp[j])
				table[j]=temp[j];
		table[a[i]%m]=1;
		if(table[0]==1)
		{
			printf("Divisible subset is present.");
			return 0;	
		}
	}
	printf("Divisible subset is absent.");
	return 0;
}
