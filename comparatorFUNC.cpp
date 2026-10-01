#include <iostream>
template <class T>
T summary(T a, T b)
{
    T c = a + b;
    return c;
}

template <class T>
T max(T a, T b)
{
    return (a < b) ? a : b;
}

template <class T>
T comparison(T a, T b)
{
    return a < b;
}

void fill(int *arr, size_t size)
{
    std::cout << " Fill the array " << '\n';
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
}

void printarr(int *arr, size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << '\t';
    }
}
template <class T>
void sorting(int *arr, size_t size, T (*compare)(T a, T b))
{
    bool flag = true;
    while (flag == true)
    {
        flag = false;
        for (int i = 0; i < size - 1; ++i)
        {
            if (compare(arr[i], arr[i + 1]))
            {
                std::swap(arr[i], arr[i + 1]);
                flag = true;
            }
        }
    }
}

int main()
{
    size_t size;
    std::cout << " Enter the size " << '\n';
    std::cin >> size;
    int *arr = new int[size];
    fill(arr, size);
    printarr(arr, size);
    sorting(arr, size, comparison<int>);
    std::cout << " Your new arr " << '\n';
    printarr(arr, size);
    return 0;
}