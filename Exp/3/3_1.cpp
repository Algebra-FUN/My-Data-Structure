#include "3_base.h"

inline void easyDeleteBST(BSTNode **p_ptr)
{
    BSTNode *q = *p_ptr;
    *p_ptr = q->lchild == nullptr ? q->rchild : q->lchild;
    delete q;
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
        BSTNode **m_ptr = findMaxNodeptr(&(*p_ptr)->lchild);
        (*p_ptr)->key = (*m_ptr)->key;
        easyDeleteBST(m_ptr);
    }
    return true;
}

void demonstrateDeleteANode(KeyType keys[9], KeyType key)
{
    BSTNode *bst = createBST(keys, 9);
    cout << "original binary search tree:\n";
    demonstrateBST(bst);
    cout << "\nafter delete node<" << key << ">:\n";
    deleteBST(&bst, key);
    demonstrateBST(bst);
    cout << "\n----------------\n";
}

int main()
{
    KeyType keys[9] = {5, 2, 1, 6, 7, 4, 8, 3, 9};
    demonstrateDeleteANode(keys, 9);
    demonstrateDeleteANode(keys, 4);
    demonstrateDeleteANode(keys, 7);
    demonstrateDeleteANode(keys, 5);
}
