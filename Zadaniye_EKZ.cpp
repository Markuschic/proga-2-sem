#include <cctype>
#include <cstring>
#include <iostream>

void getnumbers(const char *stroka, int *arrdigits, size_t size, size_t &count)
{
    count = 0;
    size_t length = strlen(stroka);
    for (int i = 0; i < length; ++i)
    {
        if (isdigit(stroka[i]))
        {
            arrdigits[count] = stroka[i] - '0'; // Чтобы получить настоящее число, нужно вычесть код нуля
            ++count;
        }
    }
}

template <class T>
void printarr(T *arr, size_t found_elements)
{
    for (int i = 0; i < found_elements; ++i)
    {
        std::cout << arr[i] << '\n';
    }
}

bool iseven(int number)
{
    return number % 2 == 0;
}

template <class T>
bool comparison(T a, T b)
{
    return a < b;
}

template <class T>
bool evencomparison(const T &a, const T &b)
{
    bool a_even = iseven(a);
    bool b_even = iseven(b);
    if (a_even != b_even)
    {
        return a_even;
    }
    return a < b; // если четности равны
}

template <class T>
void myqsort(T *arr, int left, int right, bool (*compare)(const T &a, const T &b))
{
    if (left >= right)
    {
        return;
    }
    int half = arr[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j)
    {
        while (compare(arr[i], half))
        {
            ++i;
        }
        while (compare(half, arr[j]))
        {
            --j;
        }
        if (i <= j)
        {
            std::swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    }
    myqsort(arr, left, j, compare);  // когда i больше j для левой части массива
    myqsort(arr, i, right, compare); // аналогично для правой части массива
}

void getwords(const char *stroka, const char *delims, char **arrwords, size_t size, size_t &words)
{
    size_t length = strlen(stroka);
    char *copystr = new char[length];
    strcpy(copystr, stroka);
    words = 0;
    char *token = strtok(copystr, delims);
    while (token != NULL)
    {
        bool digit = false;
        for (int i = 0; token[i] != '\0'; ++i)
        {
            if (isdigit((unsigned char)(token[i])))
            {
                digit = true;
                break;
            }
        }
        if (!digit)
        {
            arrwords[words] = token;
            ++words;
        }
        token = strtok(NULL, delims);
    }
}

template <class T>
bool wordscompare(const T &word1, const T &word2)
{
    size_t length1 = strlen(word1);
    size_t length2 = strlen(word2);
    size_t i = 0;
    while (word1[i] != '\0' && word2[i] != '\0')
    {
        unsigned char a = (unsigned char)word1[i];
        unsigned char b = (unsigned char)word2[i];
        if (a != b)
        {
            return a < b;
        }
        ++i;
    }
    return length1 < length2;
}

int leftchild(int index) // индекс левого потомка
{
    return 2 * index + 1;
}
int rightchild(int index) // индекс правого потомка
{
    return 2 * index + 2;
}
template <class T>
void heapify(T *arr, size_t size, int root, bool (*compare)(const T &a, const T &b))
{
    int left = leftchild(root);
    int right = rightchild(root);
    int largest = root;
    if (left < size && compare(arr[largest], arr[left]))
    {
        largest = left;
    }
    if (right < size && compare(arr[largest], arr[right]))
    {
        largest = right;
    }
    if (largest != root)
    {
        std::swap(arr[root], arr[largest]);
        heapify(arr, size, largest, compare);
    }
}
template <class T>
void heap_build(T *arr, size_t size, bool (*compare)(const T &a, const T &b))
{
    for (int i = (size / 2) - 1; i >= 0; --i) // последняя нелистовая вершина
    {
        heapify(arr, size, i, compare);
    }
}
template <class T>
void heap_sort(T *arr, size_t size, bool (*compare)(const T &a, const T &b))
{
    heap_build(arr, size, compare);
    for (int i = size - 1; i > 0; --i)
    {
        std::swap(arr[i], arr[0]);
        heapify(arr, i, 0, compare);
    }
}

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
bool isempty(Stack<T> &s)
{
    return s.top == 0;
}
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
    T drop = s.top->data;
    Node<T> *ptr = s.top->next;
    delete s.top;
    s.top = ptr;
    return drop;
}

int main()
{
    const char *stroka = " I was born on the 21st of july in the 1488 year ";
    int size = strlen(stroka) + 1;
    const char *delims = " ,";
    int *arrdigits = new int[size];
    size_t found_elements = 0;
    getnumbers(stroka, arrdigits, size, found_elements);
    std::cout << " Your digits " << '\n';
    printarr(arrdigits, found_elements);

    int left = 0;
    int right = size - 1;

    if (found_elements > 0)
    {
        myqsort(arrdigits, 0, found_elements - 1, evencomparison);
        std::cout << " Sorted digits: " << '\n';
        printarr(arrdigits, found_elements);
    }

    char **arrwords = new char *[size];
    size_t found_words = 0;
    getwords(stroka, delims, arrwords, size, found_words);
    std::cout << " Your words: " << '\n';
    printarr(arrwords, found_words);

    if (found_words > 0)
    {
        heap_sort(arrwords, found_words, wordscompare);
        std::cout << " Your sorted words: " << '\n';
        printarr(arrwords, found_words);
    }

    Stack<char *> queue;
    for (int i = 0; i < found_words; ++i)
    {
        push(queue, arrwords[i]);
    }
    std::cout << " Your words from queue: " << '\n';
    while (!isempty(queue))
    {
        std::cout << pop(queue) << '\n';
    }

    delete[] arrdigits;
    delete[] arrwords;
    return 0;
}