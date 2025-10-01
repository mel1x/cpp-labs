#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>

using std::wcin;
using std::wcout;
using mix::input;
using mix::print;

void printDays(int x) {
    switch (x) {
        case 1: print(L"Понедельник");
        case 2: print(L"Вторник");
        case 3: print(L"Среда");
        case 4: print(L"Четверг");
        case 5: print(L"Пятница");
        case 6: print(L"Суббота");
        case 7: print(L"Воскресенье"); break;
        default:
            print(L"Это не день недели");
    }
}

int main() {
    mix::setRuLocale();

    int day = input<int>(L"Введите номер дня недели (1-7): ");
    printDays(day);
}