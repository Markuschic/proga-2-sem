#include <iostream>
#include <string>

int wordscount(const char *delim, char *copystr, char *token, int counter = 0)
{
    while (token != NULL)
    {
        ++counter;
        token = strtok(NULL, delim);
    }
    return counter;
}

void fillbuf(char **bufer, int sizebuf, char *copystr, char *str, const char *delim)
{
    strcpy(copystr, str);
    char *token = strtok(copystr, delim);
    for (int i = 0; i < sizebuf; ++i)
    {
        bufer[i] = token;
        token = strtok(NULL, delim);
    }
}

void printbuf(char **bufer, int sizebuf)
{
    for (int i = 0; i < sizebuf; ++i)
    {
        std::cout << bufer[i] << '\n';
    }
}

bool checkanagrams(char *token1, char *token2)
{
    size_t lentok1 = strlen(token1);
    size_t lentok2 = strlen(token2);
    if (lentok1 != lentok2)
    {
        return false;
    }

    size_t counter[256]{0}; // тк всего 256 символов в таблице аски
    for (int i = 0; i < lentok1; ++i)
    {
        ++counter[token1[i]];
    }

    for (int i = 0; i < lentok2; ++i)
    {
        --counter[token2[i]];
    }

    for (int i = 0; i < 256; ++i)
    {
        if (counter[i] != 0)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    char str[1000] = " we always want tawn and bal with alb  ";
    const char *delim = " ,";
    char *copystr = new char[strlen(str) + 1];
    strcpy(copystr, str);
    char *token = strtok(copystr, delim);
    size_t lentok = strlen(token);
    int sizebuf = wordscount(str, copystr, token);
    char **bufer = new char *[sizebuf];
    fillbuf(bufer, sizebuf, copystr, str, delim);
    printbuf(bufer, sizebuf);
    for (int i = 0; i < sizebuf - 1; ++i)
    {
        if (checkanagrams(bufer[i], bufer[i + 1]))
        {
            std::cout << " Word " << bufer[i] << " and " << bufer[i + 1] << " are anagrams " << '\n';
        }
    }
    return 0;
}

//  найти самое длинное слово в строке и вывести его