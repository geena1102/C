#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define SIZE 100
int isoperator(int ch)
{
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int precedence(char op)
{
	switch(op)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		default:
			return 0;
	}
}
int applayoperator(char op,int operand1,int operand2)
{
	switch(op)
	{
		case '+':
			return operand1+operand2;
		case'-':
			return operand1-operand2;
		case'*':
			return operand1*operand2;
		case'/':
			return operand1/operand2;
	}
}
void infixtopostfix(char infix[],char postfix[])
{
	char opstack[SIZE];
	int i,j;
	int top=-1;
	for(i=0,j=0;infix[i]!='\0';i++)
	{
		char ch=infix[i];
		if(ch==' ')
		{
			continue;
		}
		else if(isdigit(ch))
		{
			postfix[j++]=ch;
		}
		else if(isoperator(ch))
		{
			while(top>=0&&precedence(opstack[top])>=precedence(ch))
			{
				postfix[j++]=opstack[top--];
			}
			opstack[++top]=ch;
		}
		else if(ch=='(')
		{
			opstack[++top]=ch;
		}
		else if(ch==')')
		{
			while(top>=0&&opstack[top]!='(')
			postfix[j++]=opstack[top--];
			top--;		
		}	
	}
	while(top>=0)
	{
		postfix[j++]=opstack[top--];
	}
	postfix[j]='\0';
}
void postfixevaluate(char postfix[])
{
	char stack[SIZE];
	int top=-1;
	int i,num1,num2;
	for(i=0;postfix[i]!='\0';i++)
	{
		if(isdigit(postfix[i]))
		{
			stack[++top]=postfix[i]-'0';
		}
		else if(isoperator(postfix[i]))
		{
			num2=stack[top--];
			num1=stack[top--];
			stack[++top]=applayoperator(postfix[i],num1,num2);
			
		}
	}
	printf("Evaluated as:");
	printf("%d",stack[0]);
}
int main()
{
	char infix[SIZE];
	char postfix[SIZE];
	printf("Enter infix string:");
	scanf("%s",infix);
	infixtopostfix(infix,postfix);
	postfixevaluate(postfix);

	return 0;
}
