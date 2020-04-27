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
        bst = (BSTNode *)malloc(sizeof(BSTNode));
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

void easyDeleteBST(BSTNode *_p, BSTNode *p, int childlr)
{
    if (_p != nullptr)
        (childlr == -1 ? _p->lchild : _p->rchild) = p->lchild == nullptr ? p->rchild : p->lchild;
    free(p);
}

BSTNode *findMaxBSTNodeAncestor(BSTNode *p)
{
    while (p->rchild->rchild != nullptr)
        p = p->rchild;
    return p;
}

bool deleteBST(BSTNode *p, KeyType key)
{
    BSTNode *_p = nullptr;
    int childlr = 0;
    while (true)
        if (p == nullptr)
            return false;
        else if (p->key == key)
            break;
        else
        {
            _p = p;
            p = key < p->key ? p->lchild : p->rchild;
            childlr = key < p->key ? -1 : 1;
        }
    if (p->lchild == nullptr || p->rchild == nullptr)
        easyDeleteBST(_p, p, childlr);
    else
    {
        BSTNode *_m = findMaxBSTNodeAncestor(p->lchild), *m = _m->rchild;
        p->key = m->key;
        easyDeleteBST(_m, m, 1);
    }
    return true;
}

bool demonstrateBST(BSTNode *p)
{
    if (p == nullptr)
        return false;
    cout << p->key;
    if (p->lchild != nullptr || p->rchild != nullptr)
    {
        cout << '(';
        p->lchild != nullptr &&demonstrateBST(p->lchild);
        cout << ',';
        p->rchild != nullptr &&demonstrateBST(p->rchild);
        cout << ')';
    }
    return true;
}

void demonstrateDeleteANode(KeyType keys[9], KeyType key)
{
    BSTNode *bst = createBST(keys, 9);
    cout << "original binary search tree:\n";
    demonstrateBST(bst);
    cout << endl
         << "after delete node<" << key << ">:\n";
    deleteBST(bst, key);
    demonstrateBST(bst);
    cout << endl
         << "----------------" << endl;
}

int main()
{
    KeyType keys[9] = {5, 2, 1, 6, 7, 4, 8, 3, 9};
    demonstrateDeleteANode(keys, 9);
    demonstrateDeleteANode(keys, 4);
    demonstrateDeleteANode(keys, 7);
    demonstrateDeleteANode(keys, 5);
}
