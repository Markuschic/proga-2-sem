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

void fillbuf(char **bufer, char *string, char *copystr, const char *delim)
{
    strcpy(copystr, string); // восстановим строку
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
    for (int i = 0; i < sizebuf; ++i)
    {
        std::cout << bufer[i] << '\n';
    }
}

void sortingwords(char **bufer, int sizebuf)
{
    bool flag = true;
    while (flag == true)
    {
        flag = false;
        for (int i = 0; i < sizebuf - 1; ++i)
        {
            if (strcmp(bufer[i], bufer[i + 1]) > 0) // сравниваем по возрастанию
            {
                std::swap(bufer[i], bufer[i + 1]);
                flag = true;
            }
        }
    }
    std::cout << " Ваши отсортированные слова: " << '\n';
    for (int i = 0; i < sizebuf; ++i)
    {
        std::cout << bufer[i] << '\n';
    }
}

int main()
{
    char string[100] = " banana, watermelon, orange, apple, grape ";
    const char delim[] = " ,";
    char *copystr = new char[strlen(string) + 1];
    int sizebuf = wordscount(string, copystr, delim);
    char **bufer = new char *[sizebuf];
    std::cout << " Всего слов: " << wordscount(string, copystr, delim) << '\n';
    fillbuf(bufer, string, copystr, delim);
    print(bufer, sizebuf);
    sortingwords(bufer, sizebuf);

    return 0;
}