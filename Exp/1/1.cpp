#include "1_base.h"

typedef void (*FP)(TBTNode *&p);

TBTNode *pre;

inline void thread_node(TBTNode *&p)
{
    if (p == nullptr)
        return;
    if (p->lchild == nullptr)
    {
        p->lchild = pre;
        p->ltag = 1;
    }
    else
        p->ltag = 0;
    if (pre->rchild == nullptr)
    {
        pre->rchild = p;
        pre->rtag = 1;
    }
    else
        p->rtag = 0;
    pre = p;
}

TBTNode *create_thread(TBTNode *p, FP thread)
{
    TBTNode *root = (TBTNode *)malloc(sizeof(TBTNode));
    root->ltag = 0, root->rtag = 1;
    root->rchild = p;
    if (p == nullptr)
        root->lchild = root;
    else
    {
        root->lchild = p;
        pre = root;
        thread(p);
        pre->rchild = root;
        pre->rtag = 1;
        root->rchild = pre;
    }
    return root;
}

void preorder_thread(TBTNode *&p)
{
    if(p == nullptr)
        return;
    thread_node(p);
    if (p->ltag == 0)
        preorder_thread(p->lchild);
    if (p->rtag == 0)
        preorder_thread(p->rchild);
}

TBTNode *create_preorder_thread(TBTNode *p)
{
    return create_thread(p, preorder_thread);
}

void preorder_TBT_traversal(TBTNode *root)
{
    TBTNode *p = root->lchild;
    while (p != root)
    {
        cout << p->data;
        if (p->ltag == 0)
            p = p->lchild;
        else
            p = p->rchild;
    }
}

void inorder_thread(TBTNode *&p)
{
    if (p == nullptr)
        return;
    if (p->ltag == 0)
        inorder_thread(p->lchild);
    thread_node(p);
    if (p->rtag == 0)
        inorder_thread(p->rchild);
}

TBTNode *create_inorder_thread(TBTNode *p)
{
    return create_thread(p, inorder_thread);
}

void inorder_TBT_traversal(TBTNode *root)
{
    TBTNode *p = root->lchild;
    while (p != root)
    {
        while(p->ltag == 0) 
            p = p->lchild;
        cout << p->data;
        while(p->rtag == 1 && p->rchild != root)
        {
            p = p->rchild;
            cout << p->data;
        }
        p = p->rchild;
    }
}
    
void postorder_thread(TBTNode *&p)
{
    if (p->ltag == 0)
        postorder_thread(p->lchild);
    if (p->rtag == 0)
        postorder_thread(p->rchild);
    thread_node(p);
}

TBTNode *create_postorder_thread(TBTNode *p)
{
    return create_thread(p, postorder_thread);
}

int main()
{
    char string[] = "A(B(D(,G),),C(E,F))";
    cout << "original binary tree:" << string << endl;
    TBTNode *p;
    p = buildTBT(string);
    p = create_preorder_thread(p);
    cout << "preorder_thread_traversal:";
    preorder_TBT_traversal(p);
    cout << endl;
    p = buildTBT(string);
    p = create_inorder_thread(p);
    cout << "inorder_thread_traversal:";
    inorder_TBT_traversal(p);
    cout << endl;
    p = buildTBT(string);
    p = create_inorder_thread(p);
    cout << "postorder_thread";
}