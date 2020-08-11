#include<stdio.h>
#include<math.h>

int main()
{
	float n,p;
	
	printf("please input n and p of bernoulli test\n");
	scanf("%f%f",&n,&p);
	if(p>1){
		printf("p should be bigger than 1");
		return 0;
	}
	printf("expected value= %f \n",n*p);
	printf("variance value= %f \n",n*p*(1-p));
	printf("standard deviation= %f \n",sqrt(n*p*(1-p)));
	
	printf("#success || probability\n");
	for(int k=0;k<=n;k++)
	{
		float pro=1;
		float top=1;
		float bottom=1;
		for (int now=1;now<=k;now++){
			top=top*(n+1-now);
			bottom=bottom*now;
			pro=pro*p;
		}
		for(int now=1;now<=n-k;now++)
		{
			pro=pro*(1-p);
		}
		pro=pro*top/bottom;
		printf("   %d        %f\n",k,pro);
	}
	
}
