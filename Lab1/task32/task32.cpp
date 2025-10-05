#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>

using mix::input;
using mix::print;

int findLast(int arr[], int size, int x) {
    int index = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            index = i;
        }
    }

    return index;
}

int main() {
    mix::setRuLocale();

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int x = input<int>(L"Введите число для поиска: ");
    int result = findLast(arr, size, x);
    
    if (result == -1)
        print(L"Число не найдено в массиве.");
    else
        print(L"Последнее вхождение числа находится по индексу:", result);
}