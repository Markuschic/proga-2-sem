#include <iostream>

template <class T>
struct Node
{
    T data;
    Node<T> *next;
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
    s.top = ptr;
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
    T drop = s.top->data;
    Node<T> *ptr = (s.top)->next;
    delete s.top;
    s.top = ptr;
    return drop;
}

int main()
{
    Stack<double> list;
    push(list, 14.88);
    push(list, 3.14);
    while (list.top != nullptr)
    {
        std::cout << pop(list) << '\n';
    }
    return 0;
}