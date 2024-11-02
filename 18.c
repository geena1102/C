#include<stdio.h>
void main()
{
	int num,c;
	scanf("%d",&num);
	while(num>0)
	{
		c++;
		num=num/10;
	}
printf("count %d",c);
}
