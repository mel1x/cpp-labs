#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std::vector;
using std::list;
using mix::input;
using mix::print;

void duplicateLastMatch(vector<int>& V, list<int>& L) {
    vector<int> first_half(V.begin(), V.begin() + V.size() / 2);

    auto it = std::find_first_of(L.begin(), L.end(), first_half.begin(), first_half.end());

    if (it != L.end()) {
        auto last_match = it;

        for (; it != L.end(); ++it) {
            if (std::find(first_half.begin(), first_half.end(), *it) != first_half.end()) {
                last_match = it;
            }
        }

        L.insert(std::next(last_match), *last_match);
    }
}

int main() {
    mix::setRuLocale();

    int n = input<ushort>(L"Введите количество элементов вектора V (чётное): ");
    while (n%2 != 0) {
        print(L"Количество вектора должно быть чётным!");
        n = input<int>(L"Введите количество элементов вектора V (чётное): ");
    }
    vector<int> V(n);
    print(L"Введите элементы вектора V: ");
    for (int i = 0; i < n; ++i) {
        V[i] = input<int>(L"Введите элемент вектора: ");
    }

    int m = input<ushort>(L"Введите количество элементов списка L: ");
    list<int> L;
    print(L"Введите элементы списка L: ");
    for (int i = 0; i < m; ++i) {
        int temp = input<int>(L"Введите элемент списка: ");
        L.push_back(temp);
    }

    
    duplicateLastMatch(V, L);

    print(L"\nИзмененный список L: ");
    for (const auto& el : L) {
        std::wcout << el << L" ";
    }
    std::wcout << std::endl;

    return 0;
}
