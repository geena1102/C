#include<stdio.h>
int partition(int a[],int ll,int ul)
{
	int start,end,pivot,temp;
	pivot=a[ll];
	start=ll;
	end=ul;
	while(start<end)
	{
		while(a[start]<=pivot)
		{
			start++;
		}
		while(a[end]>pivot)
		{
			end--;
		}
		if(start<end)
		{
			temp=a[start];
			a[start]=a[end];
			a[end]=temp;
		}	
		else
		{
			temp=a[ll];
			a[ll]=a[end];
			a[end]=temp;
		}
	}
	return end;
}
void quicksort(int a[],int ll,int ul)
{
	int loc;
	if(ll<ul)
	{
		loc=partition(a,ll,ul);
		quicksort(a,ll,loc-1);
		quicksort(a,loc+1,ul);
	}	
}
int main()
{
	int n,i,ll,ul,a[100];
	printf("Enter limit:");
	scanf("%d",&n);
	printf("Enter elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	ll=0;
	ul=n-1;
	quicksort(a,ll,ul);
	printf("Sorted array is :");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
	
}
