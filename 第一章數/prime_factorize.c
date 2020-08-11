/*
 *
 *   用數學學程式
       質因數分解
 *   Author: 台灣程式教育協進會  www.beyond-coding.org.tw

    Date: Feb 12, 2020
*/



#include <stdio.h>
int is_prime(int n);

int main(void)
{
  char buf[100]={0};
  int n=24;

  int j=0;
  int x=n;
  int i;

 for (i=2;i<=n;i++){
    if (x%i==0 && is_prime(i)){
        while(x%i==0) {
            //printf("%dx",i);
            j+=sprintf(buf+j,"%dx",i);
            x=x/i;
        }

    }
  }
   printf("\n");
   buf[strlen(buf)-1]='\0';
   printf("%s\n",buf);
  return 0;

}

int is_prime(int n)
{


int j;

  for (j=2;j<n;j++)
     if (n%j==0){
          return 0;
       }

   return 1;

}


