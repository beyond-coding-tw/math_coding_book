#include <stdio.h>

float Sqrt(float x);
float Sqrt2(float x);
#define f(x) ((x)*(x)-2)
int main(void)
{
   float x=2;
   float y=Sqrt(2);

    printf("%.4f\n",y);

    printf("%.4f\n",Sqrt(7+2*Sqrt(10)));

    y=Sqrt2(2.0);

    printf("%.4f\n",y);


     return 0;
}

//Bisection method
float Sqrt2(float x)
{

  float a=0,b=x;
  float m;

  while((b-a)> 1e-5 ) {

	m= (a + b) / 2;
	if (f(m) * f(a) > 0)
		a = m;
	else
		b = m;
    //printf("%f %f \n",a,b);
  }
   return m;
}





float Sqrt(float x)
{
   float l=0;
   int i;
   float step=1;

   for (i=0;i<6;i++) {
       while (l*l<x) {
        l+=step;
       }
       l=l-step;
       step/=10;
       //printf("%f\n",l);
    }
   //printf("%f\n",l);
   return l;
}

