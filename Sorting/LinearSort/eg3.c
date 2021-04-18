#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void LinearSort(void *ptr,int cs,int es,int (*p2f)(void *,void *))
{
int e,f,w,iep,oep;
void *a,*b,*c;
c=(void *)malloc(es);
oep=cs-2;
iep=cs-1;
for(e=0;e<=oep;e++)
{
for(f=e+1;f<=iep;f++) 
{
a=ptr+(f*es);
b=ptr+(e*es);
w=p2f(a,b);
if(w<0)
{
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
}
}
free(c);
}

int myCompatator(void *left,void *right)
{
int *num1,*num2;
num1=(int *)left;
num2=(int *)right;
return (*num1)-(*num2);
}

int main()
{
int *x,y,req;
printf("Enter your requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid Requirement\n");
return 0;
}
x=(int *)malloc(sizeof(int )*req);
for(y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
LinearSort(x,req,sizeof(int),myCompatator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
return 0;
}