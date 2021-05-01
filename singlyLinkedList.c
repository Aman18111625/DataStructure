#include<stdio.h>
#include<stdlib.h>

struct Node 
{
int num;
struct Node *next;
};

struct Node *start;

void addAtEnd(int num)
{
struct Node *t,*j;
t=(struct Node *)malloc(sizeof(struct Node));
if(t==NULL) return ;
t->num=num;
t->next=NULL;
if(start==NULL)
{
start=t;
}
else
{
j=start;
while(j->next!=NULL)
{
j=j->next;
}
j->next=t;
}
}

void TraverseTopToBottom()
{
struct Node *t;
for(t=start;t!=NULL;t=t->next)
{
printf("%d\n",t->num);
}
}

void InsertAtTop(int num)
{
struct Node *t;
t=(struct Node *)malloc(sizeof(struct Node));
if(t==NULL) return ;
t->num=num;
t->next=start;
start=t;
}

int InsertAt(int num,int pos)
{
struct Node *t,*p1,*p2;
int x;
if(pos<0)
{
return 0;
}
x=0;
p1=start;
while(p1!=NULL && x<pos)
{
p2=p1;
p1=p1->next;
x++;
}
if(p1==NULL && x<pos)
{
return 0;
}
t=(struct Node *)malloc(sizeof(struct Node));
if(t==NULL) return 0;
t->num=num;
t->next=NULL;
if(start==NULL)
{
start=t;
return 1;
}
if(p1==start)
{
t->next=start;
start=t;
return 1;
}
if(p1==NULL)
{
p2->next=t;
return 1;
}
t->next=p1;
p2->next=t;
return 1;
}

int RemoveAt(int pos)
{
struct Node *p1,*p2;
int x;
if(pos<0)
{
return 0;
}
x=0;
p1=start;
while(p1!=NULL && x<pos)
{
p2=p1;
p1=p1->next;
x++;
}
if(p1==NULL &&x<pos)
{
return 0;
}
if(p1==start)
{
start=start->next;
}
else
{
p2->next=p1->next;
}
free(p1);
return 1;
}

int main()
{
int ch,num,pos;
start=NULL;
while(1)
{
printf("1.add at End\n");
printf("2.InsertAtTop\n");
printf("3.Insert at\n");
printf("4.RemoveAt\n");
printf("5.Traverse Top To Bottom\n");
printf("6.Exit\n");
printf("Enter your choice :");
scanf("%d",&ch);
if(ch==1)
{
printf("Enter a number to add at end: ");
scanf("%d",&num);
addAtEnd(num);
printf("%d added \n",num);
}
else if(ch==2)
{
printf("Enter a number to insert at top: ");
scanf("%d",&num);
InsertAtTop(num);
printf("%d inserted \n",num);
}
else if(ch==3)
{
printf("Enter a position : ");
scanf("%d",&pos);
printf("Enter a number to insert at %d position : ",pos);
scanf("%d",&num);
if(InsertAt(num,pos))
{
printf("%d inserted at %d position\n",num,pos);
}
else
{
printf("%d is Invalid Position \n",pos);
}
}
else if(ch==4)
{
printf("Enter a position : ");
scanf("%d",&pos);
if(RemoveAt(pos))
{
printf("Element removed from %d position\n",pos);
}
else printf("%d is Invalid Position\n",pos);
}
else if(ch==5)
{
TraverseTopToBottom();
}
else if(ch==6) break;
else printf("Invalid choice \n");
}
}