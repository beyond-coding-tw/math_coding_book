#include <stdio.h>
#include <math.h>
int isprime(int x)
{
	for(int a=2;a<=sqrt(x);a++)
	{
		if(x%a==0)
		{
			return 1;//回傳1代表非質數
		}
	}
	return 0;//回傳0代表為質數
}
int main()
{
	int x;
	scanf("%d",&x);
	int ans;
	if(isprime(x)==1)
		printf("x is not prime number");
	else
		printf("x is prime number");
 } 		
