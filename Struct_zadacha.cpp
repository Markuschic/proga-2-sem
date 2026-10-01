#include <iostream>

struct Student
{
    size_t grades[5];
    size_t count{0};
    std::string name;
};

void isempty(Student &s)
{
}

void addgrade(Student &s, size_t newgrade)
{
    if (s.count > 5)
    {
        return;
    }
    s.grades[s.count] = newgrade;
    ++s.count;
}

float getaverage(Student &s)
{
    float sum = 0;
    for (size_t i = 0; i < 5; ++i)
    {
        sum += s.grades[i];
    }
    return sum / 5.0f;
}

int main()
{
    Student mystudent;
    addgrade(mystudent, 4);
    addgrade(mystudent, 6);
    addgrade(mystudent, 2);
    addgrade(mystudent, 9);
    addgrade(mystudent, 8);
    std::cout << getaverage(mystudent) << '\n';
    return 0;
}