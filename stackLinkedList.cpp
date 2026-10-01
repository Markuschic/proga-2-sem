#include <iostream>

struct Node
{
    int data;
    Node *next;
};

struct Stack
{
    size_t size{0};
    Node *top{nullptr};
};

void push(Stack &s, const char &element)
{
    Node *ptr = new Node{element, s.top};
    s.top = ptr;
    ++s.size;
}

int top(Stack &s)
{
    return (*s.top).data; // s.top -> data
}

int pop(Stack &s)
{
    int drop = (*s.top).data;
    Node *ptr = (*s.top).next;
    delete s.top;
    s.top = ptr;
    return drop;
}

int main()
{
    Stack list;
    push(list, 1);
    push(list, 2);
    push(list, 3);
    std::cout << top(list) << '\n';
    while (list.top != nullptr)
    {
        std::cout << pop(list) << '\n';
    }
    return 0;
}