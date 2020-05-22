#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "OwnTree.h"
#include "OwnStack.h"

using namespace std;

Node_t* fillCombinationTree(BTree T,ElementType2 arrayOfData[],int n,int level)
{
    if(level<=n)
    {

        T=insert_left(T,arrayOfData[level-1]);//insert data into node

        T->left=fillCombinationTree(T->left,arrayOfData,n,level+1);
        T->right=fillCombinationTree(T->right,arrayOfData,n,level+1);
    }
    return T;
}

void getAllCombinations(BTree T,stack_t s,string comb[],int index)
{
    if(T->left==NULL&&T->right==NULL&&isEmpty(s))
    {
        cout<<T->data<<endl;
        //comb[index++]+=(char*)T->data;
        return; //comb;
    }
    else if (T->left==NULL&&T->right==NULL)
    {
        cout<<T->data<<endl;
        //comb[index++]+=(char*)T->data;
        BTree subTree;
        StackPop(&s,&subTree);
        if(!isEmpty(s))
        {
            cout<<endl;
            stack_t s2;
            createStack(&s2,s.Size);
            ElementType x;
            while(!isEmpty(s))
            {
                StackPop(&s,&x);
                StackPush(&s2,x);
            }
            while(!isEmpty(s2))
            {
                StackPop(&s2,&x);
                cout<<x->data<<" ";
                //comb[index]+=strcat((char*)x->data," ");
                StackPush(&s,x);
            }
            destroyStack(&s2);
        }
        getAllCombinations(subTree->right,s,comb,index);
    }
    else
    {
        cout<<T->data<<" ";
        //comb[index]+=strcat((char*)T->data," ");
        StackPush(&s,T);
        getAllCombinations(T->left,s,comb,index);
    }
    return;// comb;
}

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    BTree Tree=NULL;
    Tree=fillCombinationTree(Tree,arr,4,1);
    //inOrder(Tree);
    cout<<"x={1,2,3,4,5,6,7,8,9,10}";
    cout<<endl;
    stack_t s;
    createStack(&s,4);
    string* comb;
    comb=(string*)malloc(pow(2,4)*sizeof(string));
    if(comb==NULL)
    {
        cout<<"insufficient Memory"<<endl;
        return 0;
    }
    //comb=getAllCombinations(Tree,s,comb,0);
    getAllCombinations(Tree,s,comb,0);
    destroyStack(&s);
    //for(int i=0;i<pow(2,4);i++)
        //cout<<comb[i]<<endl;
    /*postOrder(Tree);
    cout<<endl;
    preOrder(Tree);
    cout<<endl;*/
    return 0;
}
