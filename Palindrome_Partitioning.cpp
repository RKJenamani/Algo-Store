#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void PalindromeMatrix(char P[][],char a[], int i, int j)
{
	n=strlen(a);
	for(i=0;i<n;i++)
		P[i][i]=1;
	for(l=2;l<=n;l++)
		for(i=0;i<n-l+1;i++)
		{
			j=i+l-1;
			if(l==2)
				P[i][j]=(a[i]==a[j])?1:0;
			else
				P[i][j]=((a[i]==a[j]) && P[i+1][j-1])?1:0;
		}
}

int mincuts(char input[])
{
	int P[100][100],C[100][100];
	


}

int main()
{
	printf("Input string");
	scanf(" %s",input);
	printf("Number of minimum cuts is:",mincuts(input));
	return 0;
}