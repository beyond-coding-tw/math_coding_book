#include <stdio.h>
#include <math.h>
int isprime(int x)
{
	for(int a=2;a<=sqrt(x);a++)
	{
		if(x%a==0)
		{
			return 1;//�^��1�N��D���
		}
	}
	return 0;//�^��0�N�����
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
