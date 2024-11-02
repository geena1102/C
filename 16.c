#include<stdio.h>
void main()
{
	int num,c,sum=0,r;
	scanf("%d",&num);
	int temp=num;
	while(num>0)
	{
		r=num%10;
		c=r*r*r;
		sum=sum+c;
		num=num/10;
	}
	if(temp==sum)
	{
		printf("Armstrong");
	}
	else
	{
		printf("not armstrong");
	}
}
