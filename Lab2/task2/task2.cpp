#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>
#include <vector>

using std::wcin;
using std::wcout;
using mix::input;
using mix::print;
using std::vector;

vector<int>& formatVector(vector<int>& V) {
    for (auto i = V.begin(); i != V.end(); ++i) {
        i = V.insert(++i, 1);
    }
    return V;
}

int main() {
    mix::setRuLocale();

    vector<int> V;
    int len = input<ushort>(L"Введите количество элементов вектора");

    print(L"Введите", len, L"целых чисел:");
    for (int i = 0; i < len; ++i) {
        int num = input<int>(L"Введите число");
        V.push_back(num);
    }

    vector<int> newV = formatVector(V);

    print(L"Измененный вектор:");
    for (const auto& num : newV) {
        wcout << num << L" ";
    }
    wcout << std::endl;

    return 0;
}
