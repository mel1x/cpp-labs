#include <iostream>
#include "mixUtils.hpp"

using std::wcin;
using std::wcout;
using mix::input;
using mix::print;

int main() {
    mix::setRuLocale();

    int x = input<int>();
    print(L"Вы ввели:", x);
}