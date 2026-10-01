#include <iostream>

/*
bool (*comparator)(constT&, constT&);
*/

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    int a, b;

    int (*ptr)(int, int) = sum;
    std::cout << ptr(5, 2) << '\n';

    return 0;
}