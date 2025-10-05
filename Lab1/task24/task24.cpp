#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>

using mix::input;
using mix::print;

int pow(int x, int y) {
    if (y < 0) return 0;

    int result = 1;
    for (int i = 0; i < y; i++) {
        result *= x;
    }

    return result;
}

int main() {
    mix::setRuLocale();

    int x = input<int>(L"Введите число: ");
    int y = input<int>(L"Введите степень: ");

    print(L"Результат:", pow(x, y));
}
