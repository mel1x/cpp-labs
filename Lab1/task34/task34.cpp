#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>

using mix::input;
using mix::print;
using std::wcout;
using std::endl;
using std::to_wstring;

int* add(int arr[], int size, int x, int pos) {
    int* newArr = new int[size + 1];

    for (int i = 0, j = 0; i < size + 1; i++) {
        if (i == pos) {
            newArr[i] = x;
        } else {
            newArr[i] = arr[j];
            j++;
        }
    }

    return newArr;
}

int main() {
    mix::setRuLocale();

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int x = input<int>(L"Введите число для вставки: ");
    int pos = input<int>(L"Введите позицию вставки от 0 до " + to_wstring(size));
    if (pos > size) {
        print(L"Такой позиции нет!");
        return 0;
    }

    int* result = add(arr, size, x, pos);

    print(L"Новый массив:");
    wcout << L"[";
    for (int i = 0; i < size + 1; i++) {
        wcout << result[i];
        if (i + 1 < size + 1) wcout << L", ";
    }
    wcout << L"]" << endl;

    delete[] result;
}
