#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>

using std::wcin;
using std::wcout;
using mix::input;
using mix::print;

double safeDiv(int x, int y) {
    if (y == 0) return 0.;
    return static_cast<double>(x) / y;
}

int main() {
    mix::setRuLocale();

    int x = input<int>(L"Введите 1 число");
    int y = input<int>(L"Введите 2 число");

    print(L"Результат безопасного деления:", safeDiv(x,y));
}