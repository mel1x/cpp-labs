#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>

using std::wcin;
using std::wcout;
using mix::input;
using mix::print;
using mix::formatBool;

bool sum3(int x, int y, int z) {
    return (x + y == z) || (x + z == y) || (y + z == x);
}

int main() {
    mix::setRuLocale();
    int nums[3];

    for (int i = 0;i < 3;i++) {
        int num = input<int>(L"Введите число ");
        nums[i] = num;
    }

    print(L"Можно ли получить одни из чисел, суммируя два остальных");
    print(L"Результат:", formatBool(sum3(nums[0], nums[1], nums[2])));
}