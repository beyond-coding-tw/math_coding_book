/*
 *
 *   用數學學程式
 *
 *   Author: 台灣程式教育協進會  www.beyond-coding.org.tw
 *   Date: Feb 12, 2020
*/

#include <stdio.h>
#include <math.h>  //pow function
float f(float x,float *m,int size);
void find_root(float *m,int n);
void find_root2(float *m,int n);
void  find_root3(float x0,float *m,int n);
float differtinal(float x,float *m,int n); //f'(x)
void show_f(float *m,int size);

int main(void)
{
	//case1: f(x)=2x^2-3x+1
    int i;
	float math[]={2,2,1,-3,0,1};
	float x=1;
	int size=sizeof(math)/sizeof(float);
    printf("Quadratic function: ");
    show_f(math,size);
	float v= f(x,math,size);
	printf("f(%.2f)=%.3f\n",x,v);
    find_root2(math,size);

    x=0.75;
    v= f(x,math,size); //頂點 (-b/2a,-(b^2-4ac/4a)
	printf("the minimum of f(%.2f)=%.3f\n",x,v);


     printf("The derivative f'(x) of a curve at a point => f'(a)\n");
    //  f'(x)=4x-3
     v= differtinal(1,math,size);
     printf("f'(1)=%.2f\n",v);//

     v= differtinal(0.75,math,size);
     printf("f'(3/4)=%.2f\n",v);//

     //堪根定理
     //range [-5,5] to find the root
   printf("\n\nIntermediate value theorem \n");
    v=0;
      for (i=0;i<20;i++){
           if ((f(v,math,size)*f(v+0.3,math,size))<0) {
            printf("there exists a x between %f and %f such that f(x)= 0\n",v,v+0.3);
            }
          v+=0.3;
      }


printf("\n\nNewton's method for solving an equation f(x)=0\n");
    for (i=-1;i<=2;i++){
      printf("%d==>\n",i);
      find_root3(i,math,size);
    }
  printf("==>\n");
    float math2[]={2,1,0,-2};  //sqrt(2)==>f(x)=x^2-2
     find_root3(2,math2,4);
	return 0;

}


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


void find_root(float *m,int n)
{


   float a=m[1],b=m[3],c=m[5];
   float t=sqrt(b*b-4*a*c);

     printf("root=%.2f\n",(-b+t)/(2*a));
     printf("root=%.2f\n",(-b-t)/(2*a));

}


void find_root2(float *m,int n)
{
  float delta=0.001;
  float i;
  float r;

  for (i=-100;i<100;i+=0.1) {
        r=f(i,m,n);
         //printf("i=%f,root=%f\n",i,r);
    if (fabs(r-0)<=delta)
            printf("root=%.2f\n",i);
  }

}

float differtinal(float x,float *m,int n)
{
  float h=0.00001;
  float r;

  r=(f(x+h,m,n)-f(x,m,n))/h;
  return r;

}
//Newton’s method)
//x_(n+1)=x_n-(f(x_n))/(f'(x_n))

void find_root3(float x0,float *m,int n)
{
  float x1=x0-(f(x0,m,n)/differtinal(x0,m,n));
  float epsilon=0.000001;
  int i;
  while(fabs(x1-x0)>epsilon)
  {
		  x0=x1;
  		x1=x0-(f(x0,m,n)/differtinal(x0,m,n));
  		
  }
  printf("f(%.3f)=%.3f\n",x0,f(x0,m,n));
}
