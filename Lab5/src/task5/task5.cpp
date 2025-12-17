#include "task5.hpp"
#include "../utils.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <cstdlib>
#include <ctime>

namespace fs = std::filesystem;

Task5::Task5(std::wstring filename) 
    : filename(filename) {
    srand(time(0));
}

void Task5::fillFile(int totalCount, int numbersPerLine, int minValue, int maxValue) {
    fs::path path(filename);
    
    if (fs::exists(path)) {
        fs::remove(path);
        print(L"Старый файл", filename, L"удалён");
    }
    
    wofstream file(path);
    
    if (!file.is_open()) {
        print(L"Ошибка: не удалось создать файл", filename);
        return;
    }
    
    print(L"Создан новый файл", filename);
    print(L"Записываем", totalCount, L"чисел, по", numbersPerLine, L"в строке:");
    print();
    
    for (int i = 0; i < totalCount; i++) {
        int randomNumber = minValue + rand() % (maxValue - minValue + 1);
        
        file << randomNumber;
        wcout << randomNumber << L" ";
        
        if ((i + 1) % numbersPerLine == 0 || i == totalCount - 1) {
            file << endl;
            print();
        } else {
            file << L" ";
        }
    }
    
    print(L"Файл успешно заполнен!");
    
    file.close();
}

void Task5::loadNumbers() {
    fs::path path(filename);
    
    wifstream file(path);
    
    if (!file.is_open()) {
        print(L"Ошибка: не удалось открыть файл", filename);
        return;
    }
    
    numbers.clear();
    
    int number;
    
    while (file >> number) {
        numbers.push_back(number);
    }
    
    file.close();
    
    print(L"Загружено чисел:", numbers.size());
}

long long Task5::calculateMult(int k) {
    if (k == 0) {
        print(L"Ошибка: k не может быть равно 0!");
        return 0;
    }
    
    loadNumbers();
    
    if (numbers.empty()) {
        print(L"Файл пуст!");
        return 0;
    }
    
    long long product = 1;
    int count = 0;
    
    print();
    print(L"Поиск чисел, кратных", k, L":");
    print();
    
    for (int num : numbers) {
        if (num % k == 0) {
            print(L" ", num, L"кратно:", k);
            product *= num;
            count++;
        }
    }
    
    print();
    
    if (count == 0) {
        print(L"Чисел, кратных", k, L", не найдено");
        return 0;
    } else {
        print(L"Найдено чисел:", count);
        print(L"Произведение:", product);
        return product;
    }
}

void Task5::printFile() {
    fs::path path(filename);
    
    wifstream file(path);
    
    if (!file.is_open()) {
        print(L"Ошибка: не удалось открыть файл", filename);
        return;
    }
    
    print();
    print(L"Содержимое файла", filename, L":");
    print();
    
    std::wstring line;
    int lineNumber = 1;
    
    while (getline(file, line)) {
        print(L"Строка", lineNumber, L"-", line);
        lineNumber++;
    }
    
    file.close();
    
    if (lineNumber == 1) {
        print(L"Файл пуст!");
    } else {
        print();
        print(L"Всего строк:", lineNumber - 1);
    }
}

void Task5::printNumbers(int k) {
    if (k == 0) {
        print(L"Ошибка: k не может быть равно 0!");
        return;
    }
    
    loadNumbers();
    
    if (numbers.empty()) {
        print(L"Файл пуст!");
        return;
    }
    
    print();
    print(L"Все числа из файла (с проверкой кратности", k, L"):");
    print();
    
    for (size_t i = 0; i < numbers.size(); i++) {
        wcout << numbers[i];
        
        if (numbers[i] % k == 0) {
            wcout << L" кратно " << k;
        }
        
        print();
    }
}