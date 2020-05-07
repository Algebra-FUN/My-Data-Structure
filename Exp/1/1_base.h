#include <iostream>
#define MAX_NODE_N 10

using namespace std;

struct TBTNode
{
    char data;
    int ltag, rtag;
    TBTNode *lchild, *rchild;
};

TBTNode *initNode(char chr)
{
    TBTNode *p = (TBTNode *)malloc(sizeof(TBTNode));
    p->data = chr;
    p->ltag = 0, p->rtag = 0;
    p->lchild = nullptr, p->rchild = nullptr;
    return p;
}

TBTNode *buildTBT(char string[])
{
    int lr = 0;
    TBTNode *stack[MAX_NODE_N], *p, *q;
    int stack_ptr = -1;
    int is_node = 0;
    for(int i = 0;;++i)
    {
        char chr = string[i];
        if (chr == '\0')
            break;
        else if (chr == '(')
            lr = 0,is_node = 0;
        else if (chr == ',')
            lr = 1,is_node && --stack_ptr,is_node = 0;
        else if (chr == ')')
            is_node && --stack_ptr,is_node = 1;
        else
        {
            p = initNode(chr);
            is_node = 1;
            if (stack_ptr != -1)
            {
                q = stack[stack_ptr];
                (lr == 0 ? q->lchild : q->rchild) = p;
            }
            stack[++stack_ptr] = p;
        }
    }
    return stack[0];
}

void demonstrateTBT(TBTNode *p)
{
    if(p == nullptr)
        return;
    cout << p->data;
    if(p->lchild != nullptr || p->rchild != nullptr)
    {
        cout << '(';
        demonstrateTBT(p->lchild);
        cout << ',';
        demonstrateTBT(p->rchild);
        cout << ')';
    }
}

// int main()
// {
//     char string[] = "A(B(D(,G),),C(E,F))\0";
//     TBTNode *p = buildTBT(string);
//     demonstrateTBT(p);
// }