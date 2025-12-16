#include "task2.hpp"
#include "../utils.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <limits>

using namespace std;
namespace fs = std::filesystem;

Task2::Task2(wstring filename, int n) 
    : filename(filename), n(n) {
    matrix.resize(n, vector<int>(n, 0));
    srand(time(0));
}

void Task2::fillFile(int count, int minValue, int maxValue) {
    fs::path path(filename);
    
    ifstream checkFile(path);
    if (checkFile.is_open()) {
        checkFile.close();
        
        if (fs::remove(path)) {
            print(L"Старый файл", filename, L"удалён");
        }
    }
    
    ofstream file(path, ios::binary | ios::out);
    
    if (!file.is_open()) {
        print(L"Ошибка: не удалось создать файл", filename);
        return;
    }
    
    print(L"Создан новый файл", filename);
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

void Task2::loadMatrix() {
    fs::path path(filename);
    
    ifstream file(path, ios::binary | ios::in);
    
    if (!file.is_open()) {
        print(L"Ошибка: не удалось открыть файл", filename);
        return;
    }
    
    print(L"\nЗагрузка данных из файла в матрицу", n, L"×", n);
    
    int number;
    int readCount = 0;
    int totalElements = n * n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (file.read(reinterpret_cast<char*>(&number), sizeof(int))) {
                matrix[i][j] = number;
                readCount++;
            } else {
                goto endReading;
            }
        }
    }
    
    endReading:
        file.close();
        
        print(L"Загружено элементов:", readCount);
        
        if (readCount < totalElements) {
            print(L"Недостающие элементы заполнены нулями");
        }
}

int Task2::getColumnSum(int col) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][col];
    }
    return sum;
}

int Task2::findMinSumColumn() {
    int minSum = numeric_limits<int>::max();
    int minCol = 0;
    
    print(L"\nСуммы столбцов:");
    
    for (int col = 0; col < n; col++) {
        int sum = getColumnSum(col);
        wcout << L"Столбец " << col << L": " << sum << endl;
        
        if (sum < minSum) {
            minSum = sum;
            minCol = col;
        }
    }
    
    print(L"\nСтолбец с минимальной суммой:", minCol, L"(сумма =", minSum, L")");
    
    return minCol;
}

void Task2::replaceColumns() {
    int minCol = findMinSumColumn();
    
    vector<int> minColumn(n);
    for (int i = 0; i < n; i++) {
        minColumn[i] = matrix[i][minCol];
    }
    
    for (int col = 0; col < n; col++) {
        for (int row = 0; row < n; row++) {
            matrix[row][col] = minColumn[row];
        }
    }
    
    print(L"\nВсе столбцы заменены на столбец с минимальной суммой");
}

void Task2::printMatrix() {
    print();
    print(L"Матрица", n, L"×", n, L":");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            wcout.width(5);
            wcout << matrix[i][j];
        }
        print();
    }
}

void Task2::printFile() {
    fs::path path(filename);
    
    ifstream file(path, ios::binary | ios::in);
    
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