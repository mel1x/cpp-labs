#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>

using std::list;
using std::vector;
using mix::input;
using mix::print;

void computeAverage(const list<int>& L) {
    vector<double> V;
    
    std::adjacent_difference(L.begin(), L.end(), std::back_inserter(V), 
                             [](int a, int b) { return (a + b) / 2.0; });
    V.erase(V.begin());
    
    print(L"Вектор V, содержащий среднее арифметическое для всех пар соседних элементов: ");
    for (const auto& el : V) {
        std::wcout << el << L" ";
    }
    std::wcout << std::endl;
}

int main() {
    mix::setRuLocale();

    int n = input<ushort>(L"Введите количество элементов списка L: ");
    list<int> L;

    print(L"Введите элементы списка L: ");
    for (int i = 0; i < n; ++i) {
        int el = input<int>(L"Введите элемент: ");
        L.push_back(el);
    }

    print(L"Исходный список L: ");
    for (const auto& el : L) {
        std::wcout << el << L" ";
    }
    std::wcout << std::endl;


    computeAverage(L);
    return 0;
}