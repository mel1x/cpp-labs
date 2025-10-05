#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>
#include <sstream>

using mix::input;
using mix::print;
using std::wcin;
using std::wcout;
using std::wstring;
using std::wstringstream;

int* concat(int arr1[], int size1, int arr2[], int size2) {
    int* newArr = new int[size1 + size2];

    for (int i = 0; i < size1; i++) {
        newArr[i] = arr1[i];
    }

    for (int i = 0; i < size2; i++) {
        newArr[size1 + i] = arr2[i];
    }

    return newArr;
}

int main() {
    mix::setRuLocale();

    wcout << L"Введите элементы первого массива через пробел: ";
    wstring line1;
    std::getline(wcin, line1);

    int arr1[100];
    int size1 = 0;
    int num;
    wstringstream ss1(line1);
    while (ss1 >> num && size1 < 100) {
        arr1[size1++] = num;
    }

    wcout << L"Введите элементы второго массива через пробел: ";
    wstring line2;
    std::getline(wcin, line2);

    int arr2[100];
    int size2 = 0;
    wstringstream ss2(line2);
    while (ss2 >> num && size2 < 100) {
        arr2[size2++] = num;
    }

    int* result = concat(arr1, size1, arr2, size2);

    wcout << L"[";
    for (int i = 0; i < size1 + size2; i++) {
        wcout << result[i];
        if (i + 1 < size1 + size2) wcout << L", ";
    }
    wcout << L"]" << std::endl;

    delete[] result;
}