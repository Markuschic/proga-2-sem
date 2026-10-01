#include <iostream>

template <class T>
struct Node
{
    T data;
    Node *next;
};

template <class T>
struct Stack
{
    size_t size{0};
    Node<T> *top{nullptr};
};

template <class T>
void push(Stack<T> &s, const T &element)
{
    Node<T> *ptr = new Node<T>{element, s.top};
    if (s.top == nullptr || element >= s.top->data)
    {
        ptr->next = s.top;
        s.top = ptr;
    }
    else
    {
        Node<T> *current = s.top;
        while (current->next != nullptr && current->next->data > element)
        {
            current = current->next;
        }
        ptr->next = current->next;
        current->next = ptr;
    }
    ++s.size;
}

template <class T>
T top(Stack<T> &s)
{
    return s.top->data;
}

template <class T>
T pop(Stack<T> &s)
{
    int drop = s.top->data;
    Node<T> *ptr = s.top->next;
    delete s.top;
    s.top = ptr;
    return drop;
}

template <class T>
T isempty(Stack<T> &s)
{
    return s.top == nullptr;
}

int main()
{
    Stack<int> list;
    for (int i = 0; i < 10; ++i)
    {
        push(list, i);
    }
    while (!isempty(list))
    {
        std::cout << pop(list) << '\n';
    }
    return 0;
}