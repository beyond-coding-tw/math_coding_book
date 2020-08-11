#include <stdio.h>
#include <math.h>  //pow function

void bubble_sort(int *a,int n);
void selection_sort(int *a, int n);
void dump(int *a,int n);
void swap(int *a,int *b);
void sorting(int *a,int n);
void radixsort(int *a,int n,int digits);


int main()
{
 int i;
 int data[]={85,118,22,49,25,316};


 //dump(view,5);
 //int data[5]={5,4,3,2,1};

 //printf("==bubble_sort===\n");
 //bubble_sort(data,5);
 dump(data,5);
 //printf("==selection_sort===\n");

 //selection_sort(data,5);
 printf("==sorting index===\n");
 sorting(data,5);
 dump(data,5);

 radixsort(data,6,3);

 // dump(data,5);



 return 0;
}
// @todo (Joseph#1#07/10/19): Bubble Sort

void bubble_sort(int *a,int n)
{


    int i,j;
    int flag;

	for (i = 0 ; i < n ; i++)
    {
        flag=1;
		for (j =n-1; j > i; j--){
			if (a[j-1] < a[j]) {
	        	swap(&a[j-1], &a[j]);
	        	flag=0;
			}
		}
        if (flag) break;
        printf("pass %d: ",i+1);
		dump(a,5);

    }

}
// @todo (Joseph#1#07/10/19): Selection Sort
void selection_sort(int *a, int n)
{
    int i,j;

	for (i = 0 ; i < n - 1 ; i++)
    {
		int min = i;
		for (j = i + 1; j < n; j++)     //走訪未排序的元素
		     if (a[j] > a[min]) min = j;

        swap(&a[min], &a[i]);
        printf("pass %d: ",i+1);
		dump(a,5);
	}
}


void swap(int *a,int *b) //交換兩個變數
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void dump(int *a,int n)
{
  int i;
  for (i=0;i<n;i++)
     printf("%d ",a[i]);

   printf("\n");
}

// @todo (Joseph#1#07/10/19)
void sorting(int *a,int n)
{

 int index[n];
 int i,j;
 //initial index table
  for (i=0;i<n;i++)
      index[i]=i;

  //copy from bubble sort
	for (i = 0 ; i < n ; i++)
    {

		for (j =n-1; j > i; j--){
			if (a[index[j-1]] < a[index[j]]) {
	        	swap(&index[j-1], &index[j]);

			}
		}

    }
   //display sorting result
   for (i=0;i<n;i++)
     printf("%d ",a[index[i]]);

   printf("\n");


}


void radixsort(int *a,int n,int digits)
{
 int t,p=0;
 int idx,i,j;
 int bucket[10][n];
 int c[10]={0};



 for( idx=1;idx<=digits;idx++){
    for(j=0;j<n;j++){
         // extracting the concerned digit
        t = a[j];
        t = t / (pow(10,idx-1));
        t = t%10;
        printf("%d->%d ",a[j],t);
        bucket[t][c[t]]=a[j];
        c[t]++;
    }
    printf("\n");

 //dump bucket and also restore
 p=0;
 for (i=0;i<10;i++){
     printf("[%d] ",i);
     for (j=0;j<c[i];j++){
         //if (bucket[i][j]!=-1)
            a[p++]=bucket[i][j];

         printf("%d ",bucket[i][j]);
        // bucket[i][j]=-1;  //clear bucket
     }
       printf("\n");
      c[i]=0;
   }



   dump(a,n);

 }
}
