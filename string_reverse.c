#include<stdio.h>
#include<string.h>
#define SIZE 20
int top=-1;
char stack[SIZE];
void push(char ch)
{
	if(top+1==SIZE)
	{
		printf("Stack is full");
	}
	else
	{
		stack[++top]=ch;
	}
}
char pop()
{
	if(top==-1)
	{
		printf("Stack empty");
	}
	else
	{
		return stack[top--];
	}
}
int main()
{
	char str[20];
	int i;
	printf("enter string");
	scanf("%s",str);
	for(i=0;i<strlen(str);i++)
	{
		push(str[i]);
	}
		for(i=0;i<strlen(str);i++)
	{
		str[i]=pop();
	}
	printf("Reversed string is :");
	printf("%s",str);
	return 0;
	
}
