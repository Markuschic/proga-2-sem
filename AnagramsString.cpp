#include <iostream>

bool anagrams (char* string1, char* string2)
{
    size_t bufer[256] {0};
    while (*string1 != '\0')
    {
        ++bufer[(unsigned char)(*string1++)];
    }
    while (*string2 != '\0')
    {
        --bufer[(unsigned char)(*string2++)];
    }
    for (int i = 0; i < 256; ++i)
    {
        if (bufer[i] != 0)
        {
            std::cout << " Words are not anagrams " << '\n';
            return false;
        }
    }
    std::cout << " Words are anagrams " << '\n';
    return true;
}

int main()
{
    char string1[1000] = " banana ";
    char string2[1000] = " anaban ";
    const char* delim = " ,";
    std::cout << anagrams (string1, string2) << '\n';
    
    return 0;
}