#include<stdio.h>
#include<stdlib.h>

typedef struct _edge
{
	int a,b,weight;
}edge;

typedef struct _node
{
	int value;
	int rank;
	struct _node *parent;
} node;


void merge(edge a[],int lower,int middle,int upper)
{
	edge b[1000],c[1000];
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
		if(b[i].weight>c[j].weight)
			a[k++]=c[j++];
		else
			a[k++]=b[i++];
	}
	while(i<h1) 
		a[k++]=b[i++];
	while(j<h2) 
		a[k++]=c[j++];

}

void merge_sort(edge a[],int lower,int upper)
{
	if(lower!=upper)
	{
		int middle=(lower+upper)/2;
		merge_sort(a,lower,middle);
		merge_sort(a,middle+1,upper);
		merge(a,lower,middle,upper);
	}
}

void makeset(node* roots[],node * address[], int i)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->value=i;
	temp->parent=temp;
	temp->rank=0;
	roots[i]=temp;
	address[i]=temp;
}
node* findset(node* temp)
{
	if(temp->parent!=temp)
		temp->parent=findset(temp->parent);
	return temp->parent;
}
void setunion(node *a, node *b)
{
	a=findset(a);
	b=findset(b);
	if(a->rank<b->rank)
		a->parent=b;
	else if(a->rank>b->rank)
		b->parent=a;
	else
	{
		b->parent=a;
		(a->rank)++;
	}
	
}

void kruskal(edge edgeset[],int n,int e)
{
	node *roots[n+1],*address[n+1];
	node *temp_x;
	node *temp_y;
	int i;
	int ans[1000];
	for(i=0;i<1000;i++)
		ans[i]=0;
	merge_sort(edgeset,0,e-1);
	//for(i=0;i<e;i++)
	//		printf("\n %d--%d",edgeset[i].a,edgeset[i].b);

	for(i=0;i<n;i++)
		makeset(roots,address,i);
	i=0;
	while(i!=e)
	{
		temp_x=findset(address[edgeset[i].a]);
		temp_y=findset(address[edgeset[i].b]);
		//printf(" temp_x: %d, temp_y : %d\n",temp_x->value,temp_y->value);
		if(temp_x!=temp_y)
		{
			//printf("independent: %d",i);
			ans[i]=1;
			setunion(temp_x,temp_y);
		}
		i++;
	}
	for(i=0;i<e;i++)
		if(ans[i]==1)
			printf("\n %d--%d==%d",edgeset[i].a,edgeset[i].b,edgeset[i].weight);
}

int main()
{
	int n,e,i;
	edge edgeset[1000];
	scanf(" %d",&n);
	scanf(" %d",&e);
	for(i=0;i<e;i++)
	{
		printf(" Input Edge: ");
		scanf(" %d",&edgeset[i].a);
		scanf(" %d",&edgeset[i].b);
		scanf(" %d",&edgeset[i].weight);
	}
	kruskal(edgeset,n,e);
	return 0;
}