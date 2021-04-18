#include<stdio.h>
#include<stdlib.h>
void LinearSort(int *x,int cs)
{
int e,f,g,iep,oep;
iep=cs-1;
oep=cs-2;
for(e=0;e<=oep;e++)
{
for(f=e+1;f<=iep;f++)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
}
}
}
int main()
{
int req,y,*x;
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
printf("Unable to allocate Memory\n");
return 0;
}
for(y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
LinearSort(x,req);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}