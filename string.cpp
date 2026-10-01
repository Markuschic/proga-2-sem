#include <iostream>
int main()
{
    char mystr1[100] = " Apple And Banana ";
    char mystr2[100] = " apple and banana ";
    char delim[] = " !,";
    char *token1 = strtok(mystr1, delim);
    while (token1 != NULL)
    {
        std::cout << token1 << '\n';
        token1 = strtok(NULL, delim);
    }
    std::cout << '\n';
    char *token2 = strtok(mystr2, delim);
    while (token2 != NULL)
    {
        std::cout << token2 << '\n';
        token2 = strtok(NULL, delim);
    }
    std::cout << strcmp(mystr1, mystr2) << '\n';

    /*
    char* delim = " !,";
    char* token = strtok(string1, delim);
    while ( token != NULL )
    {
        std::cout << token << '\n';
        token = strtok ( NULL, delim );
    }
    */
    return 0;
}