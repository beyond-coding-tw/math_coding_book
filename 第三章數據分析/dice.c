#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	int n;
	printf("there are n dices, please input n=");
	scanf("%d",&n);
	int t;
	printf("repeat t times of throwing, please input t= ");
	scanf("%d",&t);
	int left=n;
	int right=n*6;
	int *point = (int *) malloc((right-left+1) * sizeof(int));
	for(int zero=0;zero<right-left+1;zero++)
	{
		point[zero]=0;
	}
	srand(time(0));
	for(int now=0;now<t;now++)
	{
		int sum=0;
		for(int count=0;count<n;count++)
		{
			int now=rand()%6+1;
			sum+=now;
		}
		point[sum-left]++;
	}
	printf("points  || number of times \n");
	for(int temp=0;temp<right-left+1;temp++)
	{
		printf("%-3d     =     %-5d\n",temp+left,point[temp]);
	}
}
