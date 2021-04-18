#include<stdio.h>
#include<stdlib.h>
void InsertionSort(int *r,int cs)
{
int j,y,num;
y=1;
while(y<cs)
{
num=r[y];
j=y-1;
while(j>=0 && r[j]>num)
{
r[j+1]=r[j];
j--;
}
r[j+1]=num;
y++;
}
}
int main()
{
int *x,req,y;
printf("Enter your requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid Requirement\n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
for(y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
InsertionSort(x,req);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}