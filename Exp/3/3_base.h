#include <iostream>

using namespace std;

typedef int KeyType;

struct BSTNode
{
    KeyType key;
    BSTNode *lchild, *rchild;
};

bool insertBST(BSTNode *&bst, KeyType key)
{
    if (bst == nullptr)
    {
        bst = new BSTNode;
        bst->key = key, bst->lchild = bst->rchild = nullptr;
        return true;
    }
    if (bst->key == key)
        return false;
    return insertBST(key < bst->key ? bst->lchild : bst->rchild, key);
}

BSTNode *createBST(KeyType keys[], int n)
{
    BSTNode *bst = nullptr;
    for (int i = 0; i < n; ++i)
        insertBST(bst, keys[i]);
    return bst;
}

void demonstrateBST(BSTNode *p)
{
    if (p == nullptr)
        return;
    cout << p->key;
    if (p->lchild != nullptr || p->rchild != nullptr)
    {
        cout << '(';
        demonstrateBST(p->lchild);
        cout << ',';
        demonstrateBST(p->rchild);
        cout << ')';
    }
}