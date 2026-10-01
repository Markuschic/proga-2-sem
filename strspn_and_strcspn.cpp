#include <iostream>

size_t wordsnumber(char *string, const char *delim, size_t counter = 0)
{
    while (string != NULL & *string != '\0')
    {
        string += strspn(string, delim);
        string += strcspn(string, delim);
        if (*string == '\0')
        {
            break;
        }
        ++counter;
    }
    return counter;
}

int main()
{
    char string[1000] = " Mum washed the house ";
    const char *delim = " ,";
    std::cout << " Amount of words is " << wordsnumber(string, delim) << '\n';
    return 0;
}