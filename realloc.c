#include<stdio.h>
#include<stdlib.h>
int main()
{
int *p,n,i,m;
printf("Enter value for n:");
scanf("%d",&n);
p=(int *)malloc(sizeof(int)*n);
printf("Enter elemets:");
for(i=0;i<n;i++)
{
	scanf("%d",(p+i));
}
printf("\nThe elemets:");
for(i=0;i<n;i++)
{
	printf("%d",*(p+i));
}
printf("\nenter new size:");
scanf("%d",&m);
p=(int *)realloc(p,sizeof(int)*m);
if(m>n)
{
	printf("\nEnter elements");
	for(i=n;i<m;i++)
	{
		scanf("%d",(p+i));
	}
}
printf("The total elements are:");
for(i=0;i<m;i++)
{
	printf("%d\t",*(p+i));
}
return 0;
}
