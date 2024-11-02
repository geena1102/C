#include<stdio.h>
void main()
{
	int a,b,temp;
	printf("Enter a and b");
	scanf("%d%d",&a,&b);
	temp=a;
	a=b;
	b=temp;
	printf("After swapping a=%d and b=%d",a,b);
	
}
