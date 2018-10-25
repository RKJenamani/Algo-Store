#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct _point
{
	int x,y;
} point;

float min(float a, float b)
{
	if(a<b)
		return a;
	else
		return b;
}

float distance(point i, point j)
{
	//printf("\n (%d,%d) & (%d,%d): %f",i.x,i.y,j.x,j.y,sqrt( (i.x-j.x)*(i.x-j.x)+(i.y-j.y)*(i.y-j.y) ));
	return sqrt( (i.x-j.x)*(i.x-j.x)+(i.y-j.y)*(i.y-j.y) );
}

void mergeX(point a[],int lower,int middle,int upper)
{
	point b[10000],c[10000];
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
		if(b[i].x>c[j].x)
			a[k++]=c[j++];
		else
			a[k++]=b[i++];
	}
	while(i<h1) 
		a[k++]=b[i++];
	while(j<h2) 
		a[k++]=c[j++];

}

void merge_sortX(point a[],int lower,int upper)
{
	if(lower!=upper)
	{
		int middle=(lower+upper)/2;
		merge_sortX(a,lower,middle);
		merge_sortX(a,middle+1,upper);
		mergeX(a,lower,middle,upper);
	}
}

void mergeY(point a[],int lower,int middle,int upper)
{
	point b[10000],c[10000];
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
		if(b[i].y>c[j].y)
			a[k++]=c[j++];
		else
			a[k++]=b[i++];
	}
	while(i<h1) 
		a[k++]=b[i++];
	while(j<h2) 
		a[k++]=c[j++];

}

void merge_sortY(point a[],int lower,int upper)
{
	if(lower!=upper)
	{
		int middle=(lower+upper)/2;
		merge_sortY(a,lower,middle);
		merge_sortY(a,middle+1,upper);
		mergeY(a,lower,middle,upper);
	}
}

float explore_strip(point strip[], int size, float current_minimum)
{
	int i,j;
	float new_minimum=current_minimum;
	for(i=0;i<size;i++)
	{
		for(j=i+1; (j<size) && abs(strip[i].y-strip[j].y)<current_minimum;j++ )
			if(distance(strip[j],strip[i])<new_minimum)
				new_minimum=distance(strip[j],strip[i]);
	}
	return new_minimum;
}
float closest_pair(point arrayX[],point arrayY[], int l, int r)
{
	if((r-l)==1)
	{
		float d1;
		d1=distance(arrayX[l],arrayX[r]);
		return d1;
	}
	else if((r-l)==2)
	{
		float d1,d2,d3;
		d1=distance(arrayX[l],arrayX[l+1]);
		d2=distance(arrayX[l+1],arrayX[l+2]);
		d3=distance(arrayX[l],arrayX[l+2]);
		return min(d1,min(d2,d3));
	}
	else
	{
		int mid=(l+r)/2;
		point arrayY_l[10000],arrayY_r[10000];
		int i,j=0,k=0;
		for(i=0;i<=r-l;i++)
		{
			if(arrayY[i].x<=arrayX[mid].x)
				arrayY_l[j++]=arrayY[i];
			else
				arrayY_r[k++]=arrayY[i];
		}
		float a=closest_pair(arrayX,arrayY_l,l,mid);
		float b=closest_pair(arrayX,arrayY_r,mid+1,r);
		float minimum=min(a,b);
		point strip[10000];
		j=0;
		for(i=0;i<=r-l;i++)
		{
			if(abs(arrayY[i].x-arrayX[mid].x)<minimum)
				strip[j++]=arrayY[i];
		}
		//printf("\n Current minimum:%f ",minimum);
		minimum=explore_strip(strip,j,minimum);
		//printf("  New minimum:%f \n",minimum);
		return minimum;


	}
}

int main()
{
	/*point arrayX[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
	point arrayY[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
	int n = sizeof(arrayX) / sizeof(arrayX[0]); */
	int n,i;
	point arrayX[10000],arrayY[10000];
	printf("Input number of points:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Input Point %d:",i+1);
		scanf("%d",&arrayX[i].x);
		scanf("%d",&arrayX[i].y);
		arrayY[i]=arrayX[i];
	}
	merge_sortX(arrayX,0,n-1);
	merge_sortY(arrayY,0,n-1);
	printf("Minimum Distance:%f",closest_pair(arrayX,arrayY,0,n-1));
	return 0;
}