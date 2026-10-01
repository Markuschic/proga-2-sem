#include <iostream>

int wordscount(char *string, char *copystr, const char *delim, int counter = 0)
{
    strcpy(copystr, string);
    char *token = strtok(copystr, delim);
    while (token != NULL)
    {
        ++counter;
        token = strtok(NULL, delim);
    }
    return counter;
}

void fillbuf(char **bufer, const char *delim, char *copystr, char *string)
{
    strcpy(copystr, string); // восстановил строку
    char *token = strtok(copystr, delim);
    for (int i = 0; token != NULL; ++i)
    {
        bufer[i] = token;
        strcpy(bufer[i], token);
        token = strtok(NULL, delim);
    }
}

void print(char **bufer, int sizebuf)
{
    std::cout << " Your words " << '\n';
    for (int i = 0; i < sizebuf; ++i)
    {
        std::cout << bufer[i] << '\n';
    }
}

void swapwords(char **bufer, int sizebuf)
{
    for (int i = 0, j = sizebuf - 1; i < sizebuf / 2; ++i, --j)
    {
        std::swap(bufer[i], bufer[j]);
    }
}

void wordsreverse(char *token)
{
    int size = strlen(token);
    for (int i = 0, j = size - 1; i < size / 2; ++i, --j)
    {
        std::swap(token[i], token[j]);
    }
}

int main()
{
    int size;
    std::cout << " Enter the size of the string " << '\n';
    std::cin >> size;
    std::cin.ignore(); // после cin>>size в потоке остался '\n' а getline натыкается на него и сразу же завершается, не дожидаясь ввода

    char *mystring = new char[size];
    const char delim[] = " ,";
    std::cout << " Enter the string " << '\n';
    std::cin.getline(mystring, size);
    std::cout << " You entered: " << mystring << '\n';

    char *copystr = new char[strlen(mystring) + 1];
    size_t sizebuf = wordscount(mystring, copystr, delim);
    char **bufer = new char *[sizebuf];
    fillbuf(bufer, delim, copystr, mystring);
    print(bufer, sizebuf);
    for (int i = 0; i < sizebuf; ++i)
    {
        wordsreverse(bufer[i]);
    }
    swapwords(bufer, sizebuf);
    print(bufer, sizebuf);

    return 0;
}