#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node tree;
tree *root=NULL;
void insert(int e)
{
	tree *p,*t;
	if(root==NULL)
	{
		root=(tree *)malloc(sizeof(tree));
		root->data=e;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		t=root;
		while(t!=NULL)
		{
			p=t;
			if(t->data>e)
			{
				t=t->left;
			}
			else
			{
				t=t->right;
			}
		}
		if(p->data>e)
		{
			p->left=(tree *)malloc(sizeof(tree));
			p->left->data=e;
			p->left->left=NULL;
			p->left->right=NULL;
		}
		else
		{
			p->right=(tree *)malloc(sizeof(tree));
			p->right->data=e;
			p->right->left=NULL;
			p->right->right=NULL;
		}
	}

}
void inorder(tree *r)
{
	if(r!=NULL)
	{
		inorder(r->left);
		printf("%d\t",r->data);
		inorder(r->right);
	}
}
void preorder(tree *r)
{
	if(r!=NULL)
	{
		printf("%d\t",r->data);
		preorder(r->left);
		preorder(r->right);
	}
}
void postorder(tree *r)
{
	if(r!=NULL)
	{
		postorder(r->left);
		postorder(r->right);
		printf("%d\t",r->data);
	}
}
int main()
{
	insert(100);
	insert(200);
	insert(150);
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	return 0;
}
