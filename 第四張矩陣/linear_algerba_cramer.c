/*
 *
 *   用數學學程式
 *   矩陣與線性代數-- Cramer's rule 求解線性方程組
 *   Author: 台灣程式教育協進會  www.beyond-coding.org.tw
 *   Date: Feb 19, 2020
*/


#include <stdio.h>

#define det_1(a) a[0][0]
#define det_2(a) a[0][0]*a[1][1]-a[0][1]*a[1][0]
#define det_3(a) a[0][0]*a[1][1]*a[2][2]+a[0][1]*a[1][2]*a[2][0]+a[0][2]*a[1][0]*a[2][1]- \
                 a[0][2]*a[1][1]*a[2][0]-a[0][1]*a[1][0]*a[2][2]-a[0][0]*a[2][1]*a[1][2]

void dump_2d(int row,int column, int a[row][column] );
void change_col(int row,int column, int m[row][column],int k, int j);
void Cramer(int row,int column, int a[row][column] );


 int main()
{

   printf("求行列式值:\n");
   int f1[2][2]={{1,1},
                 {2,-1}};

  dump_2d(2,2,f1);
  printf("|f1|=%d\n\n",det_2(f1));
  printf("|f1|=%d\n\n",f1[0][0]*f1[1][1]-f1[0][1]*f1[1][0]);


   int f2[3][3]={{2,1,-1},
                {1,-3,1},
                {1,3,-3}};
  dump_2d(3,3,f2);
  printf("|f2|=%d\n\n",det_3(f2));


  printf("求方程式解:\n");
  /*
   4x-5y+5=0
   3x-4y+6=0

   ==> x=10,y=9
  */

  int m[2][3]={{4,-5,-5},
                {3,-4,-6}};


     dump_2d(2,3,m);
     Cramer(2,3,m);

    printf("\n");
   /*
    x1-x2+x3=-2
       2x2-3x3=7
       -12x3=12
   */

   int v[3][4]={{1,-1, 1, -2},
                {0, 2, -3, 7},
                {0, 0,-12,12}};
     dump_2d(3,4,v);
     Cramer(3,4,v);
     printf("\n");

   /*
    -2x+8y=-6
     x-4y=3
   */

    int k[2][3]={{-2,8,-6},
                {1,-4,3}};


     dump_2d(2,3,k);
     Cramer(2,3,k);


   return 0;
}


/*Cramer's rule */
void Cramer(int row,int column, int a[row][column] )
{
	 int i,j;
	 int b[row][column];
	 int det,det_x;
	 float ans;
	 int flag=0;
	 //copy from a to b
	 for(i=0;i<row;i++){
		for (j=0;j<column;j++)
			b[i][j]=a[i][j];

	 }

	 if (row==1){
          det=det_1(b);
	 } else if (row==2){
          det=det_2(b);
	 } else if (row==3){
	      det=det_3(b);
	 }

   	 for(i=0;i<row;i++){
        change_col(row,column,b,i,column-1); //change column
        if (row==1){
          det_x=det_1(b);
        } else if (row==2){
          det_x=det_2(b);
        } else if (row==3){
	      det_x=det_3(b);
        }
        //printf("det_x=%d\n",det_x);
        if (det==0 && det_x!=0){
                flag=1; //one of the x is non-zero
                break;
        }

        if (det!=0)
             printf("x%d=%.2f\n",i,det_x/(float)det);

        change_col(row,column,b,column-1,i); //save back

   	 }
       if (det==0) {
         if (flag==1)
              printf("方程式無解\n");
        else
            printf("方程式無限多解或無解\n");
       }
}


void dump_2d(int row,int column, int a[row][column] )
{
	 int i,j;
	 for(i=0;i<row;i++){
		for (j=0;j<column;j++)
			printf("%2d ",a[i][j]);

	    printf("\n");
	 }
	  printf("\n");
}

void change_col(int row,int column, int m[row][column],int k, int j)
{
    int i;
    int temp;
    for (i=0;i<row;i++){

          temp=m[i][k];
           m[i][k]=m[i][j];
           m[i][j]=temp;
    }
}



