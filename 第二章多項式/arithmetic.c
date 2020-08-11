#include <stdio.h>
#include <math.h>  //pow function
float f(float x,float *m,int size);
void find_root(float *m,int n);
void find_root2(float *m,int n);
void  find_root3(float x0,float *m,int n);
float differtinal(float x,float *m,int n); //f'(x)
void show_f(float *m,int size);
void show_f(float *m,int size)
{
    int i;
	printf("f(x)=");
    for (i=0;i<size;i+=2) {

        if (m[i+1]>0 && i>0) //coefficient>0
           printf("+");

        if (m[i]==0) //constant
          printf("%.2f",m[i+1]);
        else
          printf("%.2fx^%.2f",m[i+1],m[i]);
    }
    printf("\n");
}
float f(float x,float *m,int n)
{

    int i;
    float f=0;

    for (i=0;i<n;i+=2) {
        f+=m[i+1]*pow(x,m[i]);
    }

     return f;


}
void add(float *m1,float *m2,int size1,int size2)
{
	int index1=0,index2=0;
	float temp[size1+size2];
	for (int init=0;init<size1+size2;init++)
	{
		temp[init]=0;
	}
	int now=0;
	while(index1<size1&&index2<size2)
	{
		
		if(m1[index1]==m2[index2])
		{
			if(m1[index1+1]+m2[index1+1]!=0)
			{
				temp[now]=m1[index1];
				temp[now+1]=m1[index1+1]+m2[index1+1];
				now+=2;
			}
			index1+=2;
			index2+=2;
		}else if(m1[index1]<=m2[index2])
		{
			temp[now]=m2[index2];
			temp[now+1]=m2[index2+1];
			now+=2;
			index2+=2;
		}else
		{
			temp[now]=m1[index1];
			temp[now+1]=m1[index1+1];
			now+=2;
			index1+=2;
		}
	}

	while(index1<size1)
	{
		temp[now]=m1[index1];
		temp[now+1]=m1[index1+1];
		now+=2;
		index1+=2;
	}
	while(index2<size2)
	{
		temp[now]=m2[index2];
		temp[now+1]=m2[index2+1];
		now+=2;
		index2+=2;
	}
	float answer[now];
	for(int a=0;a<now;a++)
	{
		answer[a]=temp[a];
	}
	show_f(answer,sizeof(answer)/sizeof(float));
}
void divide(float *m1,float *m2,int size1)
{
	float r=-m2[3];
	int power=m1[0];
	float rest=0;
	int now=0;
	while(power!=-1)
	{
		if(power==m1[now])
		{
			rest=rest*r+m1[now+1];
			now+=2;
			power--;
		}
		else{
			rest=rest*r;
			power--;
		}
	}
	printf("rest=%f",rest);
}
int main()
{
	float math[]={2,1,0,-29};
	float math2[]={1,0,0,2};
	
	float x=1;
	add(math,math2,sizeof(math)/sizeof(float),sizeof(math)/sizeof(float));
	divide(math,math2,sizeof(math)/sizeof(float));
}
