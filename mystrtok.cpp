#include <iostream>

char* mystrtok ( char* string, const char* delim )
{
    static char* newtoken = NULL;
    if ( string != NULL )
    {
        newtoken = string;
    }
    if ( newtoken == NULL || *newtoken == '\0' )
    {
        return NULL;
    }
    while ( *newtoken && strchr( delim, *newtoken ) )
    {
        ++newtoken;
    }
    char* begintoken = newtoken;
    while ( *newtoken && !strchr( delim, *newtoken ) )
    {
        ++newtoken;
    }
    if ( *newtoken )
    {
        *newtoken = '\0';
        ++newtoken;
    }
    return begintoken;
}

int main()
{
    char string[100] = " Apple, orange, banana ";
    char delim[] = " !,";
    char* token = mystrtok ( string, delim );
    while ( token != NULL )
    {
    std::cout << token << '\n';
    token = mystrtok ( NULL, delim );
    } 
    return 0;
}