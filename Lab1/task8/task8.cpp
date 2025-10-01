#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>

using std::wcin;
using std::wcout;
using mix::input;
using mix::print;

bool isDivisor(int a, int b) {
    if (a == 0 or b == 0) {
        return false;
    }
    if (a%b == 0 or b%a == 0) return true;
    
    return false;
}

int main() {
    mix::setRuLocale();

    int x = input<int>(L"Введите 1 число");
    int y = input<int>(L"Введите 2 число");
    
    print(L"Делится ли одно число на другое:", mix::formatBool(isDivisor(x,y)));
}