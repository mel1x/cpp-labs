#include "task3.hpp"
#include "../utils.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <algorithm>
#include <cstring>
#include <limits>

namespace fs = std::filesystem;

Task3::Task3(std::wstring filename) 
    : filename(filename) {
}

void Task3::fillFile() {
    fs::path path(filename);
    
    if (fs::exists(path)) {
        fs::remove(path);
        print(L"Старый файл", filename, L"удалён");
    }
    
    ofstream file(path, ios::binary | ios::out);
    
    if (!file.is_open()) {
        print(L"Ошибка: не удалось создать файл", filename);
        return;
    }
    
    print(L"Создан новый файл", filename);
    print(L"\nДобавление игрушек в файл:");
    
    std::vector<Toy> sampleToys;
    Toy toy;

    wcscpy(toy.name, L"Мяч");
    toy.price = 350.50;
    toy.minAge = 3;
    toy.maxAge = 14;
    sampleToys.push_back(toy);
    
    wcscpy(toy.name, L"Конструктор LEGO");
    toy.price = 4500.00;
    toy.minAge = 2;
    toy.maxAge = 12;
    sampleToys.push_back(toy);
    
    wcscpy(toy.name, L"Кукла Барби");
    toy.price = 2200.00;
    toy.minAge = 3;
    toy.maxAge = 8;
    sampleToys.push_back(toy);
    
    wcscpy(toy.name, L"Конструктор особняк");
    toy.price = 2300.00;
    toy.minAge = 3;
    toy.maxAge = 12;
    sampleToys.push_back(toy);
    
    wcscpy(toy.name, L"Радиоуправляемая машина");
    toy.price = 5500.00;
    toy.minAge = 5;
    toy.maxAge = 14;
    sampleToys.push_back(toy);
    
    wcscpy(toy.name, L"Конструктор 'Звезда смерти'");
    toy.price = 14200.00;
    toy.minAge = 4;
    toy.maxAge = 12;
    sampleToys.push_back(toy);
    
    wcscpy(toy.name, L"Мишка");
    toy.price = 1650.00;
    toy.minAge = 0;
    toy.maxAge = 5;
    sampleToys.push_back(toy);
    
    wcscpy(toy.name, L"Конструктор самолет");
    toy.price = 1500.00;
    toy.minAge = 2;
    toy.maxAge = 8;
    sampleToys.push_back(toy);
    
    for (const auto& t : sampleToys) {
        file.write(reinterpret_cast<const char*>(&t), sizeof(Toy));
        print(L"  - ", t.name, L"-", t.price, L"руб, от", t.minAge, L"До", t.maxAge, L"лет");
    }
    
    file.close();
    
    print(L"\nВсего добавлено игрушек:", sampleToys.size());
    print(L"Файл успешно заполнен!");
}

void Task3::addToy(const std::wstring& name, double price, int minAge, int maxAge) {
    fs::path path(filename);
    
    ofstream file(path, ios::binary | ios::app);
    
    if (!file.is_open()) {
        print(L"Ошибка: не удалось открыть файл", filename);
        return;
    }
    
    Toy toy;
    
    wcsncpy(toy.name, name.c_str(), 49);
    toy.name[49] = L'\0';
    
    toy.price = price;
    toy.minAge = minAge;
    toy.maxAge = maxAge;
    
    file.write(reinterpret_cast<const char*>(&toy), sizeof(Toy));
    
    file.close();
    
    print(L"Игрушка добавлена:", name);
}

void Task3::loadToys() {
    fs::path path(filename);
    
    ifstream file(path, ios::binary | ios::in);
    
    if (!file.is_open()) {
        print(L"Ошибка: не удалось открыть файл", filename);
        return;
    }
    
    toys.clear();
    
    Toy toy;
    
    while (file.read(reinterpret_cast<char*>(&toy), sizeof(Toy))) {
        toys.push_back(toy);
    }
    
    file.close();
}

bool Task3::findMostExpensive(Toy& result) {
    loadToys();
    
    if (toys.empty()) {
        print(L"Файл пуст!");
        return false;
    }
    
    bool found = false;
    double maxPrice = -1.0;
    
    for (const auto& toy : toys) {
        std::wstring toyName = toy.name;
        
        transform(toyName.begin(), toyName.end(), toyName.begin(), ::towlower);
        
        if (toyName.find(L"конструктор") != std::wstring::npos) {
            if (toy.price > maxPrice) {
                maxPrice = toy.price;
                result = toy;
                found = true;
            }
        }
    }
    
    return found;
}

void Task3::printToy(const Toy& toy) {
    wcout << L"  Название: " << toy.name << endl;
    wcout << L"  Стоимость: " << toy.price << L" руб." << endl;
    wcout << L"  Возраст: от " << toy.minAge << L" до " << toy.maxAge << L" лет" << endl;
}

void Task3::printAllToys() {
    fs::path path(filename);
    
    ifstream file(path, ios::binary | ios::in);
    
    if (!file.is_open()) {
        print(L"Ошибка: не удалось открыть файл", filename);
        return;
    }
    
    wcout << endl;
    print(L"Все игрушки в файле", filename, L":");
    wcout << endl;
    
    Toy toy;
    int count = 0;
    
    while (file.read(reinterpret_cast<char*>(&toy), sizeof(Toy))) {
        count++;
        wcout << count << L". " << toy.name 
              << L" - " << toy.price << L" руб. ("
              << toy.minAge << L"-" << toy.maxAge << L" лет)" << endl;
    }
    
    file.close();
    
    if (count == 0) {
        print(L"Файл пуст!");
    } else {
        wcout << endl;
        print(L"Всего игрушек:", count);
    }
}