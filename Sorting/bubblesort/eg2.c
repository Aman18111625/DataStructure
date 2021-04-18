#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void BubbleSort(void *ptr,int cs,int es,int (*p2f)(void *,void*))
{
int e,f,m,w;
void *a,*b,*c;
c=(void *)malloc(es);
m=cs-2;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
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
e++;
f++;
}
m--;
}
free(c);
}
struct Student
{
int rollNumber;
char name[21];
};

int StudentCompatator(void *left,void *right)
{
struct Student *s1,*s2;
s1=(struct Student *)left;
s2=(struct Student *)right;
return (s1->rollNumber)-(s2->rollNumber);
}
int main()
{
int req,y;
struct Student *s,*j;
printf("Enter requirement :");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid Requirement\n");
return 0;
}
s=(struct Student *)malloc(sizeof(struct Student)*req);
if(s==NULL)
{
printf("memory is not allocate according to %d requirement\n",req);
return 0;
}
j=s;
for(y=0;y<req;y++)
{
printf("Enter Roll Number : ");
scanf("%d",&(j->rollNumber));
printf("Enter Name : ");
scanf("%s",j->name);
j++;
}
BubbleSort(s,req,sizeof(struct Student),StudentCompatator);
for(y=0;y<req;y++)
{
printf("Roll Number : %d ,Name : %s\n",s[y].rollNumber,s[y].name);
}
free(s);
return 0;
}