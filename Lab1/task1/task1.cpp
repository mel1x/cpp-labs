#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>
#include <string>

using std::wcin;
using std::wcout;
using mix::input;
using mix::print;
using mix::formatBool;

bool isUpperCase(wchar_t x) {
    int charCode{ static_cast<int>(x) };

    if (charCode >= 65 and charCode <= 90) {
        return true;
    }
    else if (charCode >= 1040 and charCode <= 1071) {
        return true;
    }
    else if (charCode == 1025) {
        return true;
    }
    
    return false;
}

int main() {
    mix::setRuLocale();

    wchar_t x = input<wchar_t>(L"Введите символ");
    print(L"Результат:", formatBool(isUpperCase(x)));
}