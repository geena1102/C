#include<stdio.h>
int q[5],f=-1,r=-1;
void enqueue(int e)
{
	if(r+1==5)
	{
		printf("Q is full\n");
	}
	else
	{
		if(f==-1)
		{
			f=0;
		}
		r=r+1;
		q[r]=e;
	}
}
void dequeu()
{
	int i;
	if(f==-1)
	{
		printf("Q is empty\n");
	}
	else
	{
		printf("\nDequed item is :%d",q[f]);
		if(f==r)
		{
			f=r=-1;
		}
		else
		{
			for(i=0;i<r;i++)
			{
				q[i]=q[i+1];
			}
			
		}
		r--;
	}
}
void disp()
{
	int i;
	if(f==-1)
	{
		printf("Q is empty\n");
	}
	else
	{
		printf("Elements are :");
		for(i=0;i<=r;i++)
		{
			printf("%d\t",q[i]);
		}
	}
}
int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	disp();
	dequeu();
	dequeu();
	return 0;
	
}
