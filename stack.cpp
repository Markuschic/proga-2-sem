#include <iostream>

struct Stack
{
    std::string *arr{};
    size_t size;
    size_t top{0};
};

bool checkelem(Stack &s)
{
    return s.top == 0;
}

void init(Stack &s, size_t size)
{
    s.size = size;
    s.arr = new std::string[size];
}

std::string top(Stack &s)
{
    return s.arr[s.top - 1];
}

void push(Stack &s, std::string stroka)
{
    s.arr[s.top++] = stroka;
}

std::string pop(Stack &s)
{
    return s.arr[--s.top];
}

void clear(Stack &s)
{
    delete[] s.arr;
    s.size = 0;
    s.top = 0;
}

int main()
{
    std::string stroka = "Hello world";
    Stack mystack;
    checkelem(mystack);
    init(mystack, stroka.length());
    std::cout << top(mystack) << '\n';
    while (!stroka.empty())
    {
        push(mystack, stroka.substr(0, 1));
        stroka.erase(0, 1);
    }
    while (!checkelem(mystack))
    {
        std::cout << pop(mystack) << '\n';
    }
    clear(mystack);
    return 0;
}