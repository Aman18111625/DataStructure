#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void InsertionSort(void *ptr,int cs,int es,int (*p2f)(void *,void *))
{
int y,ep,j;
void *num;
num=(void *)malloc(es);
ep=cs-1;
for(y=1;y<=ep;y++)
{
memcpy(num,(void *)(ptr+(y*es)),es);
j=y-1;
while(j>=0 && p2f(ptr+(j*es),num)>0)
{
memcpy(ptr+((j+1)*es),(const void*)(ptr+(j*es)),es);
j--;
}
memcpy((ptr+(j+1)*es),(const void *)num,es);
}
free(num);
}
int myCompatator(void *left,void *right)
{
int *i,*j;
i=(int *)left;
j=(int *)right;
return (*i)-(*j);
}
int main()
{
int req,*x,y;
printf("Enter your requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid Requirement \n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
for(y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
InsertionSort(x,req,sizeof(int),myCompatator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}