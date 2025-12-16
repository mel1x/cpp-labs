#pragma once

#include <string>
#include <vector>

using namespace std;

class Task4 {
private:
    wstring filename;
    vector<int> numbers;

public:
    Task4(wstring filename);
    
    void fillFile(int count, int minValue, int maxValue);
    
    void loadNumbers();

    int findSum();
    
    void printFile();
    void printIndexes();
};