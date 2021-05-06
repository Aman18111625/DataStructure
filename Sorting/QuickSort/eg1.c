#include<stdio.h>
#include<stdlib.h>

int findPartitionPoint(int *x,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && x[e]<=x[lb]) e++;
while(x[f]>x[lb]) f--;
if(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[lb];
x[lb]=x[f];
x[f]=g;
}
}
return f;
}
void QuickSort(int *x,int lowerBound,int upperBound)
{
int size,*lbStack,*ubStack,top,pp,a,b;
size=(upperBound-lowerBound+1);

lbStack=(int *)malloc(sizeof(int)*size);
ubStack=(int *)malloc(sizeof(int)*size);
top=size;

top--;
lbStack[top]=lowerBound;
ubStack[top]=upperBound;

while(top!=size)
{
a=lbStack[top];
b=ubStack[top];
top++;

pp=findPartitionPoint(x,a,b);
if(pp+1<b)
{
top--;
lbStack[top]=pp+1;
ubStack[top]=b;
}
if(a<pp-1)
{
top--;
lbStack[top]=a;
ubStack[top]=pp-1;
}
}
free(lbStack);
free(ubStack);
}
int main()
{
int *x,req,y;
printf("Enter your requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement\n");
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
printf("Enter a number : ");
scanf("%d",&x[y]);
}
QuickSort(x,0,req-1);
for(y=0;y<10;y++)
{
printf("%d\n",x[y]);
}
return 0;
}