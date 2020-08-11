/*
 *
 *   用數學學程式
 *   十分逼近法: 計算開根號及log值
 *   Author: 台灣程式教育協進會  www.beyond-coding.org.tw
 *   Date: Feb 12, 2020
*/



#include<stdio.h>
#include<math.h> //for pow(a,b)
double mysqrt(double x,int depth);
double square_root(double x);
//#define log(x) square_root(x)
double Log(double x,double base);

int main()
{

  printf("square_root(100)=%f\n",square_root(100));
  printf("square_root(2)=%f\n",square_root(2));
  printf("square_root(3)=%f\n",square_root(3));
  printf("square_root(5)=%f\n",square_root(5));

  //recursion version
  printf("sqrt(2)=%f\n",mysqrt(2,0));
//-----------------------
    //log2(x)
   printf("Log2(32)=%f\n",Log(32,2));

   printf("Log10(100)=%f\n",Log(100,10));
   printf("Log10(2)=%f\n",Log(2,10));
   printf("Log10(1)=%f\n",Log(1,10));
   printf("Log10(-2)=%f\n",Log(-2,10));
   printf("Log10(0)=%f\n",Log(0,10));


  return 0;


}
//十分逼近法

double square_root(double x)
{
  double l=0;
  double step=1.0;
  int j;//control the precision
  for (j=0;j<8;j++) {

    while (l*l<x) {
        l+=step;
    }
    l-=step;
    step/=10;
 }
    return l;
}

//recursive version
double mysqrt(double x,int depth)
{
  double l=0;
  double step=1.0/pow(10,depth);
   while (l*l<x) {
        l+=step;
    }
   l-=step;
 if (depth==8)
       return l;
  else {
    return mysqrt(x,++depth);
 }

}


double Log(double b,double a)
{
  double l=0;
  double step=1.0;
  int j;//control the precision

  if (b==0) return -INFINITY;
  if (b<0 || a<=0 || a==1) return -NAN;  //NAN: not a number

  if (b==1) return 0; //log1=0

  for (j=0;j<8;j++) {

    while (pow(a,l)<b) {
        l+=step;
    }
    l-=step;
    step/=10;

 }

    return l;
}

