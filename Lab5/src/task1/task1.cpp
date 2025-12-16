#include "task1.hpp"
#include "../utils.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <locale>
#include <codecvt>

using namespace std;


string wstringToString(const wstring& wstr) {
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wstr);
}

Task1::Task1(wstring inFilename, wstring outFilename) 
    : inFilename(inFilename), outFilename(outFilename) {
    srand(time(0));
}


void Task1::fillFile(int count, int minValue, int maxValue) {
    string strInFilename = wstringToString(inFilename);
    
    ifstream checkFile(strInFilename);
    if (checkFile.is_open()) {
        checkFile.close();
        
        if (remove(strInFilename.c_str()) == 0) {
            print(L"Старый файл", inFilename, L"удалён");
        }
    }
    
    ofstream file(strInFilename, ios::binary | ios::out);
    if (!file.is_open()) {
        print(L"Ошибка: не удалось создать файл", inFilename);
        return;
    }
    
    print(L"Создан новый файл", inFilename);
    print(L"Записываем", count, L"случайных чисел:");
    
    for (int i = 0; i < count; i++) {
        int randomNumber = minValue + rand() % (maxValue - minValue + 1);
        
        file.write(reinterpret_cast<const char*>(&randomNumber), sizeof(int));
        
        wcout << randomNumber << L" ";
    }
    
    print();
    print(L"Файл успешно заполнен!");
    
    file.close();
}

void Task1::copyMultiplesOfK(int k) {
    if (k == 0) {
        print(L"Ошибка: k не может быть равно 0!");
        return;
    }
    
    string strInFilename = wstringToString(inFilename);
    string strOutFilename = wstringToString(outFilename);
    
    ifstream inputFile(strInFilename, ios::binary | ios::in);
    
    if (!inputFile.is_open()) {
        print(L"Ошибка: не удалось открыть файл", inFilename);
        return;
    }
    
    ofstream outputFile(strOutFilename, ios::binary | ios::out);
    
    if (!outputFile.is_open()) {
        print(L"Ошибка: не удалось создать файл", outFilename);
        inputFile.close();
        return;
    }
    
    print();
    print(L"Создан файл", outFilename);
    print(L"Числа, кратные", k, L":");
    
    int number;
    int copiedCount = 0;
    
    while (inputFile.read(reinterpret_cast<char*>(&number), sizeof(int))) {
        if (number % k == 0) {
            outputFile.write(reinterpret_cast<const char*>(&number), sizeof(int));
            wcout << number << L" ";
            copiedCount++;
        }
    }
    
    print();
    print(L"Скопировано чисел:", copiedCount);
    print(L"Результат сохранён в файл", outFilename);
    
    inputFile.close();
    outputFile.close();
}

void Task1::printFile(const wstring& filename) {
    string strFilename = wstringToString(filename);
    
    ifstream file(strFilename, ios::binary | ios::in);
    
    if (!file.is_open()) {
        print(L"Ошибка: не удалось открыть файл", filename);
        return;
    }
    
    print();
    print(L"Содержимое файла", filename, L":");
    
    int number;
    int count = 0;
    
    while (file.read(reinterpret_cast<char*>(&number), sizeof(int))) {
        wcout << number << L" ";
        count++;
    }
    
    print();
    print(L"Всего чисел в файле:", count);
    
    file.close();
}