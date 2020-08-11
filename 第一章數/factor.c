#include <stdio.h>

int main(void)
{

int n=1024;
int j;
int i;
 for (i=1,j=1;i<=n/2;i++){
    if (n%i==0){
      printf("%d\t",i);
      j++;
      if (j%8==0) printf("\n");
    }
  }
   printf("%d\n",n);
  return 0;
}

