#include <iostream>

int wordscount(char *str, const char *delim, char *copystr, size_t counter = 0)
{
    strcpy(copystr, str);
    char *token = strtok(copystr, delim);
    while (token != NULL)
    {
        ++counter;
        token = strtok(NULL, delim);
    }
    return counter;
}

void fillbuf(char **bufer, size_t sizebuf, char *copystr, char *str, const char *delim)
{
    strcpy(copystr, str);
    char *token = strtok(copystr, delim);
    while (token != NULL)
    {
        for (int i = 0; i < sizebuf; ++i)
        {
            bufer[i] = token;
            token = strtok(NULL, delim);
        }
    }
}

void printbuf(char **bufer, size_t sizebuf)
{
    for (int i = 0; i < sizebuf; ++i)
    {
        std::cout << bufer[i] << '\n';
    }
}

char *longestword(char **bufer, size_t sizebuf)
{
    size_t maxword = 0;
    for (int i = 1; i < sizebuf; ++i)
    {
        if (strlen(bufer[i]) > strlen(bufer[maxword]))
        {
            maxword = i;
        }
    }
    return bufer[maxword];
}

int main()
{
    char str[1000] = " Mum and dad are driving to the mall to buy a new playstation game ";
    const char *delim = " ,";
    char *copystr = new char[strlen(str) + 1];
    size_t sizebuf = wordscount(str, delim, copystr);
    char **bufer = new char *[sizebuf];
    fillbuf(bufer, sizebuf, copystr, str, delim);
    printbuf(bufer, sizebuf);
    std::cout << " The biggest word int the string is " << longestword(bufer, sizebuf) << '\n';
    return 0;
}