#include<stdio.h>
int main()
{
int stack1[10][2],stack2[10][2];
int x[10],temp[10];
int y,i1,i2,i3,lb1,lb2,ub1,ub2,a,b,mid,top1,top2;
top1=10;
top2=10;

for(y=0;y<10;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}


//push lb,ub on stack1
top1--;
stack1[top1][0]=0;
stack1[top1][1]=9;

while(top1!=10)
{
//pop from stack1 into a,b;
a=stack1[top1][0];
b=stack1[top1][1];
top1++;

//push a,b on stack2
top2--;
stack2[top2][0]=a;
stack2[top2][1]=b;

mid=((a+b)/2);
if(a<mid)
{
top1--;
stack1[top1][0]=a;
stack1[top1][1]=mid;
}
if(mid+1<b)
{
top1--;
stack1[top1][0]=mid+1;
stack1[top1][1]=b;
}
}

while(top2!=10)
{
//pop from stack2 into lb1,ub2;
lb1=stack2[top2][0];
ub2=stack2[top2][1];
top2++;

ub1=((lb1+ub2)/2);
lb2=ub1+1;

i1=lb1;
i2=lb2;
i3=lb1;
while(i1<=ub1 && i2<=ub2)
{
if(x[i1]<x[i2])
{
temp[i3]=x[i1];
i1++;
}
else
{
temp[i3]=x[i2];
i2++;
}
i3++;
}
while(i1<=ub1)
{
temp[i3]=x[i1];
i1++;
i3++;
}
while(i2<=ub2)
{
temp[i3]=x[i2];
i2++;
i3++;
}
i3=lb1;
while(i3<=ub2)
{
x[i3]=temp[i3];
i3++;
}
}
for(y=0;y<10;y++)
{
printf("%d\n",x[y]);
}
return 0;
}