#include <iostream>
#include <stdlib.h>

using namespace std;

typedef BTree ElementType;

typedef struct
{
    ElementType *content;
    int topOfStack;
    int Size;
}stack_t;

int createStack(stack_t *s,int Size)
{
    s->content=(ElementType*)malloc(Size*sizeof(ElementType));
    if(s->content==NULL)
    {
        cout<<"Insufficient Memory"<<endl;
        return 0;
    }
    s->topOfStack=-1;
    s->Size=Size;
    return 1;
}

void destroyStack(stack_t *s)
{
    free(s->content);
    s->content=NULL;
    s->topOfStack=-1;
    s->Size=0;
}

int isFull(stack_t s){return s.topOfStack>=s.Size-1;}

int isEmpty(stack_t s){return s.topOfStack<=-1;}

int StackPush(stack_t *s,ElementType val)
{
    if(!isFull(*s))
    {
        s->content[++s->topOfStack]=val;
        return 1;
    }
    cout<<"Stack overflew"<<endl;
    return 0;
}

int StackPop(stack_t *s,ElementType*val)
{
    if(!isEmpty(*s))
    {
        *val=s->content[s->topOfStack--];
        return 1;
    }
    cout<<"Stack is empty"<<endl;
    return 0;
}