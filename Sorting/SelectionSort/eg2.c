#include<stdio.h>
#include<stdlib.h>
void SelectionSort(int *r,int cs)
{
int e,f,si,g,iep,oep;
oep=cs-2;
iep=cs-1;
for(e=0;e<=oep;e++)
{
for(f=e+1,si=e;f<=iep;f++)
{
if(r[f]<r[si])
{
si=f;
}
}
g=r[si];
r[si]=r[e];
r[e]=g;
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
for(y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
SelectionSort(x,req);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
return 0;
}