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

void easyDeleteBST(BSTNode **p_ptr)
{
    BSTNode *q = *p_ptr;
    *p_ptr = q->lchild == nullptr ? q->rchild : q->lchild;
    free(q);
}

BSTNode **findMaxNodeptr(BSTNode **p_ptr)
{
    while ((*p_ptr)->rchild != nullptr)
        p_ptr = &(*p_ptr)->rchild;
    return p_ptr;
}

bool deleteBST(BSTNode **p_ptr, KeyType key)
{
    while (true)
        if (*p_ptr == nullptr)
            return false;
        else if ((*p_ptr)->key == key)
            break;
        else
            p_ptr = &(key < (*p_ptr)->key ? (*p_ptr)->lchild : (*p_ptr)->rchild);
    if ((*p_ptr)->lchild == nullptr || (*p_ptr)->rchild == nullptr)
        easyDeleteBST(p_ptr);
    else
    {
        BSTNode **m_ptr = findMaxNodeptr(&((*p_ptr)->lchild));
        (*p_ptr)->key = (*m_ptr)->key;
        easyDeleteBST(m_ptr);
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
    deleteBST(&bst, key);
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
