#include <stdio.h>
#include <math.h>  //pow function
float f(float x,float *m,int size);
void find_root(float *m,int n);
void find_root2(float *m,int n);
void  find_root3(float x0,float *m,int n);
float differtinal(float x,float *m,int n); //f'(x)
void show_f(float *m,int size);
void show_f(float *m,int size)
{
    int i;
	printf("f(x)=");
    for (i=0;i<size;i+=2) {

        if (m[i+1]>0 && i>0) //coefficient>0
           printf("+");

        if (m[i]==0) //constant
          printf("%.2f",m[i+1]);
        else
          printf("%.2fx^%.2f",m[i+1],m[i]);
    }
    printf("\n");
}
float f(float x,float *m,int n)
{

    int i;
    float f=0;

    for (i=0;i<n;i+=2) {
        f+=m[i+1]*pow(x,m[i]);
    }

     return f;


}
float differtinal(float x,float *m,int n)
{
  float delta=0.00001;
  float r;
  r=(f(x+delta,m,n)-f(x,m,n))/(delta);
  return r;


}
float localextreme(float *math,int size)
{
	float answer=0;
	for(float a=0;a<=5;a+=0.25)
	{
		if(differtinal(a,math,size)==0)
		{
			answer=a;
		}
	}
	show_f(math,size);
	printf("has local extreme on x=%f",answer);
}
void findroot(float *math,int size)
{
	float left=0;
	float right=10;
	float middle;
	if(f(left,math,size)*f(right,math,size)>0)
	{
			printf("there is no root in this range\n");
			return;
	}
	for(int count=0;count<20;count++)
	{
		middle=(left+right)/2;
		if ((f(left,math,size)*f(middle,math,size))<0)
		{
			right=middle;
		}else {
			left=middle;
		}
	} 
	printf("%f",middle);
}
int main()
{
	float math[]={2,1,0,-29};
	float x=1;
	findroot(math,sizeof(math)/sizeof(float));
	
}
