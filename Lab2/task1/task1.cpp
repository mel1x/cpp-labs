#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>
#include <deque>

using std::wcin;
using std::wcout;
using mix::input;
using mix::print;
using std::deque;

void printSides(deque<int> Deck, int len) {
    deque<int>::reverse_iterator rit = Deck.rbegin();

    print(L"Первая половина в обратном порядке:");
    for (; rit != Deck.rbegin() + len / 2; ++rit) {
        wcout << *rit << L" ";
    }
    wcout << std::endl;

    print(L"Вторая половина в обратном порядке:");
    for (; rit != Deck.rend(); ++rit) {
        wcout << *rit << L" ";
    }
    wcout << std::endl;
}

int main() {
    mix::setRuLocale();

    int len = input<int>(L"Введите количество элементов (четное число)");
    while (len % 2 != 0) {
        print(L"Число должно быть четным. Попробуйте снова.");
        len = input<int>(L"Введите количество элементов (четное)");
    }

    deque<int> Deck;
    print(L"Введите ", len, L" целых чисел:");
    for (int i = 0; i < len; ++i) {
        int num = input<int>(L"Введите число");
        Deck.push_back(num);
    }

    printSides(Deck, len);
}