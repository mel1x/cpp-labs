#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>
#include <sstream>
#include <vector>

using std::wcin;
using std::wcout;
using std::wstring;
using std::wstringstream;
using std::vector;

void reverse(vector<int>& arr) {
    size_t n = arr.size();
    for (size_t i = 0; i < n / 2; i++) {
        std::swap(arr[i], arr[n - i - 1]);
    }
}

int main() {
    mix::setRuLocale();

    wcout << L"Введите числа через пробел: ";
    wstring line;
    std::getline(wcin, line);

    wstringstream ss(line);
    vector<int> numbers;
    int num;
    while (ss >> num) {
        numbers.push_back(num);
    }

    reverse(numbers);

    wcout << L"[";
    for (size_t i = 0; i < numbers.size(); i++) {
        wcout << numbers[i];
        if (i + 1 < numbers.size()) {
            wcout << L", ";
        }
    }
    wcout << L"]\n";

    return 0;
}
