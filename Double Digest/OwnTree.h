#include <iostream>
#include <stdlib.h>

using namespace std;

typedef int ElementType2;

typedef struct node
{
    ElementType2 data;
    struct node* left;
    struct node* right;
}Node_t;

typedef Node_t* BTree;

void printNode(BTree T)
{
    cout<<T->data<<" ";
}

void preOrder(BTree T)
{
    if(T!=NULL)
    {
        printNode(T);
        preOrder(T->left);
        preOrder(T->right);
    }
}

void postOrder(BTree T)
{
    if(T!=NULL)
    {
        postOrder(T->left);
        postOrder(T->right);
        printNode(T);
    }
}

void inOrder(BTree T)
{
    if(T!=NULL)
    {
        inOrder(T->left);
        printNode(T);
        inOrder(T->right);
    }
}

int height(BTree T)
{
    int hRight,hLeft;
    if(T->left==NULL&&T->right==NULL)
    {
        return 0;
    }
    hRight=height(T->right);
    hLeft=height(T->left);
    if(hRight>hLeft)
        return hRight;
    return hLeft;
}

Node_t* insert_left(BTree T,ElementType2 x)
{
    BTree temp;
    temp=(BTree)malloc(sizeof(Node_t));
    if(temp==NULL)
    {
        cout<<"insufficient Memory"<<endl;
        return T;
    }
    temp->left=temp->right=NULL;
    temp->data=x;
    if(T==NULL)
    {
        T=temp;
    }
    else if(T->left==NULL)
    {
        T->left=temp;
    }
    else
    {
        T->left=insert_left(T->left,x);
    }
    return T;
}

Node_t* insert_right(BTree T,ElementType2 x)
{
    BTree temp;
    temp=(BTree)malloc(sizeof(Node_t));
    if(temp==NULL)
    {
        cout<<"insufficient Memory"<<endl;
        return T;
    }
    temp->left=temp->right=NULL;
    temp->data=x;
    if(T==NULL)
    {
        T=temp;
    }
    else if(T->right==NULL)
    {
        T->right=temp;
    }
    else
    {
        T->right=insert_right(T->right,x);
    }
    return T;
}