#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>

using std::wcin;
using std::wcout;
using mix::input;
using mix::print;
using mix::formatBool;

bool equalNum(int x) {
    if (x < 0) x = -x;

    int lastDigit = x % 10;
    while (x > 0) {
        if (x % 10 != lastDigit) {
            return false;
        }
        x /= 10;
    }
    return true;
}

int main() {
    mix::setRuLocale();

    int x = input<int>(L"Введите число");
    print(L"Результат:", formatBool(equalNum(x)));
}