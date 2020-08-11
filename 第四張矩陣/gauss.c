/*
 *
 *   �μƾǾǵ{��
 *   �������h�k(Gauss Elimination): �D�ѽu�ʤ�{��
 *   Author: �x�W�{���Ш|��i�|  www.beyond-coding.org.tw
 *   Date: Feb 12, 2020
*/


#include "stdio.h"
#include "math.h"

void gauss(int rows,int columns, float a[rows][columns] );

void dump_2d(int rows,int columns, float a[rows][columns]);
#define row 3
#define col 4
int main(void)
{
   int i;

    /*
     x1-x2+x3=-2
       2x2-3x3=7
        -12x3=12
    */

     float Mat[row][col] = {
     {1, 2, 3, 14},
     {3, 4,  2, 17},
     {3, 1,  4, 17}};
    printf("�x�}���e:\n");
    dump_2d(row,col,Mat);
	int row2,col2;

    gauss(row,col,Mat);
    printf("�g�L�������h�k:\n");
    dump_2d(row,col,Mat);

    printf("��{������:\n");
    for(i=0;i<row;i++)
        printf("X%d=%7.3f\n",i+1,Mat[i][col-1]);
	
    return 0;
}

void gauss(int rows,int columns, float a[rows][columns] )
{
     int i, j, k;
     float temp;
     for(i=0;i<row;i++)
     {
        temp=a[i][i];
        for(j=0;j<col;j++) 
            a[i][j] /= temp ;
        for(j=0;j<row;j++) {
             if (j==i) continue;
             temp=a[j][i];
             for(k=0;k<col;k++){
                a[j][k] += -1*a[i][k]*temp ; 

             }
         }
         printf("after row %d eliminating\n",i);
         dump_2d(row,col,a);
     }

}




void dump_2d(int rows,int columns, float a[rows][columns] )
{
	 int i,j;
	 for(i=0;i<rows;i++){
		for (j=0;j<columns;j++)
			printf("%7.3f ",a[i][j]);

	    printf("\n");
	 }

}


