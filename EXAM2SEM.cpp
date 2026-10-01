#include <iostream>

int wordscount(const char *stroka, const char *delims, char *copystr, size_t counter = 0)
{
    strcpy(copystr, stroka);
    char *token = strtok(copystr, delims);
    while (token != NULL)
    {
        ++counter;
        token = strtok(NULL, delims);
    }
    return counter;
}

void fillbuf(const char *stroka, const char *delims, char *copystr, size_t sizebuf, char **bufer)
{
    strcpy(copystr, stroka);
    char *token = strtok(copystr, delims);
    for (int i = 0; i < sizebuf && token != NULL; ++i)
    {
        bufer[i] = token;
        token = strtok(NULL, delims);
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
        if (strlen(bufer[i]) >= strlen(bufer[maxword]))
        {
            maxword = i;
        }
    }
    return bufer[maxword];
}

bool checkanagrams(char *word1, char *word2)
{
    size_t length1 = strlen(word1);
    size_t length2 = strlen(word2);
    if (length1 != length2)
    {
        return false;
    }
    int counter[256] = {0}; // тк в таблице аски 256 символов
    for (int i = 0; i < length1; ++i)
    {
        ++counter[std::tolower((unsigned char)word1[i])];
    }
    for (int i = 0; i < length2; ++i)
    {
        --counter[std::tolower((unsigned char)word2[i])];
    }
    for (int i = 0; i < 256; ++i)
    {
        if (counter[i] != 0)
        {
            return false;
        }
    }
    return true;
}

void printanagrams(char **bufer, size_t sizebuf, const char *stroka)
{
    for (int i = 0; i < sizebuf; ++i)
    {
        for (int j = i + 1; j < sizebuf; ++j)
        {
            if (checkanagrams(bufer[i], bufer[j]))
            {
                std::cout << " Words " << bufer[i] << " and " << bufer[j] << " are anagrams " << '\n';
            }
        }
    }
}

void myreverse(char *word)
{
    size_t length = strlen(word);
    for (int i = 0, j = length - 1; i < length / 2; ++i, --j)
    {
        std::swap(word[i], word[j]);
    }
    std::cout << word << '\n';
}

int main()
{
    int size;
    std::cout << " Enter the size " << '\n';
    std::cin >> size;
    std::cin.ignore();

    char *stroka = new char[size];
    const char delims[] = " ,!";
    std::cout << " Enter the string " << '\n';
    std::cin.getline(stroka, size);

    size_t slength = strlen(stroka);
    char *copystr = new char[slength + 1];

    size_t sizebuf = wordscount(stroka, delims, copystr);
    char **bufer = new char *[sizebuf];
    fillbuf(stroka, delims, copystr, sizebuf, bufer);
    printbuf(bufer, sizebuf);
    std::cout << " Longest word: " << longestword(bufer, sizebuf) << '\n';
    printanagrams(bufer, sizebuf, stroka);
    // for (int i = 0; i < sizebuf; ++i)
    // {
    //     myreverse(bufer[i]);
    // }

    delete[] stroka;
    delete[] copystr;
    delete[] bufer;
    return 0;
}