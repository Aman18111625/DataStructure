#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void SelectionSort(void *ptr,int cs,int es,int (*p2f)(void *,void *))
{
int e,f,si,w,iep,oep;
void *a,*b,*c;
c=(void *)malloc(es);
oep=cs-2;
iep=cs-1;
for(e=0;e<=oep;e++)
{
for(f=e+1,si=e;f<=iep;f++)
{
a=ptr+(f*es);
b=ptr+(si*es);
w=p2f(a,b);
if(w<0)
{
si=f;
}
}
a=ptr+(e*es);
b=ptr+(si*es);
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
free(c);
}

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
printf("Enter your requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement \n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
for(y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
SelectionSort(x,req,sizeof(int),myCompatator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}