#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void InsertionSort(void *ptr,int lb,int ub,int es,int (*p2f)(void *,void *))
{
int y,j;
void *num;
num=(void *)malloc(es);
y=lb+1;;
while(y<=ub)
{
memcpy(num,(void *)(ptr+(y*es)),es);
j=y-1;
while(j>=0 && p2f(ptr+(j*es),num)>0)
{
memcpy(ptr+((j+1)*es),(const void *)(ptr+j*es),es);
j--;
}
memcpy(ptr+((j+1)*es),(const void *)num,es);
y++;
}
free(num);
}
int myComparator(void *left,void *right)
{
int *i,*j;
i=(int *)left;
j=(int *)right;
return (*i)-(*j);
}
int main()
{
int *x,req,y,start,end;
printf("Enter your requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement \n");
return 0;
}
printf("Enter start Point  : ");
scanf("%d",&start);
if(start<0 || start>=req)
{
printf("invalid start point %d in case of collection of %d numbers\n",start,req);
return 0; 
}
printf("Enter end  point :  ");
scanf("%d",&end);
if(end<start || end>=req)
{
printf("Invalid End point %d in case of start point is %d and collection of numbers is %d\n",end,start,req);
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL) 
{
printf("Unable to allocate memory for %d numbers\n",req);
return 0;
}
for(y=0;y<req;y++)
{
printf("Enter a number  : ");
scanf("%d",&x[y]);
}
InsertionSort(x,start,end,sizeof(int),myComparator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
return 0;
}