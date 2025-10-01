#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>

using std::wcin;
using std::wcout;
using std::wstring;
using std::to_wstring;
using mix::input;
using mix::print;

wstring age(int x) {
    if (x == 11 or x == 12 or x == 13 or x == 14) return to_wstring(x) + L" лет";
    if ((x % 10 == 1)) return to_wstring(x) + L" год";
    if ((x % 10 == 2 or x % 10 == 3 or x % 10 == 4)) return to_wstring(x) + L" года";
    return to_wstring(x) + L" лет";
}

int main() {
    mix::setRuLocale();

    int x = input<int>(L"Введите ваш возраст");
    if (x < 1) {
        print(L"Вам точно больше!!!");
        return 0;
    }
    print(L"Вам", age(x));
}