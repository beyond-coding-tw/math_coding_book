/*
 *
 *   用數學學程式
 *   Author: 台灣程式教育協進會  www.beyond-coding.org.tw

    Date: Feb 12, 2020
*/

#include<stdio.h>
#include<math.h> //for pow(a,b)

void convert(int n,int base); //base=2,8,16
void dump(void *a,int size,int reverse);
int main()
{
  printf("0xFA to binary: ");
  convert(0xFA,2);
  printf("18 to octal: ");
  convert(18,8);
  printf("31 to hex: ");
  convert(31,16);

  return 0;


}

void convert(int n,int base)
{
  int i;
  char m[100];

  for (i=0;n>0;n/=base,i++){
   // printf("%d",n%2);
   if (n%base>=10) //for hex case
      m[i]='A'+(n%base)-10;
   else
      m[i]='0'+n%base;
  }

  dump(m,i,1); //1: dump in reverse order
  printf("\n");
}

void dump(void *a,int size,int reverse)
{
   int i;
   char *p=(char *)a;
   if (reverse==0) {
       for(i=0;i<size;i++)
          printf("%c ",p[i]);
   }else {

       for(i=size-1;i>=0;i--)
           printf("%c ",p[i]);

   }

}





