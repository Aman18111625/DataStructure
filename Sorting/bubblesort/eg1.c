#include<string.h>
#include<stdlib.h>
#include<stdio.h>
/*
Bubble sort algorithm written by suresh in 2020
ptr for storing base address
cs reperesnts collection size
es represents element size
*/
void bubblesort(void *ptr,int cs,int es, int (*p2f)(void *,void *))
{
int e,f,m,w;
void *a,*b,*c;
c=(void *)malloc(es);
m=cs-2;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
a=ptr+(f*es);
b=ptr+(e*es);
w=p2f(a,b);
if(w<0)
{
memcpy(c,(const void *)a, es);
memcpy(a,(const void *)b, es);
memcpy(b,(const void *)c, es);
}
e++;
f++;
}
m--;
}
free(c);
}
//the following code written by mahesh
int myCompatator(void *left,void *right)
{
int *i,*j;
i=(int *)left;
j=(int *)right;
return (*i)-(*j);
}
int main()
{
int *x,req,y;
printf("Enter Requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid Requirement\n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Unable to allocate memory according to requirement %d\n",req);
return 0;
}
for(y=0;y<req;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
bubblesort(x,req,sizeof(int),myCompatator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}