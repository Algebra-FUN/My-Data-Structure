#include <iostream>

using namespace std;

typedef int Data;

class Node
{
public:
    Data data;
    Node *next;
    Node(Data data, Node *next)
    {
        this->data = data;
        this->next = next;
    };
};

class List
{
private:
    Node *head = new Node(NULL, NULL);
    void removeAfterNode(Node *pre){
        Node *node = pre->next;
        pre->next = pre->next->next;
        free(node);
    }

public:
    void insertData(Data data)
    {
        Node *pre = this->head;
        while (pre->next && pre->next->data < data)
            pre = pre->next;
        pre->next = new Node(data, pre->next);
    }
    void removeTheRepeat()
    {
        Node *node = this->head;
        while(node->next){
            if(node->data == node->next->data)
                this->removeAfterNode(node);
            else
                node = node->next;
        }
            
    }
    void printAll()
    {
        Node *node = this->head;
        while (node->next)
        {
            node = node->next;
            cout << node->data << ' ';
        }
        cout << endl;
    }
};

int main()
{
    List *list = new List();
    list->insertData(2);
    list->insertData(5);
    list->insertData(3);
    list->insertData(4);
    list->insertData(1);
    list->insertData(3);
    list->insertData(6);
    list->insertData(3);
    list->insertData(4);
    list->printAll();
    list->removeTheRepeat();
    list->printAll();
}