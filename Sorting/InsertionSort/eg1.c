#include<stdio.h>
#include<stdlib.h>
int main()
{
int req,y,j,num;
int *x;
printf("Enter requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement\n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL) 
{
printf("Unable to locate memory\n");
return 0;
}
for(y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
y=1;
while(y<=req-1)
{
num=x[y];
j=y-1;
while(j>=0 && x[j]>num)
{
x[j+1]=x[j];
j--;
}
x[j+1]=num;
y++;
}
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
return 0;
}