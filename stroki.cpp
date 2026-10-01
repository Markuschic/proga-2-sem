#include <iostream>

int main()
{
   char name[100];
   std::cout << " Enter the name " << '\n';
   std::cin.getline ( name , 100 );
   std::cout << " You entered " << name << '\n';
   return 0;
}