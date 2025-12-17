#include "task4.hpp"
#include "../utils.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <cstdlib>
#include <ctime>

namespace fs = std::filesystem;

Task4::Task4(std::wstring filename) 
    : filename(filename) {
    srand(time(0));
}

void Task4::fillFile(int count, int minValue, int maxValue) {
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
    print(L"Записываем", count, L"случайных чисел:");
    
    for (int i = 0; i < count; i++) {
        int randomNumber = minValue + rand() % (maxValue - minValue + 1);
        file << randomNumber << endl;
        wcout << randomNumber << L" ";
    }
    
    print();
    print(L"Файл успешно заполнен!");
    
    file.close();
}

void Task4::loadNumbers() {
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

int Task4::findSum() {
    loadNumbers();
    
    if (numbers.empty()) {
        print(L"Файл пуст!");
        return 0;
    }
    
    int sum = 0;
    int count = 0;
    
    print();
    print(L"Поиск элементов, равных своему индексу:");
    print();
    
    for (size_t i = 0; i < numbers.size(); i++) {
        if (numbers[i] == static_cast<int>(i)) {
            print(L" Индекс", i, L", число:", numbers[i]);
            sum += numbers[i];
            count++;
        }
    }
    
    print();
    
    if (count == 0) {
        print(L"Элементов, равных своему индексу, не найдено");
    } else {
        print(L"Найдено элементов:", count);
        print(L"Сумма этих элементов:", sum);
    }
    
    return sum;
}

void Task4::printFile() {
    fs::path path(filename);
    
    wifstream file(path);
    
    if (!file.is_open()) {
        print(L"Ошибка: не удалось открыть файл", filename);
        return;
    }
    
    print();
    print(L"Содержимое файла", filename, L":");
    print();
    
    int number;
    int line = 0;
    
    while (file >> number) {
        print(L"Строка", line, L"-", number);
        line++;
    }
    
    file.close();
    
    if (line == 0) {
        print(L"Файл пуст!");
    } else {
        print();
        print(L"Всего чисел:", line);
    }
}

void Task4::printIndexes() {
    loadNumbers();
    
    if (numbers.empty()) {
        print(L"Файл пуст!");
        return;
    }
    
    print();
    print(L"Сравнение чисел с индексами:");
    print();
    
    wcout << L"  Индекс | Число | Совпадение" << endl;
    wcout << L"  ------------------------" << endl;
    
    for (size_t i = 0; i < numbers.size(); i++) {
        wcout << L"  ";
        wcout.width(6);
        wcout << i << L" | ";
        wcout.width(5);
        wcout << numbers[i] << L" | ";
        
        if (numbers[i] == static_cast<int>(i)) {
            wcout << L"  Да" << endl;
        } else {
            wcout << L"  нет" << endl;
        }
    }
}