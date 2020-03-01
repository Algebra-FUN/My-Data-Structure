#include <iostream>

using namespace std;

typedef int Data;

class Node
{
public:
    Data data;
    Node *prior;
    Node *next;
    Node(Data data,Node *prior,Node *next){
        this->data = data;
        this->prior = prior;
        this->next = next;
    }
};

class List
{
    Node *head = new Node(NULL,NULL,NULL);
};

int main(){
    List *list = new List();

}