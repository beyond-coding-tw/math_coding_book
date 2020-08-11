#include<stdio.h>
/*
Homework:C language
Date: Nov 9, 2019
Website: www.ittraining.com.tw
*/
#define TEST 0
int main()
{

 int n,m;
  int i,j;
 #if TEST==1
  n=8;
  m=4;

  int w[]={10,31,97,32,79,193,80,76};
 #else

 scanf("%d %d",&n,&m);

 int w[n];
 for (i=0;i<n;i++)
    scanf("%d",&w[i]);

 for (i=0;i<n;i++)
    printf("%d ",w[i]);
   printf("\n");
 #endif
   int k=0;
   int faucet[m];
   int time=0;
   int next=m;
   int finish=0;

   for (j=0;j<m ;j++) {
      faucet[j]=j;
   }

 while (!finish) {

    time++;
    for (j=0;j<m;j++) {
       w[faucet[j]]--;
    }

    for (j=0;j<m;j++) {
     if (w[faucet[j]]==0) {
        printf("[%d] complete ,time=%d\n",faucet[j],time);
        k++;
        if (n-k>=m) {
             faucet[j]=next;
             next=next+1;
             // printf("call next %d \n",next);

        }

     }

}
      if (k==n) finish=1;
  }

  printf("time=%d\n",time);

return 0;
}




