//Subset_Sum

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int a[100][100],S[100];
	int n,sum,i,j;
	printf("Input value of n:");
	scanf("%d",&n);
	printf("Input set:");
	for(i=1;i<=n;i++)
		scanf("%d",&S[i]);
	printf("Input Sum:");
	scanf("%d",&sum);

	for(i=0;i<=n;i++)
		a[0][i]=1;
	for(i=1;i<=sum;i++)
		a[i][0]=0;
	
	for(i=1;i<=sum;i++)
	{
		for(j=1;j<=n;j++)
		{
			if((i-S[j])>=0)
				a[i][j%2]=(a[i][(j-1)%2] || a[i-S[j]][(j-1)%2]);
			else
				a[i][j%2]=a[i][(j-1)%2];
		}
	}
	/*for(i=0;i<=sum;i++)
	{
		for(j=0;j<=1;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}*/

	printf("Output:%s\n",((a[sum][n%2])?"true":"false"));
	/*int subset[n+1][sum+1];
  
    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
      subset[i][0] = 1;
  
    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
      subset[0][i] = 0;
  
     // Fill the subset table in botton up manner
     for (int i = 1; i <= n; i++)
     {
       for (int j = 1; j <= sum; j++)
       {
         if(j<S[i-1])
         subset[i][j] = subset[i-1][j];
         if (j >= S[i-1])
           subset[i][j] = (subset[i-1][j] || 
                                 subset[i - 1][j-S[i-1]]);
       }
     }
     for(i=0;i<=n;i++)
	{
		for(j=0;j<=sum;j++)
			printf("%d ",subset[i][j]);
		printf("\n");
	}*/

}
