#include<stdio.h>
int push(int a[],int top)
{
	if (top+1==10)
	{
		printf("Stack is full\n");
	}
	else
	{
		printf("Enter element to be pushed :");
		scanf("%d",&a[++top]);
	}
	return top;
}
int pop(int a[],int top)
{
	if (top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("popped element is :%d",a[top--]);
	}
	return top;
}
void peek(int a[],int top)
{
	if (top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Top elemet is :%d",a[top]);
	}
	
}
int menu()
{
	int ch;
	printf("\n1.push\n2.pop\n3.peek\n4.exit\nEnter your choice :");
	scanf("%d",&ch);
	return ch;
}
void process()
{
	int ch;
	int a[10],top=-1;
	for(ch=menu();ch!=4;ch=menu())
	{
		switch(ch)
		{
			case 1:
				top=push(a,top);
				break;
			case 2:
				top=pop(a,top);
				break;
			case 3:
				peek(a,top);
				break;
		}
	}
}
int main()
{
	int a[10],top=-1;
	process();
	return 0;
}
