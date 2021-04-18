#include<stdio.h>
int main()
{
int x[5],y,e,f,g;
for(int y=0;y<5;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
e=0;
while(e<=3)
{
f=e+1;
while(f<=4)
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
for(y=0;y<5;y++)
{
printf("%d\n",x[y]);
}
return 0;
}