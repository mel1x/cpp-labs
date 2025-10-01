#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>

using std::wcin;
using std::wcout;
using mix::input;
using mix::print;

int sumLastNums(int x) {
    return abs(x%10 + (x/10)%10);
}

int main() {
    mix::setRuLocale();

    int x = input<int>(L"Введите число");
    if (abs(x) < 10) {
        print(L"Число должно иметь хотя бы 2 знака!");
        return 0;
    }

    print(L"Результат сложения последних знаков: ", sumLastNums(x));
}