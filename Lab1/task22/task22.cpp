#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>

using std::wcin;
using std::wcout;
using mix::input;
using mix::print;
using std::wstring;
using std::to_wstring;

wstring reverseListNums(int x) {
    wstring result = L"";
    
    if (x == 0) return L"";
    if (x > 0) {
        for (int i = x; i >= 0; --i) {
            result += to_wstring(i);
            if (i != 0) result += L" ";
        }
    } else {
        for (int i = x; i <= 0; ++i) {
            result += to_wstring(i);
            if (i != 0) result += L" ";
        }
    }

    return result;
}


int main() {
    mix::setRuLocale();

    int len = input<int>(L"Введите длинну списка: ");
    print(L"Обратный список:", reverseListNums(len));
}