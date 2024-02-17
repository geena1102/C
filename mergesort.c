#include<stdio.h>
void merge(int a[],int p,int m,int q)
{
	int b[100],i,j,k;
	k=0;
	for(i=p,j=m+1;i<=m&&j<=q;)
	{
		if(a[i]<a[j])
		{
			b[k]=a[i];
			i++;
		}
		else
		{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	while(i<=m)
	{
		b[k]=a[i];
		k++;
		i++;
	}
	while(j<=q)
	{
		b[k]=a[j];
		k++;
		j++;
	}
	for(i=p,k=0;i<=q;i++,k++)
	{
		a[i]=b[k];
	}
}
void mergesort(int a[],int p,int q)
{
	int m;
	if(p<q)
	{
		m=(p+q)/2;
		mergesort(a,p,m);
		mergesort(a,m+1,q);
		merge(a,p,m,q);
	}
}
int main()
{
	int n,i,a[100];
	printf("enter limit :");
	scanf("%d",&n);
	printf("Enter elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	mergesort(a,0,n-1);
	printf("sorted array is :");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}
