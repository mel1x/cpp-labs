#pragma once

#include <string>
#include <vector>

using namespace std;

class Task2 {
private:
    wstring filename;
    int n;
    vector<vector<int>> matrix;

    int getColumnSum(int col);
    int findMinSumColumn();

public:
    Task2(wstring filename, int n);

    void fillFile(int count, int minValue, int maxValue);

    void loadMatrix();

    void replaceColumns();
    
    void printMatrix();
    void printFile();
};