/*
 *
 *   �μƾǾǵ{��
 *   Author: �x�W�{���Ш|��i�|  www.beyond-coding.org.tw

    Date: Feb 12, 2020
*/

#include<stdio.h>
#include<math.h> //for pow(a,b)

int sum(int i)
{
	int sum=0;
	for (int a=1;a<=i;a++)
		sum+=a;
	return sum;
}

int main()
{
	int i;
  	scanf("%d",&i);
	printf("%d",sum(i));
}




