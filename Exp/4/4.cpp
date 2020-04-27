#include <iostream>
#define DICT_SIZE 23
#define MAX_LEN 15
#define CHAR_N 27

using namespace std;

inline int index(char c)
{
    return c == '\0' ? 0 : c % 'a' + 1;
}

struct WNode
{
    char *string;
    WNode *next;
};

class WQueue
{
public:
    WNode *head = nullptr, *tail = nullptr;
    void push(WNode *p)
    {
        if (this->head == nullptr)
            this->head = p, this->tail = p;
        else
            this->tail->next = p, this->tail = p;
        p->next = nullptr;
    }
};

WNode *create_p(char word_array[DICT_SIZE][MAX_LEN])
{
    WNode *p = nullptr;
    for (int i = 0; i < DICT_SIZE; ++i)
    {
        WNode *q = (WNode *)malloc(sizeof(WNode));
        q->string = word_array[i];
        q->next = p;
        p = q;
    }
    return p;
}

WNode *dict_sort(WNode *p)
{
    WNode *q, *tail;
    for (int i = MAX_LEN - 1; i >= 0; --i)
    {
        WQueue wqs[CHAR_N];
        q = nullptr;
        while (p != nullptr)
        {
            q = p->next;
            wqs[index(p->string[i])].push(p);
            p = q;
        }
        p = nullptr,tail = nullptr;
        for (int j = 0; j < CHAR_N; ++j)
        {
            if (wqs[j].head == nullptr)
                continue;
            (p == nullptr ? p : tail->next) = wqs[j].head;
            tail = wqs[j].tail;
        }
    }
    return p;
}

void print_dict(WNode *p)
{
    while (p != nullptr)
    {
        cout << p->string << endl;
        p = p->next;
    }
}

int main()
{
    char word_array[DICT_SIZE][MAX_LEN] = {
        "apple",
        "android",
        "java",
        "ruby",
        "perl",
        "kotlin",
        "basic",
        "vscode",
        "pascal",
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
    WNode *p = create_p(word_array);
    p = dict_sort(p);
    print_dict(p);
}