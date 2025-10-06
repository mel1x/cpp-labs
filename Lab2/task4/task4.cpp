#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>
#include <fstream>
#include <iterator>

using std::wcin;
using std::wcout;
using std::string;
using std::ofstream;
using std::ios;
using std::ostream_iterator;
using mix::input;
using mix::print;

void createStarsFile(string name, ulong K) {
    ofstream file(name, ios::out);
    if (!file.is_open()) {
        print(L"Не удалось открыть файл для записи!");
        exit(1);
    }

    std::fill_n(ostream_iterator<char>(file), K, '*');
    file.close();
}

int main() {
    mix::setRuLocale();

    string name = input<string>(L"Введите имя файла");
    ulong K = input<ulong>(L"Введите количество символов * (K > 0)");
    while (K < 1) {
        print(L"Ошибка K должно быть > 0 !!!");
        K = input<ulong>(L"Введите количество символов * (K > 0)");
    }

    createStarsFile(name, K);

    print(L"Запись в файл выполнена успешно.");
}
