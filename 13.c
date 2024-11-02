#include<stdio.h>
void main()
{
	int n,i,f=1,sum=0;
	printf("Enter n");
	scanf("%d",&n);
	for(i=1;i<=n/2;i++)
	{
		if(n%i==0)
		{
			sum=sum+i;
		}
	}
	if(n==sum)
	printf("perfect");
	else
	printf("not");
}
