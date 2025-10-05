#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>
#include <sstream>

using std::wcin;
using std::wcout;
using std::wstring;
using std::wstringstream;

void reverse(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        std::swap(arr[i], arr[size - i - 1]);
    }
}

int main() {
    mix::setRuLocale();

    wcout << L"Введите числа через пробел: ";
    wstring line;
    std::getline(wcin, line);

    wstringstream ss(line);
    int arr[100];
    int num, size = 0;

    while (ss >> num && size < 100) {
        arr[size++] = num;
    }

    reverse(arr, size);

    wcout << L"[";
    for (int i = 0; i < size; i++) {
        wcout << arr[i];
        if (i + 1 < size) {
            wcout << L", ";
        }
    }
    wcout << L"]\n";

    return 0;
}
