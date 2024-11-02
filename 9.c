#include<stdio.h>
void main()
{
	int y;
	printf("Enter year");
	scanf("%d",&y);
	if((y%400==0)||(y%4==0&&y%100!=0))
	{
		printf("Leap year");
	}
	else
	{
		printf("not lep year");
	}
}
