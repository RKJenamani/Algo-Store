//Length of largest subset such that every pair in the subset is such that the larger element of the pair is divisible by smaller element.

#include<stdio.h>
#include<stdlib.h>

void merge(int a[],int lower,int middle,int upper)
{
	int b[100],c[100];
	int i,j,k,h1,h2;
	h1=0;
	for(i=lower;i<=middle;i++)
		b[h1++]=a[i];
	h2=0;
	for(i=middle+1;i<=upper;i++)
		c[h2++]=a[i];
	i=0;
	j=0;
	k=lower;
	while(i<h1 && j<h2)
	{
		if(b[i]>c[j])
			a[k++]=c[j++];
		else
			a[k++]=b[i++];
	}
	while(i<h1) 
		a[k++]=b[i++];
	while(j<h2) 
		a[k++]=c[j++];

}

void merge_sort(int a[],int lower,int upper)
{
	if(lower!=upper)
	{
		int middle=(lower+upper)/2;
		merge_sort(a,lower,middle);
		merge_sort(a,middle+1,upper);
		merge(a,lower,middle,upper);
	}
}
 
 void main()
 {
 	int i,j,n,max,a[100],DP[100];
 	printf("Input number of elements in array:");
 	scanf("%d",&n);
 	printf("Input elements:");
 	for(i=0;i<n;i++)
 		scanf("%d",&a[i]);
 	merge_sort(a,0,n-1);
 	DP[n-1]=1;
 	for(i=n-2;i>=0;i--)
 	{
 		max=0;
 		for(j=i+1;j<n;j++)
 		{
 			if(a[j]%a[i]==0)
 			{
 				if(max<DP[j])
 					max=DP[j];
 			}
 		}
 		DP[i]=max+1;
 	}
 	max=DP[0];
 	for(i=1;i<n;i++)
 		if(DP[i]>max)
 			max=DP[i];
 	printf("Length of largest subset is:%d",max);

 }