#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>
#include <string>

using std::wcin;
using std::wcout;
using std::wstring;
using std::to_wstring;
using mix::input;
using mix::print;

wstring makeDecision(int x, int y) {
    if (x < y) {
        return to_wstring(x) + L"<"  + to_wstring(y);
    } else if (x > y) {
        return to_wstring(x) + L">"  + to_wstring(y);
    } else {
        return to_wstring(x) + L"==" + to_wstring(y);
    }
}

int main() {
    mix::setRuLocale();

    int x = input<int>(L"Введите 1 число");
    int y = input<int>(L"Введите 2 число");

    print(L"Результат:", makeDecision(x,y));
}