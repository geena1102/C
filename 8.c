#include<stdio.h>
void main()
{
	int n,ele,l=0,i;
	printf("Enter no");
	scanf("%d",&n);
	printf("Enter elements");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&ele);
		if(ele>l)
		{
			l=ele;
		}
	}
	printf("Largest ele is %d",l);
	
	
	
}
