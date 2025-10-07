#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

using std::vector;
using mix::input;
using mix::print;
using std::partial_sort;
using std::greater;

void printLastThree(vector<int>& V) {
    partial_sort(V.begin(), V.begin() + 3, V.end(), greater<int>());
    
    print(L"Три наибольших элемента вектора в порядке убывания: ");
    std::copy(V.begin(), V.begin() + 3, std::ostream_iterator<int, wchar_t>(std::wcout, L" "));
    std::wcout << std::endl;
}

int main() {
    mix::setRuLocale();
    
    int n = input<int>(L"Введите количество элементов вектора V (не менее 3): ");
    vector<int> V(n);
    
    print(L"Введите элементы вектора V: ");
    for (int i = 0; i < n; ++i) {
        V[i] = input<int>(L"Введите элемент вектора: ");
    }
    
    print(L"Исходный вектор V: ");
    for (const auto& el : V) {
        std::wcout << el << L" ";
    }
    std::wcout << std::endl;
    
    printLastThree(V);
    return 0;
}