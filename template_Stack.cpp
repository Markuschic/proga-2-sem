#include <iostream>

template <class T>

struct Stack
{
    T *arr{nullptr};
    size_t size;
    size_t top{0};
};
template <class T>
bool emtpy(Stack<T> &s)
{
    return s.top == 0;
}
template <class T>
void init(Stack<T> &s, size_t size)
{
    s.size = size;
    s.arr = new int[size];
}
template <class T>
void push(Stack<T> &s, int value)
{
    s.arr[s.top++] = value;
}
template <class T>
int pop(Stack<T> &s)
{
    return s.arr[--s.top];
}
template <class T>
int top(Stack<T> &s)
{
    return s.arr[s.top - 1];
}
template <class T>
void clear(Stack<T> &s)
{
    delete[] s.arr;
    s.top = 0;
    s.size = 0;
}

int main()
{
    ;
    Stack<int> mystack;
    init(mystack, 100);
    for (int i = 0; i < 6; ++i)
    {
        push(mystack, i);
    }
    std::cout << top(mystack) << '\n'; // просто вывел элемент который находится в pop
    for (int i = 0; i < 6; ++i)
    {
        std::cout << pop(mystack) << '\n';
    }
    clear(mystack);
    // Stack<Stack<int>> c;
}