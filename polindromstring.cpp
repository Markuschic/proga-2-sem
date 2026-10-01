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

void fillbuf(char **bufer, int sizebuf, char *copystr, char *string, const char *delim)
{
    strcpy(copystr, string);
    char *token = strtok(copystr, delim);
    for (int i = 0; token != NULL; ++i)
    {
        bufer[i] = token;
        token = strtok(NULL, delim);
    }
}

void print(char **bufer, int sizebuf)
{
    std::cout << " Your bufer: " << '\n';
    for (int i = 0; i < sizebuf; ++i)
    {
        std::cout << bufer[i] << '\n';
    }
}

void wordsreverse(char *token)
{
    size_t size = strlen(token);
    for (int i = 0, j = size - 1; i < size / 2; ++i, --j)
    {
        std::swap(token[i], token[j]);
    }
}

void swapwords(char **bufer, int sizebuf)
{
    for (int i = 0, j = sizebuf - 1; i < sizebuf / 2; ++i, --j)
    {
        std::swap(bufer[i], bufer[j]);
    }
}

char *detectpolindroms(char *token)
{
    size_t size = strlen(token);
    for (int i = 0; i < size / 2; ++i)
    {
        if (token[i] != token[size - i - 1])
        {
            return NULL;
        }
    }
    return token;
}

void printpolindroms(char **bufer, int sizebuf)
{
    for (int i = 0; i < sizebuf; ++i)
    {
        char *palindrome = detectpolindroms(bufer[i]);
        if (palindrome != NULL)
        {
            std::cout << " Слово " << palindrome << " с индекском " << i << " является палиндромом " << '\n';
        }
    }
}
void swappolindorms(char **bufer, int sizebuf)
{
    int max1 = 0;
    int max2 = 0;
    for (int i = 1; i < sizebuf; ++i)
    {
        if (strlen(bufer[i]) > strlen(bufer[max1]))
        {
            max2 = max1;
            max1 = i;
        }
        else if (strlen(bufer[i]) > strlen(bufer[max2]))
        {
            max2 = i;
        }
    }
    if (max1 != max2)
    {
        std::swap(bufer[max1], bufer[max2]);
    }
}

int main()
{
    char string[1000] = " Mark with level in the racecar ";
    char *copystr = new char[strlen(string) + 1];
    const char *delim = " ,";
    int sizebuf = wordscount(string, copystr, delim);
    char **bufer = new char *[sizebuf];
    fillbuf(bufer, sizebuf, copystr, string, delim);
    print(bufer, sizebuf);
    for (int i = 0; i < sizebuf; ++i)
    {
        wordsreverse(bufer[i]);
    }
    printpolindroms(bufer, sizebuf);
    swappolindorms(bufer, sizebuf);
    print(bufer, sizebuf);
    delete[] bufer;
    return 0;
}