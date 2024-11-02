#include<stdio.h>
void main()
{
	int a[6]={10,20,30,40,50,60};
	int ele,loc,i;
	printf("Enter ele");
	scanf("%d",&ele);
	printf("Enter loc");
	scanf("%d",&loc);
	if(loc>=6)
	{
		printf("No such location");
	}
	else
	{
		for(i=5;i>=loc;i--)
		{
			a[i+1]=a[i];
		}
		a[loc]=ele;
	}
	for(i=0;i<7;i++)
	{
		printf("%d\n",a[i]);
	}
}
