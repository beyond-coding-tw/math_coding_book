/***********************************************************************
 *  艾鍗學院
 *  C程式設計
 *  Author: joseph (2020/2/21)
 *  http://www.ittraining.com.tw
 *
 ***********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> //for sqrt
#define X_LIMIT 20
#define Y_LIMIT 20



typedef struct _point * pPoint;
 typedef struct _point {
    float x1;
   // int x2;
   // int x3;
    float y; //target
    /*more*/
 }Point;
 
void dump(pPoint ptr,int size); //2-d
int is_in(int x, int y,pPoint set,int size);
void plot_scatter(pPoint ptr,int size);
void statistic(pPoint ptr,int size);
void sort(pPoint a,int size);

int main(void)
{
  int i;

 

  int n=10;
  Point p[n];

 // Point new_x={1,4};
  srand(time(0));
  //initialize data point
  for (i=0;i<n;i++) {
    p[i].x1=rand()%X_LIMIT; //range 0~X_LIMIT
    p[i].y=rand()%Y_LIMIT; //range 0~Y_LIMIT
//    p[i].y=p[i].x1+2;

  }

	
	
	
	
  dump(p,n);
  statistic(p,n);
  plot_scatter(p,n);




  return 0;
}


void statistic(pPoint ptr,int size)
{
  int i;
  int n=size;
  float sum_x1=0,sum_y=0;
  float avg_x1,avg_y;
  float r_xy;
  float temp=0;
  int max,min;
  float m;

  max=min=ptr[0].x1;

  //average
  for (i=0;i<n;i++){
     sum_x1+=ptr[i].x1;
     sum_y+=ptr[i].y;
     //also find the max, min
     if (ptr[i].x1>max) max=ptr[i].x1;
     if (ptr[i].x1<min) min=ptr[i].x1;

  }
	
   printf("min(x1)=%.2f\n",min);
   printf("max(x1)=%.2f\n",max);

   avg_x1=sum_x1/n;
   avg_y=sum_y/n;
   printf("avg(x1)=%.2f\n",avg_x1);
   printf("avg(y)=%.2f\n",avg_y);
   //std
   sum_x1=sum_y=0;
   for (i=0;i<n;i++){
     sum_x1+=pow(ptr[i].x1-avg_x1,2);
     sum_y+=pow(ptr[i].y-avg_y,2);
     temp+=(ptr[i].x1-avg_x1)*(ptr[i].y-avg_y);
  }

    printf("std(x1)=%.2f\n",sqrt(sum_x1/n));
    printf("std(y)=%.2f\n",sqrt(sum_y/n));

   //corelation
    r_xy=temp/(sqrt(sum_x1)*sqrt(sum_y));
    printf("r_xy=%.2f\n",r_xy);

    //regression m
	
    sort(ptr,n);
    printf("median of x1=%.2f\n",ptr[n/2].x1);


    //regression line
    //y-E(y)y=m(x-E(X))
    //y=mx+(E(y)-mE(X))
    
    printf("regression line\n");
    m=r_xy*sqrt(sum_y/n)/sqrt(sum_x1/n);
	printf("y=%.2fx+(%.2f)\n",m,avg_y-m*avg_x1);
	//after standardization
	Point s[n];
	for (i=0;i<n;i++){
		s[i].x1=(ptr[i].x1-avg_x1)/sqrt(sum_x1/n);
		s[i].y=(ptr[i].y-avg_y)/sqrt(sum_y/n);
	}
	printf("after standardization\n");
	dump(s,n);
}





void plot_scatter(pPoint ptr,int size)
{
  int i,j;
    printf("%2s","");


  printf("\n");
  for (j=Y_LIMIT-1;j>=0;j--) {
       printf("%2d",j) ;
      for (i=0;i<X_LIMIT;i++) {
          if (is_in(i,j,ptr,size))
                printf("|%2s","*") ;
           else
                printf("|%2s","") ;
     }
     printf("|\n");
  }
   printf("%3s"," ") ;
   for (i=0;i<X_LIMIT;i++)
     printf("%2d|",i) ;

   printf("\n");
}

int is_in(int x, int y,pPoint set,int size)
{
     int i;
     for (i=0;i<size;i++) {
       if (x==set[i].x1 && y==set[i].y)
            return 1;
    }

     return 0;

}
void dump(pPoint ptr,int size)
{
  int i;

  printf("x1    y\n") ;
  //printf("x1   x2  x3    y\n") ;
  printf("-----------------\n");
  for (i=0;i<size;i++) {
   //  printf("%3d,%3d,%3d,%3d\n", ptr[i].x1,ptr[i].x2,ptr[i].x3, ptr[i].y) ;  //*(ptr+i)==ptr[i]
    printf("%.2f,%.2f\n", ptr[i].x1,ptr[i].y) ;  //*(ptr+i)==ptr[i]


  }
}


void sort(pPoint a,int size)
{
   int i,j;
   for(i=0;i<size;i++) {
    for(j=0;j<size-1;j++) {
       if (a[j].x1>a[j+1].x1) {
        Point t=a[j];
        a[j]=a[j+1];
        a[j+1]=t;
       }
    }
   }
}

