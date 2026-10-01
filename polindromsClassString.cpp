#include <iostream>
#include <string>

void strcheck(std::string &stroka)
{
    if (stroka.empty())
    {
        std::cout << " Your string is empty " << '\n';
    }
}

size_t wordscounter(std::string &stroka, std::string delim, size_t counter = 0)
{
    size_t index = 0;
    size_t npos = std::string::npos;
    while (index < stroka.size())
    {
        index = stroka.find_first_not_of(delim, index); // пропускаем разделители идем до первой буквы
        if (index == npos)
        {
            break;
        }
        ++counter;
        index = stroka.find_first_of(delim, index); // ищем первый разделитель
        if (index == npos)
        {
            break;
        }
        ++index;
    }
    return counter;
}

void fillbuf(std::string *bufer, size_t bufsize, std::string stroka, std::string &delim, size_t index = 0)
{
    size_t wordIndex = 0;
    size_t npos = std::string::npos;
    for (int i = 0; i < bufsize; ++i)
    {
        size_t begin = stroka.find_first_not_of(delim, index);
        if (begin == npos)
        {
            break;
        }
        size_t end = stroka.find_first_of(delim, begin);
        size_t wordlen = begin - end;
        bufer[wordIndex] = stroka.substr(index, end - index);
        ++wordIndex;
        index = end + 1;
    }
}

void printbuf(std::string *bufer, size_t bufsize)
{
    for (int i = 0; i < bufsize; ++i)
    {
        std::cout << bufer[i] << '\t';
    }
}

bool detectpolindroms(std::string &word)
{
    size_t wordsize = word.size();
    for (int i = 0; i < wordsize / 2; ++i)
    {
        if (word[i] != word[wordsize - i - 1])
        {
            return false;
        }
    }
    return true;
}

void printpolindroms(std::string *bufer, size_t bufsize)
{
    for (int i = 0; i < bufsize; ++i)
    {
        if (detectpolindroms(bufer[i]))
        {
            std::cout << " Слово " << bufer[i] << " с индексом " << i << " является полиндромом " << '\n';
        }
    }
}

int main()
{
    std::string stroka = "The tactical radar detected a fast racecar while the civic leader used a kayak to cross the river.";
    strcheck(stroka);
    std::string delim = " ,";
    size_t bufsize = wordscounter(stroka, delim);
    std::string *bufer = new std::string[bufsize];
    fillbuf(bufer, bufsize, stroka, delim);
    printbuf(bufer, bufsize);
    printpolindroms(bufer, bufsize);
    delete[] bufer;
    return 0;
}
