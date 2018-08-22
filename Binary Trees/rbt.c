#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct treenode
{
	int key;
	char color;//'b' black,'r' red
	struct treenode *leftchild;
	struct treenode *rightchild;
	struct treenode *parent;
} NODE, *NODEPTR;

int height_tree(NODEPTR x,NODEPTR NIL)
{
	if(x==NIL)
		return 0;
	else
	{
		int height_left=height_tree(x->leftchild,NIL);	
		int height_right=height_tree(x->rightchild,NIL);
		if(height_left>height_right)
			return height_left+1;
		else
			return height_right+1;
	}
}


void preorder(NODEPTR x,NODEPTR NIL)
{
	if(x!=NIL)
	{
		printf("%d--%c \n",x->key,x->color);
		preorder(x->leftchild,NIL);
		preorder(x->rightchild,NIL);
	}
}

NODEPTR search(NODEPTR x,int k,NODEPTR NIL)
{
	if(x==NIL)
		return NIL;
	else if ( x->key == k)
		return x;
	else if ( x->key > k)
		return search(x->leftchild,k,NIL);
	else
		return search(x->rightchild,k,NIL);
}

NODEPTR right_rotate(NODEPTR root, NODEPTR x,NODEPTR NIL)
{
	NODEPTR y=NIL;
	y=x->leftchild;
	x->leftchild=y->rightchild;
	if(y->rightchild!=NIL)
		y->rightchild->parent=x;
	y->parent=x->parent;
	if(x->parent==NIL)
		root=y;
	else if(x->parent->leftchild==x)
		x->parent->leftchild=y;
	else
		x->parent->rightchild=y;
	y->rightchild=x;
	x->parent=y;
	return root;
	
}


NODEPTR left_rotate(NODEPTR root, NODEPTR x,NODEPTR NIL)
{
	NODEPTR y=NIL;
	y=x->rightchild;
	x->rightchild=y->leftchild;
	if(y->leftchild!=NIL)
		y->leftchild->parent=x;
	y->parent=x->parent;
	if(x->parent==NIL)
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
NODEPTR fix_insert(NODEPTR root,NODEPTR x,NODEPTR NIL)
{
	NODEPTR y=NIL;
	while(x!=root && (x->parent->color=='r'))
	{
		if(x->parent==x->parent->parent->leftchild)
		{
			y=x->parent->parent->rightchild;
			if(y->color=='r')
			{
				x->parent->color='b';
				y->color='b';
				x->parent->parent->color='r';
				x=x->parent->parent;
			}
			else
			{
				if(x->parent->rightchild==x)
				{
					x=x->parent;
					root=left_rotate(root,x,NIL);
				}
				x->parent->color='b';
				x->parent->parent->color='r';
				root=right_rotate(root,x->parent->parent,NIL);
			}
		}
		else
		{
			y=x->parent->parent->leftchild;
			if(y->color=='r')
			{
				x->parent->color='b';
				y->color='b';
				x->parent->parent->color='r';
				x=x->parent->parent;
			}
			else
			{
				if(x->parent->leftchild==x)
				{
					x=x->parent;
					root=right_rotate(root,x,NIL);
				}
				x->parent->color='b';
				x->parent->parent->color='r';
				root=left_rotate(root,x->parent->parent,NIL);
			}
		}
		
		
	}
	root->color='b';
	return root;
}

NODEPTR insert(NODEPTR x,NODEPTR NIL)
{
	int input;
	printf("Input Number:");
	scanf("%d",&input);
	if (x==NIL)
	{
		x=(NODE*)malloc(sizeof(NODE));
		x->key = input;
		x->color='b';
		x->parent = NIL; 
		x->leftchild=NIL;
		x->rightchild=NIL;
		return x;
	}
	else 
	{
		NODEPTR temp=x;
		while(temp!=NIL)
		{
			if( temp->key > input ) //input < temp->key
			{
				if(temp->leftchild == NIL)
				{
					temp->leftchild=(NODE*)malloc(sizeof(NODE));
					(temp->leftchild)->key=input;
					temp->leftchild->color='r';
					(temp->leftchild)->parent = temp; 
					(temp->leftchild)->leftchild=NIL;
					(temp->leftchild)->rightchild=NIL;
					temp=temp->leftchild;
					break;
				}
				else
					temp=temp->leftchild;
			}
			else if( temp->key < input ) //input > x->key
			{
				if(temp->rightchild == NIL)
				{
					temp->rightchild=(NODE*)malloc(sizeof(NODE));
					(temp->rightchild)->key=input;
					temp->rightchild->color='r';
					(temp->rightchild)->parent = temp; 
					(temp->rightchild)->leftchild=NIL;
					(temp->rightchild)->rightchild=NIL;
					temp=temp->rightchild;
					break;
				}
				else
					temp=temp->rightchild;
			}
		}
		x=fix_insert(x,temp,NIL);
		return x;
		
	}
}
int computeBH(NODEPTR cur_node,NODEPTR NIL)
{
	if (cur_node == NIL)
		return 0;
	int rightBH = computeBH(cur_node->rightchild,NIL);
	int leftBH = computeBH(cur_node->leftchild,NIL);
	int add;
	if((cur_node->color == 'b'))
		add=1;
	else
		add=0;
	if (leftBH == -1 || rightBH == -1 || leftBH != rightBH)
        	return -1;
	else
        	return leftBH + add;
}

int findBH(NODEPTR cur_node,NODEPTR NIL)
{
	int black_height;
	black_height=computeBH(cur_node,NIL);
	if(black_height==-1)
		return -1;
	else if(cur_node->color=='r')
		return black_height+1;
	else
		return black_height;
}

void main()
{
	int n,i,s;
	char input[100];
	NODEPTR root=NULL,NIL=NULL,current=NULL;
	NIL=(NODEPTR)malloc(sizeof(NODE));
	NIL->parent=NULL;
	NIL->leftchild=NULL;
	NIL->rightchild=NULL;
	NIL->color='b';
	root=NIL;
	printf("Enter the number of keys:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		root=insert(root,NIL);
		preorder(root,NIL);
		printf("\n");
		printf("Black height of root :%d\n",computeBH(root,NIL));
	}
	printf("\nRED BLACK BINARY TREE:\n");
	preorder(root,NIL);
	printf("\nHeight of Binary Tree:%d\n",height_tree(root,NIL));
	for(i=0;i<n;i++)
	{
	printf("Enter value of key for black height:");
	scanf("%d",&s);
	current=search(root,s,NIL);
	printf("Black height of node :%d\n",findBH(current,NIL));
	}
	printf("\n\n");

}	
