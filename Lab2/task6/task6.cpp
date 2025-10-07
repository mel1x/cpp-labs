#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>
#include <list>
#include <algorithm>

using std::list;
using std::wcout;
using mix::input;
using mix::print;
using std::rotate;
using std::next;

void rotateRight(list<int>& L1, int K) {
    if (L1.empty() || K == 0) return;
    K = K % L1.size();
    rotate(L1.rbegin(), next(L1.rbegin(), K), L1.rend());
}

void rotateLeft(list<int>& L2, int K) {
    if (L2.empty() || K == 0) return;
    K = K % L2.size();
    rotate(L2.begin(), next(L2.begin(), K), L2.end());
}

int main() {
    mix::setRuLocale();
    
    int K = input<int>(L"Введите количество сдвигов K (0 < K < 10): ");
   
    print(L"Введите 10 элементов для списка L1: ");
    list<int> L1;
    for (int i = 0; i < 10; ++i) {
        int el = input<int>(L"Введите элемент: ");
        L1.push_back(el);
    }
    
    print(L"Введите 10 элементов для списка L2: ");
    list<int> L2;
    for (int i = 0; i < 10; ++i) {
        int el = input<int>(L"Введите элемент: ");
        L2.push_back(el);
    }
    
    rotateRight(L1, K);
    rotateLeft(L2, K);
    
    print(L"\nИзмененный список L1 после сдвига вправо: ");
    for (const auto& el : L1) {
        wcout << el << L" ";
    }
    wcout << std::endl;
    
    print(L"Измененный список L2 после сдвига влево: ");
    for (const auto& el : L2) {
        wcout << el << L" ";
    }
    wcout << std::endl;
    
    return 0;
}