#include <iostream>

using namespace std;

class Node
{
public:
    char data;
    Node *next;
    Node(char data = NULL, Node *next = NULL)
    {
        this->data = data;
        this->next = next;
    };
};

class String
{
public:
    Node *head = new Node();
    String(char array[] = "")
    {
        Node *node = this->head;
        for (int i = 0; array[i] != '\0'; i++)
        {
            node->next = new Node(array[i]);
            node = node->next;
        }
    }
    String *copy()
    {
        String *clone = new String();
        Node *q = clone->head;
        Node *p = this->head;
        while (p->next)
        {
            p = p->next;
            q->next = new Node(p->data);
            q = q->next;
        }
        return clone;
    }
    void print()
    {
        Node *node = this->head;
        while (node->next)
        {
            node = node->next;
            cout << node->data;
        }
        cout << endl;
    }
    void concat(String *str)
    {
        Node *node = this->end();
        node->next = str->copy()->head->next;
    }
    Node *end(){
        Node *node = this->head;
        while (node->next)
            node = node->next;
        return node;
    }
    Node *indexOf(int index)
    {
        Node *node = this->head;
        if (index < 0)
            throw "index must be a integer >= 0!";
        for (int i = 0; i < index; i++)
            if (node->next)
                node = node->next;
            else
                throw "index out of range!";
        return node;
    }
    void insertAt(String *str,int index)
    {
        String *clone = str->copy();
        Node *node = this->indexOf(index);
        clone->end()->next = node->next;
        node->next = clone->head->next;
    }
};

int main()
{
    String *str = new String("String():");
    String *str1 = new String("str1");
    str->print();
    str->concat(str1);
    str->print();
    str->insertAt(str1,7);
    str->print();
}
