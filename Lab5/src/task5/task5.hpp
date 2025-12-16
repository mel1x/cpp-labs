#pragma once

#include <string>
#include <vector>

using namespace std;

class Task5 {
private:
    wstring filename;
    vector<int> numbers;

public:
    Task5(wstring filename);

    void fillFile(int totalCount, int numbersPerLine, int minValue, int maxValue);
    
    void loadNumbers();
    
    long long calculateMult(int k);
    
    void printFile();
    void printNumbers(int k);
};