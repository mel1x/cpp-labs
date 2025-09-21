#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>

using std::wcin;
using std::wcout;
using mix::input;
using mix::print;

int main() {
    mix::setRuLocale();

    int x = input<int>();
    print(L"Вы ввели:", x);
}