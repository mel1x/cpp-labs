#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>

using std::wcin;
using std::wcout;
using mix::input;
using mix::print;

int lastNumSum(int a, int b) {
    return abs(a%10) + abs(b%10);
}

int main() {
    mix::setRuLocale();

    int nums[5];
    for (int i = 0; i < 5; i++) {
        nums[i] = input<int>(L"Введите число " + std::to_wstring(i + 1) + L": ");
    }

    int res = nums[0];

    for (int i = 1; i < 5; i++) {
        int prev = res;
        res = lastNumSum(res, nums[i]);
        print(prev, L"+", nums[i], L"это", res);
    }

    print(L"Итого", res);
}