#include <iostream>

using namespace std;

typedef char Data;

class Node
{
public:
    Data data;
    Node *next;
    Node(Data data = NULL, Node *next = NULL)
    {
        this->data = data;
        this->next = next;
    }
};

class LinkedStack
{
private:
    Node *top = new Node();

public:
    void push(Data data)
    {
        top->next = new Node(data, top->next);
    }
    bool isEmpty()
    {
        return top->next == NULL;
    }
    Data pop()
    {
        if (this->isEmpty())
            return NULL;
        Data data = top->next->data;
        top->next = top->next->next;
        return data;
    }
};

int main()
{
}