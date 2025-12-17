#pragma once

#include <string>
#include <vector>

class Task2 {
private:
    std::wstring filename;
    int n;
    std::vector<std::vector<int>> matrix;

    int getColumnSum(int col);
    int findMinSumColumn();

public:
    Task2(std::wstring filename, int n);

    void fillFile(int count, int minValue, int maxValue);

    void loadMatrix();

    void replaceColumns();
    
    void printMatrix();
    void printFile();
};