#include<stdio.h>
#include<stdlib.h>
int main()
{
int req,y,e,f,g;
int *x;
printf("Enter your requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid Requirement\n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
for(int y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
e=0;
while(e<=req-2)
{
f=e+1;
while(f<=req-1)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
f++;
}
e++;
}
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}