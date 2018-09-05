#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct treenode
{
	int key;
	struct treenode *leftchild;
	struct treenode *rightchild;
	struct treenode *parent;
} NODE, *NODEPTR;



NODEPTR search(NODEPTR x,int k)
{
	if(x==NULL)
		return NULL;
	else if ( x->key == k)
		return x;
	else if ( x->key > k)
		return search(x->leftchild,k);
	else
		return search(x->rightchild,k);
}

NODEPTR right_rotate(NODEPTR root, NODEPTR x)
{
	NODEPTR y=NULL;
	y=x->leftchild;
	x->leftchild=y->rightchild;
	if(y->rightchild!=NULL)
		y->rightchild->parent=x;
	y->parent=x->parent;
	if(x->parent==NULL)
		root=y;
	else if(x->parent->leftchild==x)
		x->parent->leftchild=y;
	else
		x->parent->rightchild=y;
	y->rightchild=x;
	x->parent=y;
	return root;
	
}


NODEPTR left_rotate(NODEPTR root, NODEPTR x)
{
	NODEPTR y=NULL;
	y=x->rightchild;
	x->rightchild=y->leftchild;
	if(y->leftchild!=NULL)
		y->leftchild->parent=x;
	y->parent=x->parent;
	if(x->parent==NULL)
	{
		root=y;
	}
	else if(x==(x->parent->leftchild))
	{
		x->parent->leftchild=y;
	}
	else
		x->parent->rightchild=y;
	y->leftchild=x;
	x->parent=y;	
	return root;
}

NODEPTR insert(NODEPTR x)
{
	int input;
	printf("Input Number:");
	scanf("%d",&input);
	if (x==NULL)
	{
		x=(NODE*)malloc(sizeof(NODE));
		x->key = input;
		x->parent = NULL; 
		x->leftchild=NULL;
		x->rightchild==NULL;
		return x;
	}
	else 
	{
		NODEPTR temp=x;
		while(temp!=NULL)
		{
			if( temp->key > input ) //input < temp->key
			{
				if(temp->leftchild == NULL)
				{
					temp->leftchild=(NODE*)malloc(sizeof(NODE));
					(temp->leftchild)->key=input;
					(temp->leftchild)->parent = temp; 
					(temp->leftchild)->leftchild=NULL;
					(temp->leftchild)->rightchild==NULL;
					return x;
				}
				else
					temp=temp->leftchild;
			}
			else if( temp->key < input ) //input > x->key
			{
				if(temp->rightchild == NULL)
				{
					temp->rightchild=(NODE*)malloc(sizeof(NODE));
					(temp->rightchild)->key=input;
					(temp->rightchild)->parent = x; 
					(temp->rightchild)->leftchild=NULL;
					(temp->rightchild)->rightchild==NULL;
					return x;
				}
				else
					temp=temp->rightchild;
			}
		}
		
	}
	
}

void inorder(NODEPTR x)
{
	if(x!=NULL)
	{
		inorder(x->leftchild);
		printf("%d ",x->key);
		inorder(x->rightchild);
	}
}
	
void preorder(NODEPTR x)
{
	if(x!=NULL)
	{
		printf("%d ",x->key);
		preorder(x->leftchild);
		preorder(x->rightchild);
	}
}

NODEPTR delete(NODEPTR root, int key)
{
	NODEPTR N;
	N=search(root,key);
	NODEPTR M=N->parent;
	while(root!=NULL)
	{
		if(N->left==NULL && N->right==NULL)
		{
			if(N->parent==NULL) 
				return NULL;
			NODEPTR temp=N->parent;
			if(temp->left==N)
				temp->left=NULL;
			else
				temp->right=NULL;
			N->parent=NULL;
			break;
		}
		else if(N->left==NULL)
		{
			NODEPTR temp=N->right;
			N->right==NULL;
			temp->parent=N->parent;
			if(N->parent!=NULL)
			{
				if(temp->parent->left==N)
					temp->parent->left=temp;
				else
					temp->parent->right=temp;
			}
			else
				root=temp;
			N->parent=NULL;
			break;
		}
		else if(N->right==NULL)
		{
			NODEPTR temp=N->left;
			N->left=NULL;
			temp->parent=N->parent;
			if(N->parent!=NULL)
			{
				if(temp->parent->left==N)
					temp->parent->left=temp;
				else
					temp->parent->right=temp;
			}
			else
				root=temp;
			N->parent=NULL;
			break;
		}
		else
		{
			NODEPTR temp=successor(N);
			N->value=temp->value;
			N=temp;	
		}	
	}
	if(M!=NULL)
	{
		root=lift_insert(root,M);
	}
	return root;
	
}

void main()
{
	int n,i,s;
	char input[100];
	NODEPTR root=NULL,node=NULL;
	printf("Enter the number of keys:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		root=insert(root);
	}
	preorder(root);
	printf("\nEnter value of key to be left rotated:\n");
	scanf("%d",&s);
	node=search(root,s);
	if(node->rightchild==NULL)
		printf("Cannot Left Rotate");
	else
		root=left_rotate(root, node);
	preorder(root);
	printf("\nEnter value of key to be right rotated:\n");
	scanf("%d",&s);
	node=search(root,s);
	if(node->leftchild==NULL)
		printf("Cannot Right Rotate");
	else
		root=right_rotate(root, node);
	preorder(root);
	printf("\n\n");
}



























	
