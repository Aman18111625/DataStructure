#include<stdio.h>
#include<stdlib.h>
int main()
{
int req,y,si,e,f,g;
int *x;
printf("Enter your requirement : ");
scanf("%d",&req);
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Unable to allocate memory\n");
return 0;
}
for(y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
e=0;
while(e<=req-2)
{
si=e;
f=e+1;
while(f<=req-1)
{
if(x[f]<x[si])
{
si=f;
}
f++;
}
g=x[si];
x[si]=x[e];
x[e]=g;
e++;
}
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
return 0;
}