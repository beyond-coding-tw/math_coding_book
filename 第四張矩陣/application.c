/*
 *
 *   用數學學程式
 *   高斯消去法(Gauss Elimination): 求解線性方程組
 *   Author: 台灣程式教育協進會  www.beyond-coding.org.tw
 *   Date: Feb 12, 2020
*/


#include "stdio.h"
#include "math.h"

void gauss(int rows,int columns, float a[rows][columns] );
void reverse(int rows,int columns, float a[rows][columns] );
void dump_2d(int rows,int columns, float a[rows][columns]);
void adj(int rows,int columns, float a[rows][columns]);
void reverse2(int rows,int columns, float a[rows][columns]);
void vector(int rows,int columns, float a[rows][columns],float v[columns][1]);
#define row 3
#define col 3
#define det_2(a) a[0][0]*a[1][1]-a[0][1]*a[1][0]
int main(void)
{
   int i;

    /*
     x1-x2+x3=-2
       2x2-3x3=7
        -12x3=12
    */

     float Mat[row][col] = {
     {1, 2, 3},
     {3, 4,  2},
     {3, 1,  4}};
    printf("矩陣內容:\n");
    dump_2d(row,col,Mat);
	printf("反矩陣；\n");
	reverse(row,col,Mat);
	dump_2d(row,col,Mat);
	printf("after double implementation：　\n");
	reverse(row,col,Mat);
	dump_2d(row,col,Mat);
	printf("vector=\n");
	float v[row][1]={{1},{2},{2}};
	dump_2d(row,1,v);
	printf("after matrix\n");
	vector(row,3,Mat,v);
	
	float Mat2[2][2] = {
     {1, 2},
     {3, 4}};
	printf("矩陣為\n");
	dump_2d(2,2,Mat2);
	printf("行列式值為%7.3f\n",det_2(Mat2));
	
	printf("伴隨矩陣為\n");
	reverse2(2,2,Mat2);
	dump_2d(2,2,Mat2);
	
	printf("縮放矩陣為\n");
	float Mat3[2][2] = {
     {5, 0},
     {0, 4}};
	dump_2d(2,2,Mat3);
	printf("原本向量為\n");
	float v2[2][1]={{1},{2}};
	dump_2d(2,1,v2);
	printf("經過縮放矩陣後，向量變為\n");
	vector(2,2,Mat3,v2);
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
void reverse(int rows,int columns, float a[rows][columns] )
{
	if(rows!=columns){
		printf("there is no reverse matrix of this matrix");
		return;
	}
	float r[rows][rows+rows];
	for(int now=0;now<rows;now++)
	{
		for(int now2=0;now2<columns;now2++)
		{
			r[now][now2]=a[now][now2];
		}
		r[now][now+rows]=1;
	}
	float temp;
	for(int i=0;i<rows;i++)
     {
        temp=r[i][i];
        for(int j=0;j<columns*2;j++) 
            r[i][j] /= temp ;
        for(int j=0;j<rows;j++) {
             if (j==i) continue;
             temp=r[j][i];
             for(int k=0;k<columns*2;k++){
                r[j][k] += -1*r[i][k]*temp ; 

             }
         }
     }
	for(int i=0;i<rows;i++)
	
	{
		for(int j=0;j<columns;j++)
		{
			a[i][j]=r[i][j+rows];
		}
	}
	return;
}

void vector(int rows,int columns, float a[rows][columns],float v[columns][1]){
	float v2[columns][1];
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<1;j++)
		{
			float sum=0;
			for(int now=0;now<rows;now++)
			{
				
				sum+=a[i][now]*v[now][j];
			}

			v2[i][j]=sum;
		}
	}
	dump_2d(rows,1,v2);	
	
}
void reverse2(int rows,int columns, float a[rows][columns] )
{
	adj(rows,columns,a);
	float det=det_2(a);
	for(int j=0;j<rows;j++)
	{
		for(int i=0;i<columns;i++)
			a[j][i]=a[j][i]/det;
	}

}
void adj(int rows,int columns, float a[rows][columns] )
{
	float temp=a[0][0];
	a[0][0]=a[1][1];
	a[1][1]=temp;
	a[0][1]=-a[0][1];
	a[1][0]=-a[1][0];

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


