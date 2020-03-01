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

public:
    int length(){
        Node *node = this->head;
        int length = 0;
        while(node->next)
            node = (length++,node->next);
        return length;
    }
    void appendData(Data data)
    {
        Node *node = this->head;
        while (node->next)
            node = node->next;
        node->next = new Node(data, NULL);
    }
    void insertDataAt(Data data,int index){
        Node *node = this->getNodeByIndex(index);
        node->next = new Node(data,node->next);
    }
    void removeAt(int index){
        if(index == 0)
            throw "can't remove head node!";
        Node *prior = this->getNodeByIndex(index-1);
        Node *node = prior->next;
        prior->next = prior->next->next;
        free(node);
    }
    Data getDataByIndex(int index)
    {
        return this->getNodeByIndex(index)->data;
    }
    Node* getNodeByIndex(int index)
    {
        Node *node = this->head;
        if (index < 0)
            throw "index must be a integer >= 0!";
        for (int i = 0; i < index; i++){
            if(node->next)
                node = node->next;
            else
                throw "index out of range!";
            
        }
        return node;
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
    list->appendData(1);
    list->appendData(2);
    list->appendData(3);
    list->printAll();
    list->insertDataAt(4,2);
    list->printAll();
    list->removeAt(1);
    list->printAll();
    cout << "length = " << list->length() << endl;
    cout << "indexOf(2) = " << list->getDataByIndex(2) << endl;
}
