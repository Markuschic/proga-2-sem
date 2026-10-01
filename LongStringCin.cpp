#include <iostream>

int main()
{
    std::string s;
    std::cout << " Enter str " << '\n';
    std::getline(std::cin, s, '$');       // Если вводится длинная строка, занимающая несколько строк ввода, в getline указывается третий параметр – символ, определяющий конец ввода строки.
    std::cout << s << '\n';
    return 0;
}
