#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>
#include <sstream>

using mix::input;
using mix::print;
using std::wcin;
using std::wcout;
using std::wstring;
using std::wstringstream;

int* deleteNegative(int arr[], int size, int& newSize) {
    newSize = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 0)
            newSize++;
    }
    
    int* newArr = new int[newSize];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 0) {
            newArr[j++] = arr[i];
        }
    }

    return newArr;
}

int main() {
    mix::setRuLocale();

    wcout << L"Введите элементы массива через пробел: ";
    wstring line;
    std::getline(wcin, line);

    int arr[100];
    int size = 0;
    int num;
    wstringstream ss(line);
    while (ss >> num && size < 100) {
        arr[size++] = num;
    }

    int newSize = 0;
    int* result = deleteNegative(arr, size, newSize);

    wcout << L"[";
    for (int i = 0; i < newSize; i++) {
        wcout << result[i];
        if (i + 1 < newSize) wcout << L", ";
    }
    wcout << L"]" << std::endl;

    delete[] result;
}
