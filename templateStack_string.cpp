#include <iostream>
template <class T>
struct Stack
{
    T *arr;
    size_t size;
    size_t top;
};
template <class T>
bool isempty(Stack<T> &s)
{
    return s.top == 0;
}
template <class T>
void init(Stack<T> &s, size_t size)
{
    s.size = size;
    s.arr = new T[size];
    s.top = 0;
}
template <class T>
void push(Stack<T> &s, T element)
{
    s.arr[s.top++] = element;
}
template <class T>
T pop(Stack<T> &s)
{
    return s.arr[--s.top];
}
template <class T>
T top(Stack<T> &s)
{
    return s.arr[s.top - 1];
}
template <class T>
void clear(Stack<T> &s)
{
    delete[] s.arr;
    s.size = 0;
    s.top = 0;
}

int main()
{
    Stack<std::string> mystack;
    isempty(mystack);
    std::string stroka{"Hello world"};
    init(mystack, stroka.length());
    while (!stroka.empty())
    {
        push(mystack, stroka.substr(0, 1));
        stroka.erase(0, 1);
    }
    while (!isempty(mystack))
    {
        std::cout << pop(mystack) << '\n';
    }
    clear(mystack);
    return 0;
}