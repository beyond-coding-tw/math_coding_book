/*
 *
 *   用數學學程式-Study math & programming
 *   Description: how to generate a random variable x based on a specific distribution
 *   Author: 台灣程式教育協進會  www.beyond-coding.org.tw
 *   Date: Feb 25, 2020
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> //for sqrt

#define X_LIMIT 20

void dump(double *ar,int size);
double mean(double* values, int n);
double var(double* values, int n);
double stddev(double* values, int n);
//probability distribution
double rnd();
double rnd_uniformc(double a, double b ); //continuous uniform dist.
int rnd_uniformd(int a, int b); //discrete uniform dist.
double* rand_normal(double mean, double stdDev,int size); //generate n data follow  N(mean,std)
double* rand_exp(double lambda,int size);  // generate n data follow Exp(lambda)
double* rnd_binomial(int n, double p,int size);   //binomial distribution X~Binomial(n,p)
void plotHistogram(double* values, int n,double low,double high,double delta,char *title);


int main(void)
{

    int n;
    srand(time(NULL));
    n=100000;
	
    //generate data from binomial distribution
    double *data3=rnd_binomial(100,0.5,n);
    //dump(data3,n);
    plotHistogram(data3,n,30,70,1,"X~Binomial(n=100,p=0.5)");
    printf("E(X)=%5.2f\n",mean(data3,n));  //E(X)=np
    printf("VAR(X)=%5.2f\n",var(data3,n));  //VAR(x)=np(1-p)
    free(data3);

    //generate data from normal distribution
    //if n is large, then binomial distribution is similar to normal distribution
    double *data1=rand_normal(0,2,n);
    plotHistogram(data1,n,-8,8,0.5,"X~Normal(mean=0,std=2)");
    printf("E(X)=%5.2f\n",mean(data1,n));   //E(X)=mean
    printf("VAR(X)=%5.2f\n",var(data1,n));  //VAR(x)=std^2
    double sigma=stddev(data1,n)*2;   //95.4% observations
    double mean1=mean(data1,n);
    int count=0;
    for (int i=0;i<n;i++){
        if ((data1[i]<=mean1-sigma) || (data1[i]>=mean1+sigma))
            count++;
    }

    printf("%.2f%% of the population is contained\n",100*(1.0-count/(double)n));

    free(data1);
    //generate data from Exp distribution
    double *data2=rand_exp(0.5,n);
    plotHistogram(data2,n,0,5,0.2,"X~Exp(lambda=0.5)");
    printf("E(X)=%5.2f\n",mean(data2,n));      //E(X)=1/lamda=1/0.5=2
        printf("VAR(X)=%5.2f\n",var(data2,n)); //VAR(x)=1/(lamda^2)=1/((0.5)^2)=4
    free(data2);







  return 0;
}

//statistics function
double mean(double* values, int n)
{
    int i;
    double s = 0;

    for ( i = 0; i < n; i++ )
        s += values[i];
    return s / n;
}


double var(double* values, int n)
{
    int i;
    double average = mean(values,n);
    double s = 0;

    for ( i = 0; i < n; i++ )
        s += pow((values[i] - average),2);
    return s / n;
}


double stddev(double* values, int n)
{
    return sqrt(var(values,n));
}


// generate a uniform random variable 0~0.99999999999999999
double rnd()
{    //return (0,1)
	  return (double)rand()/(RAND_MAX);

}


// genrate a continuous uniform random variable (a,b)

double rnd_uniformc(double a, double b )
{   // b-a+1==>[a,a+1,a+2,....b
     //1~5==>1,2,3,4,5
	  return (a+(b-a+1)*rnd());

}


int rnd_uniformd(int a, int b)
{
      //example: 0~5
      //6*0.95=5.xxx=5
	  return a+(b-a+1)*rnd();

}
//https://en.wikipedia.org/wiki/Binomial_distribution


double* rnd_binomial(int n, double p,int size)
{
  int i=0,k=0;
  double u,q,f;

  double* values = (double*)malloc(size*sizeof(double));
   for ( i = 0; i < size; i++ ){
      k=0;
      f=q=pow(1.0-p,n);
      u=rnd();
      while (f<=u) {
        q*=p*(n-k)/((k+1.0)*(1.0-p));
        f+=q;
        k++;
      }
     values[i]=k;
     //printf("j=%d\n",j);

   }

  return values;

}



/*
 X~Exp(λ);
 f(x)=λexp(-λx) ,x>0
 F(x)=1-exp(-λx) for x>0

 ## how to generate data from exponential distribution ?
  1.) set a random number r (uniformly distributed between 0 and 1)
  2.) r=F(t)=1-exp(-λt) is equal (also between 0 and 1)
  3.) exp(-λt)=1-r
      -λt=ln(1-r)
       t=-ln(1-r)/λ

  http://web.mit.edu/urban_or_book/www/book/chapter7/7.1.3.html

*/

double* rand_exp(double lambda,int size)
{
    double u;
    int i;
    int n=size;
    double* values = (double*)malloc(n*sizeof(double));

    for ( i = 0; i < n; i ++ ){
        u = rnd();  // 0<u<1
        values[i]=-log(1-u)/lambda;
    }

    return values;
}



/*
 * Normal random numbers generator - Marsaglia algorithm.
   https://en.wikipedia.org/wiki/Marsaglia_polar_method
 */
double* rand_normal(double mean, double stdDev,int size)
{
    int i;
    int n=size;
    int m = n + (n % 2);
    double* values = (double*)malloc(m*sizeof(double));
    if ( values )
    {
        for ( i = 0; i < m; i += 2 )
        {
            double x,y,rsq,f;
            do {
                x = 2.0 * rnd() - 1.0;   // -1<x<1
                y = 2.0 * rnd() - 1.0;  // -1<y<1
                rsq = x * x + y * y;
            }while( rsq >= 1.0 || rsq == 0.0 );

            f = sqrt( -2.0 * log(rsq) / rsq );
            values[i]   = mean+ x * f * stdDev;
            values[i+1] = mean+ y * f * stdDev;
        }
    }
    return values;
}
void plotHistogram(double* values, int n,double low,double high,double delta,char *title)
{
        const int width = 50;
        int max = 0;

        int i,j,k;
        int nbins = (int)((high - low) / delta);
        int bins[nbins];

        if (title) printf("%s\n",title);

    //init bins[] to 0
        for ( j = 0; j < nbins; j++ )
             bins[j]=0;


        for ( i = 0; i < n; i++ )
        {
            int j = (int)( (values[i] - low) / delta );
            if ( 0 <= j  &&  j < nbins )
                bins[j]++;


        }

        for ( j = 0; j < nbins; j++ ){
            // printf("%d=%d\n",j,bins[j]);
            if ( max < bins[j] )
                max = bins[j];
        }


        for ( j = 0; j < nbins; j++ )
        {
            printf("(%6.2f, %6.2f) |", low + j * delta, low + (j + 1) * delta );
            k = (int)(width*bins[j] /(max*1.0) );//ratio
            while(k-- > 0) printf("=");
            printf("%d/%d  (%-.1f%%)",bins[j],n,bins[j] * 100.0 / (double)n);
            printf("\n");
        }

}

void dump(double *ar,int size)
{
   int i=0;
   for (;i<size;i++)
    printf("%5.2f  ",ar[i]);
   printf("\n");
}

