#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>

using mix::input;
using mix::print;
using std::wcout;
using std::endl;

void leftTriangle(int x) {
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= i; j++) {
            wcout << L"*";
        }
        wcout << endl;
    }
}

int main() {
    mix::setRuLocale();

    int height = input<int>(L"Введите высоту треугольника: ");
    print(L"Левый треугольник:");
    leftTriangle(height);
}