#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>

using std::wcin;
using std::wcout;
using mix::input;
using mix::print;

bool isPositive(int x) {
    return x>0;
}

int main() {
    mix::setRuLocale();

    int x = input<int>(L"Введите число");
    print(L"Положительное ли число:", mix::formatBool(isPositive(x)));
}