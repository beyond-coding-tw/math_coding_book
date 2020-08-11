#include "stdio.h"
#include "math.h"

#define row1 3
#define col1 4

void dump_2d(int rows,int columns, float a[rows][columns]);
int equal(int rows,int columns, float a[rows][columns],int rows2,int columns2, float b[rows2][columns2]);
void rowswap(int rows,int columns, float a[rows][columns],int swap1,int swap2);
void multiplication(int rows,int columns, float a[rows][columns],int rows2,int columns2, float b[rows2][columns2]);


int main(void)
{
   int i;

    /*
     x1-x2+x3=-2
       2x2-3x3=7
        -12x3=12
    */

     float Mat[row1][col1] = {
     {1, -1, 1, -2},
     {0, 2,  -3, 7},
     {0, 0,  -12, 12}};
    printf("矩陣內容:\n");
    dump_2d(row1,col1,Mat);
	
	int row2,col2;
	printf("請輸入row=?");
	scanf("%d",&row2);
	printf("請輸入column?");
	scanf("%d",&col2);
	float Mat2[row2][col2];
	for(int a=0;a<row2;a++)
	{
		for (int b=0;b<col2;b++)
		{
			printf("請輸入第%d列第%d行的元為？",a+1,b+1);
			scanf("%f",&Mat2[a][b]);
		}
	}
	printf("矩陣內容:\n");
	dump_2d(row2,col2,Mat2);



	if(equal(row1,col1,Mat,row1,col1,Mat2))
	{
		printf("two matrices are the same\n");
	}else
	{
		printf("two matrices are not the same\n");
	}
	
	
	printf("after row swap\n");
	
	rowswap(row1,col1,Mat,1,2);
	dump_2d(row1,col1,Mat);
	
	
	printf("after mutiplication\n");
	
	multiplication(row1,col1,Mat,row2,col2,Mat2);
    return 0;
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
int equal(int rows,int columns, float a[rows][columns],int rows2,int columns2, float b[rows2][columns2])
{
	if(rows!=rows2||columns!=columns2)
		return 0;
	
	for(int row=0;row<rows;row++)
	{
		for(int col=0;col<columns;col++)
		{
			if(a[row][col]!=b[row][col])
				return 0;
		}
	 } 
	return 1;
}
void rowswap(int rows,int columns, float a[rows][columns],int swap1,int swap2)
{
	for(int col=0;col<columns;col++)
	{
		float temp=a[swap1][col];
		a[swap1][col]=a[swap2][col];
		a[swap2][col]=temp;
	}
}
void multiplication(int rows,int columns, float a[rows][columns],int rows2,int columns2, float b[rows2][columns2])
{
	if(columns!=rows2)
	{
		printf("two matrices could not be multiplied");
		return;
	}
	float m[rows][columns2];
	for(int row=0;row<rows;row++)
	{
		for(int col=0;col<columns2;col++)
		{
			float sum=0;
			for(int now=0;now<columns;now++)
			{
				sum+=a[row][now]*b[now][col];
			}
			m[row][col]=sum;
		}
	}
	dump_2d(rows,columns2,m);
}

