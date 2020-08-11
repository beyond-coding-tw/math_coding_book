
#include <stdio.h>
void dump_2d(int row,int column, int a[row][column] );
void transpose(int row,int column, int a[row][column],int b[column][row]);
void add(int row,int column, int a[row][column],int b[row][column],int c[row][column]);
void rotate(int row,int column, int a[row][column],int b[column][row]);
void lrotate(int row,int column, int a[row][column],int b[column][row]);
void flip(int row,int column, int a[row][column],int b[row][column]);
int main(void)
{
  int n,m;


  #if 1
    n=3;m=2;
    int a[3][2]={{1,1},
                 {3,1},
                 {1,2},
                 };
    int b[2][3];
    int c[2][3];

  #else
  int i,j;
  scanf("%d %d",&n,&m);
  int a[n][m]; // a VLA
 //read input
  for(i=0;i<n;i++)
     for (j=0;j<m;j++)
      scanf("%d",&a[i][j]);
    #endif // 1

    dump_2d(n,m,a);  //dump the input

   printf("After A left rotation:\n");
    lrotate(n,m,a,b);
    dump_2d(m,n,b);

  //  printf("After A left rotation:\n");
    lrotate(m,n,b,a);
  //  dump_2d(n,m,a);

    printf("------------\n");
    flip(n,m,a,b);
    dump_2d(n,m,b);



/*
 dump_2d(3,2,a);
 transpose(3,2,a,b);
 dump_2d(2,3,b);

*/
}
void add(int row,int column, int a[row][column],int b[row][column],int c[row][column])
{
   int i,j;
   for(i=0;i<row;i++){
  	    for (j=0;j<column;j++){
			//printf("%d ",a[i][j]);
			c[i][j]=b[i][j]+a[i][j];
        }
	    //printf("\n");
	}



}
void rotate(int row,int column, int a[row][column],int b[column][row])
{


   for(int i=0; i<column; i++){
    for(int j=0; j<row; j++) {
     b[i][j]= a[row-j-1][i];
    }
   }
}

void lrotate(int row,int column, int a[row][column],int b[column][row])
{


   for(int i=0; i<column; i++){
    for(int j=0; j<row; j++) {
     b[column-i-1][j]= a[j][i];
    }
   }
}


void transpose(int row,int column, int a[row][column],int b[column][row])
{
  	 int i,j;
   for(i=0;i<row;i++){
  	    for (j=0;j<column;j++){
			//printf("%d ",a[i][j]);

			b[j][i]=a[i][j];
        }
	    //printf("\n");
	 }

}

void flip(int row,int column, int a[row][column],int b[row][column])
{


   for(int i=0; i<column; i++){
    for(int j=0; j<row; j++) {

       b[row-j-1][i]= a[j][i];

      //  dump_2d(row,column,b);
    }
   }

}




void dump_2d(int row,int column, int a[row][column] )
{
	 int i,j;
	 printf("%2d %2d\n",row,column);
	 for(i=0;i<row;i++){
		for (j=0;j<column;j++)
			printf("%2d ",a[i][j]);

	    printf("\n");
	 }
}





