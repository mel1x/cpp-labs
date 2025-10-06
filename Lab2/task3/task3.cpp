#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>
#include <deque>

using std::wcin;
using std::wcout;
using mix::input;
using mix::print;
using std::deque;

deque<int>& removeMid(deque<int>& Deck) {
    deque<int>::iterator mid = Deck.begin() + Deck.size() / 2;
    Deck.erase(mid);
    
    return Deck;
}

int main() {
    mix::setRuLocale();

    int N = input<int>(L"Введите количество элементов (нечетное число, N ≥ 3)");
    if (N % 2 == 0 or N < 3) {
        print(L"Количество элементов должно быть нечётным и ≥3!");
        return 1;
    }

    deque<int> Deck;
    print(L"Введите ", N, L" целых чисел:");
    for (int i = 0; i < N; ++i) {
        int num = input<int>(L"Введите число");
        Deck.push_back(num);
    }

    deque<int> newDeck = removeMid(Deck);

    print(L"Измененный дек:");
    for (const auto& num : newDeck) {
        wcout << num << L" ";
    }
    wcout << std::endl;

    return 0;
}
