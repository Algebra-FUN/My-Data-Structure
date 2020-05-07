#include<iostream>

using namespace std;

struct Node
{
    int value;
    Node *next;
};

Node* createList(int array[],int n)
{
    Node *p = nullptr;
    for(int i=0;i<n;++i)
    {
        Node *q = (Node*)malloc(sizeof(Node));
        q->value = array[i];
        q->next = p;
        p = q;
    }
    return p;
}

void direct_sort(Node *p)
{
    Node *q = p->next;
    while(q != nullptr)
    {
        
        q = q->next;
    }
}

int main()
{
    int array[]= {1,2,3,4,5,6,7,8,9};
    Node *p = createList(array,9);
}