#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SUCCESSFUL 1
#define FAILED 0

typedef struct __stack_t
{
void * ptr;
struct __stack_t *next;
}StackNode;

typedef struct __stack
{
int elementSize;
StackNode *top;
int size;
}Stack;

int isEmpty(Stack *stack,int *successful,int *error)
{
if(successful) *successful=FAILED;
if(error) *error=0;
if(stack==NULL) 
{
if(error) *error=1;
return 1;
}
if(successful) *successful=SUCCESSFUL;
if(stack->size==0) return 1;
return 0;
}
void initStack(Stack *stack,int elementSize,int *successful,int *error)
{
if(successful) *successful=FAILED;
if(error) *error=0;
if(stack==NULL) 
{
if(error) *error=1;
return ;
}
if(elementSize<=0)
{
if(error) *error=2;
return ;
}
stack->top=NULL;
stack->size=0;
stack->elementSize=elementSize;
if(successful) *successful=SUCCESSFUL;
}

void  push(Stack *stack, void * ptr,int *successful,int *error)
{
StackNode *t;
if(successful) *successful=FAILED;
if(error) *error=0;
if(stack==NULL)
{
if(error) *error=1;
 return ;
}
t=(StackNode *)malloc(sizeof(StackNode));
if(t==NULL)
{
if(error) *error=3;
 return ;
}
if(ptr!=NULL)
{
t->ptr=(void *)malloc(stack->elementSize);
if(t->ptr==NULL)
{
free(t);
if(error) *error=3;
return ;
}
memcpy(t->ptr,(const void *)ptr,stack->elementSize);
}
else
{
t->ptr=ptr;
}
t->next=stack->top;
stack->top=t;
stack->size++;
if(successful) *successful=SUCCESSFUL;
}

void pop(Stack *stack,void *ptr,int *successful,int *error)
{
int j;
StackNode *t;
if(successful) *successful=FAILED;
if(error) *error=0;
if(stack==NULL || ptr==NULL) 
{
if(error) *error=1;
return ;
}
if(stack->top==NULL) 
{
if(error) *error=4;
return ;
}
if(stack->top->ptr==NULL)
{
for(j=0;j<stack->elementSize;j++)
{
*((char *)(ptr+j))=(char)0;
}
}
else
{
memcpy(ptr,(const void *)stack->top->ptr,stack->elementSize);
}
t=stack->top;
stack->top=stack->top->next;
if(t->ptr!=NULL) free(t->ptr);
free(t);
stack->size--;
if(successful) *successful=SUCCESSFUL;
}     

void clearStack(Stack *stack,int *successful,int *error)
{
StackNode *node;
if(successful) *successful=FAILED;
if(error) *error=0;
if(stack==NULL)
{
*error=1;
return ;
}
while(stack->top!=NULL)
{
node=stack->top;
stack->top=stack->top->next;
if(node->ptr!=NULL) free(node->ptr);
free(node);
}
stack->size=0;
if(successful) *successful=SUCCESSFUL;
}              
void merge(void *x,int lb1,int ub1,int lb2,int ub2,int es,int (*p2f)(void *,void *),int *successful,int *error)
{
int size1,size2,size3;
int i1,i2,i3;
void *temp;
if(successful) *successful=FAILED;
if(error) *error=0;
if(x==NULL || p2f==NULL)
{
if(error) *error=1;
return ;
}
if(es<=0)
{
if(error) *error=2;
return ;
}
size1=(ub1-lb1)+1;
size2=(ub2-lb2)+1;
size3=size1+size2;
temp=(void *)malloc(sizeof(int)*size3);
if(temp==NULL)
{
if(error) *error=3;
return ;
}
i1=lb1;
i2=lb2;
i3=0;
while(i1<=ub1 && i2<=ub2)
{
if(p2f(x+i1*es,x+i2*es)<0)
{
memcpy((temp+i3*es),(const void *)(x+i1*es),es);
i1++;
}
else
{
memcpy((temp+i3*es),(const void *)(x+i2*es),es);
i2++;
}
i3++;
}
while(i1<=ub1)
{
memcpy((temp+i3*es),(const void *)(x+i1*es),es);
i1++;
i3++;
}
while(i2<=ub2)
{
memcpy((temp+i3*es),(const void *)(x+i2*es),es);
i2++;
i3++;
}
i3=0;
i1=lb1;
while(i1<=ub1)
{
memcpy((x+i1*es),(const void *)(temp+i3*es),es);
i1++;
i3++;
}
i2=lb2;
while(i2<=ub2)
{
memcpy((x+i2*es),(const void *)(temp+i3*es),es);
i2++;
i3++;
}
free(temp);
if(successful) *successful=SUCCESSFUL;
}

void mergeSort(void *x,int lowerBound,int upperBound,int es,int(*p2f)(void *,void *),int *successful,int *error)
{
struct LBUB
{
int lb,ub;
};
int isSuccessful,errorNumber;
struct LBUB lbub;
int a,b,mid;
Stack stack1;
Stack stack2;
if(successful) *successful=FAILED;
if(error) *error=0;
initStack(&stack1,sizeof(struct LBUB),&isSuccessful,&errorNumber);
initStack(&stack2,sizeof(struct LBUB),&isSuccessful,&errorNumber);
lbub.lb=lowerBound;
lbub.ub=upperBound;

push(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
if(!successful)
{
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return ;
}
while(!isEmpty(&stack1,&isSuccessful,&errorNumber))
{
pop(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
push(&stack2,(void *)&lbub,&isSuccessful,&errorNumber);
if(!successful)
{
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return ;
}
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
if(a<mid)
{
lbub.lb=a;
lbub.ub=mid;
push(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
if(!successful)
{
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return ;
}
}
if(mid+1<b)
{
lbub.lb=mid+1;
lbub.ub=b;
push(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
if(!successful)
{
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return ;
}
}
}
while(!isEmpty(&stack2,&isSuccessful,&errorNumber))
{
pop(&stack2,(void *)&lbub,&isSuccessful,&errorNumber);
if(!successful)
{
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return ;
}
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
merge(x,a,mid,mid+1,b,es,p2f,&isSuccessful,&errorNumber);
}
}

int myComparator(void *left,void *right)
{
int *leftInt,*rightInt;
leftInt=(int *)left;
rightInt=(int *)right;
return (*leftInt)-(*rightInt);
}
int main()
{
int *x,y,req;
int isSuccessful,errorNumber;
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
printf("Unable to allocate memory for %d requirement\n",req);
return 0;
}
for(y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
mergeSort(x,0,req-1,sizeof(int),myComparator,&isSuccessful,&errorNumber);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
return 0;
}