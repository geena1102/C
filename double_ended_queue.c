#include<stdio.h>
int q[5],f=-1,r=-1;
void enqueuerear(int e)
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
void enqueuefront(int e)
{
	int i;
	if(r+1==5)
	{
		printf("Q is full\n");
	}
	else
	{
		if(f==-1)
		{
			f=r=0;
			q[f]=e;
		}
		else
		{
			for(i=r;i>=0;i--)
			{
				q[i+1]=q[i];
			}
			r=r+1;
			q[f]=e;
			
		}
	}
	
}
void dequeufront()
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
void dequeurear()
{
	if(f==-1)
	{
		printf("Q is empty");
	}
	else
	{
		printf("\nDequed item is :%d\n",q[r]);
		if(f==r)
		{
			f=r=-1;
		}
		
		r=r-1;
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
//	enqueuerear(10);
//	enqueuerear(20);
//	enqueuerear(30);
//	enqueuerear(40);
//	disp();
//	dequeurear();
//	dequeurear();
enqueuefront(10);
enqueuefront(20);
enqueuefront(30);
disp();
	return 0;
	
}
