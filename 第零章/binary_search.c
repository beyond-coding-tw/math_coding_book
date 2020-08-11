





#include <stdio.h>


int linear_search(int *ar,int size,int key);
int binary_search(int *ar,int size,int key);

int main()
{
 int j;
 int a[8]={0, 2, 4, 6, 8, 10, 12, 14};

j=binary_search(a,8,-1);
   printf("%d\n",j);

j=binary_search(a,8,0);
   printf("%d\n",j);


j=binary_search(a,8,10);
   printf("%d\n",j);


j=binary_search(a,8,14);
   printf("%d\n",j);


return 0;

}


int linear_search(int *ar,int size,int key)
{
   int i;
   for (i=0;i<size;i++){
    if (ar[i]==key)
      return i;
  }
  if (i==size)
        return -1;


}

int binary_search(int *ar,int size,int key)
 {

   int low,high,mid;
   low=0;
   high=size;

   while (low <=high) {

      mid=(low+high)/2;
      if (ar[mid]==key)
           return mid;
      else if (ar[mid]<key)
          low=mid+1;
      else
          high=mid-1;

   }
           return -1;
}



