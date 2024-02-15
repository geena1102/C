#include<stdio.h>
int readArray(int a[])
{
	int n,i;
	printf("Enter value for n:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	return n;
}
void Insort(int a[],int n)
{
	int i,e,j;
	for(i=1;i<n;i++)
	{
		e=a[i];
		j=i-1;
		while(j>=0&&a[j]>e)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=e;
	}

}
int binarySearch(int a[],int n,int data)
{
	int m,l,r;
	l=0;
	r=n-1;
	while(l<=r)
	{
		m=(l+r)/2;
		if(a[m]==data)
			return m;
		else if(a[m]<data)
		
			l=m+1;
		else
			r=m-1;
	}
return -1;	
}
void printArray(int a[],int n)
{
	int i;
	printf("Elements are:");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
int main()
{
	int a[10],n,num,result;
	n=readArray(a);
	printArray(a,n);
	Insort(a,n);
	printArray(a,n);
	printf("enter ele to be searched:");
	scanf("%d",&num);
	result=binarySearch(a,n,num);
	if(result==-1)
	{
		printf("Ele mot found");
		
	}
	else
	{
		printf("Ele fount ");
	}

	return 0;	
}
