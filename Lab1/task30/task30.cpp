#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>
#include <cstdlib>

using mix::input;
using mix::print;
using std::rand;

void guessGame() {
    int secret = rand() % 10;
    int attempts = 0;
    int guess;

    while (true) {
        guess = input<int>(L"Введите число от 0 до 9: ");
        attempts++;

        if (guess == secret) {
            print(L"Вы угадали!");
            print(L"Вы отгадали число за", attempts, L"попыток(и)");
            break;
        } else {
            print(L"Неверно, попробуйте ещё раз!");
        }
    }
}

int main() {
    mix::setRuLocale();
    guessGame();
}
