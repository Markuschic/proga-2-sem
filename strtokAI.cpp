#include <iostream>
#include <cstring>  // для strchr

char* my_strtok(char* str, const char* delim) {
    static char* next_token = nullptr;  // запоминаем, где остановились
    
    // Если передали новый указатель, начинаем с него
    if (str != nullptr) {
        next_token = str;
    }
    
    // Если нечего обрабатывать
    if (next_token == nullptr || *next_token == '\0') {
        return nullptr;
    }
    
    // Пропускаем разделители в начале
    while (*next_token && strchr(delim, *next_token)) {
        next_token++;
    }
    
    // Если строка закончилась
    if (*next_token == '\0') {
        return nullptr;
    }
    
    // Нашли начало токена
    char* token_start = next_token;
    
    // Ищем конец токена (до разделителя или конца строки)
    while (*next_token && !strchr(delim, *next_token)) {
        next_token++;
    }
    
    // Если нашли разделитель, заменяем его на '\0'
    if (*next_token) {
        *next_token = '\0';
        next_token++;  // переходим к следующему символу
    }
    
    return token_start;
}

int main() {
    char str[] = "Hello,world,this,is,test";
    char delim[] = ",";
    
    char* token = my_strtok(str, delim);
    while (token != nullptr) {
        std::cout << token << std::endl;
        token = my_strtok(nullptr, delim);
    }
    
    return 0;
}