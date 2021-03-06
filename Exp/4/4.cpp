#include <iostream>
#define DICT_SIZE 23
#define MAX_LEN 15
#define CHAR_N 27

using namespace std;

inline int index(char c)
{
    return c == '\0' ? 0 : c - 'a' + 1;
}

struct WNode
{
    char *word;
    WNode *next;
};

class WQueue
{
public:
    WNode *head = nullptr, *tail = nullptr;
    void push(WNode *p)
    {
        (this->head == nullptr ? this->head : this->tail->next) = p;
        this->tail = p;
        p->next = nullptr;
    }
    void join(WQueue wq)
    {
        if (wq.head == nullptr)
            return;
        (this->head == nullptr ? this->head : this->tail->next) = wq.head;
        this->tail = wq.tail;
    }
};

WNode *create_word_list(char word_array[DICT_SIZE][MAX_LEN])
{
    WNode *p = nullptr, *q;
    for (int i = 0; i < DICT_SIZE; ++i)
    {
        q = new WNode;
        q->word = word_array[i];
        q->next = p;
        p = q;
    }
    return p;
}

WNode *dict_sort(WNode *p)
{
    WNode *q;
    for (int i = MAX_LEN - 1; i >= 0; --i)
    {
        WQueue queues[CHAR_N], assembler;
        q = nullptr;
        while (p != nullptr)
        {
            q = p->next;
            queues[index(p->word[i])].push(p);
            p = q;
        }
        for (int j = 0; j < CHAR_N; ++j)
            assembler.join(queues[j]);
        p = assembler.head;
    }
    return p;
}

void print_dict(WNode *p)
{
    while (p != nullptr)
        cout << p->word << endl, p = p->next;
}

int main()
{
    char word_array[DICT_SIZE][MAX_LEN] = {
        "java",
        "ruby",
        "perl",
        "kotlin",
        "basic",
        "vscode",
        "pascal",
        "apple",
        "android",
        "swift",
        "julia",
        "python",
        "javascript",
        "html",
        "css",
        "editor",
        "list",
        "apply",
        "data",
        "struct",
        "egg",
        "application",
        "edit",
    };
    WNode *p = create_word_list(word_array);
    p = dict_sort(p);
    print_dict(p);
}