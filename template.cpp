#include <iostream>

template <class T1, class T2>
T1 summary (T1 a, T2 b)
{
    return a+b;
}

int main()
{
    int a = 5;
    double b = 12.88;
    std::cout << summary (a,b) << '\n';
    return 0;
}