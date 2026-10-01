#include <iostream>

template <class T>
struct Stack
{
    T *arr;
    size_t size;
    size_t top;
    float resize_factor; // на какой коэффициент нужно расширяться
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
    s.resize_factor = 1.67;
}

template <class T>
T min(const T &value1, const T &value2)
{
    return (value1 > value2) ? value2 : value1;
}

template <class T>
void resize(Stack<T> &s, size_t newsize)
{
    T *newarr = new T[newsize];
    if (s.size == newsize)
    {
        return;
    }
    for (size_t i = 0; i < min(s.size, newsize); ++i)
    {
        newarr[i] = s.arr[i];
    }
    delete[] s.arr;
    s.arr = newarr;
    s.size = newsize;
    if (s.top > newsize)
    {
        s.top = newsize;
    }
}

template <class T>
void push(Stack<T> &s, const T &element)
{
    if (s.size >= s.top)
    {
        resize(s, (s.size * s.resize_factor));
    }
    s.arr[s.top++] = element;
}

template <class T>
T top(Stack<T> &s)
{
    return s.arr[s.top - 1];
}

template <class T>
T pop(Stack<T> &s)
{
    return s.arr[--s.top];
}

template <class T>
void clear(Stack<T> &s)
{
    delete[] s.arr;
    s.size = 0;
    s.top = 0;
}

size_t priority(const char &sign)
{
    if (sign == '(')
        return 0;
    if (sign == '+' || sign == '-')
        return 1;
    if (sign == '*' || sign == '/')
        return 2;
    if (sign == '^')
        return 3;
    return -1;
}
std::string opn(std::string stroka)
{
    std::string result{""};
    Stack<char> operators;
    init(operators, stroka.size());
    for (size_t i = 0; i < stroka.size(); ++i)
    {
        if (stroka[i] >= 48 && stroka[i] <= 57) // аски код цифр 0 - 9
        {
            result += stroka[i];
        }
        else if (stroka[i] == '(')
            push(operators, '(');
        else if (stroka[i] == ')')
        {
            while (top(operators) != '(')
            {
                result += pop(operators);
            }
            pop(operators);
        }
        else
        {
            while (!isempty(operators) && priority(top(operators)) >= priority(stroka[i]))
            {
                result += pop(operators);
            }
            push(operators, stroka[i]);
        }
    }
    while (!isempty(operators))
    {
        result += pop(operators);
    }
    clear(operators);
    return result;
}

int main()
{
    std::string stroka{"2*(3+4)^2"};
    std::cout << opn(stroka) << '\n';
    return 0;
}