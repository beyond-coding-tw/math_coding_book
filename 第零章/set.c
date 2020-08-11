#include<stdio.h>

typedef struct {
	
 unsigned int n;
	
}Set;

void AddSet (Set *s, int e);
void DelSet (Set *s, int e);
int IsInSet(Set *s, int e);  
void FillSet(Set *s);   //S={0..31}
void EmptySet(Set *s);  //S={ }
int IsSetEqual(Set *s1,Set *s2);


int main()
{


Set A;  
int y;
EmptySet(&A);  //A={ }
AddSet(&A,12);  //A={12}
AddSet(&A,13);  // A={12,13};

y=IsInSet(&A, 12);   // y is 1
printf("12 is in set? %d\n",y);

DelSet(&A,12);  // A={13};


y=IsInSet(&A, 12);   // y is 1
printf("12 is in set? %d\n",y);

y=IsInSet(&A, 13);   // y is 1
printf("13 is in set? %d\n",y);

getchar();


return 0; 


}
/////////////////////////////////////////////
void AddSet (Set *s, int e)
{
    s->n|=0x1<<e;
     
}

void DelSet (Set *s, int e)
{
     
   s->n&=~(0x1<<e);  
     
}
int IsInSet(Set *s, int e)
{
   return (s->n>>e)&0x1?1:0;  
     
}
void FillSet(Set *s)
{
     
     s->n=-1;   
     
}   
void EmptySet(Set *s)
{
     
    s->n=0;     
     
}
  
int IsSetEqual(Set *s1,Set *s2)
{
    
    return (s1->n==s2->n)?1:0;
    
   
    
    
}
