#pragma once

#include <string>
#include <vector>

class Task5 {
private:
    std::wstring filename;
    std::vector<int> numbers;

public:
    Task5(std::wstring filename);

    void fillFile(int totalCount, int numbersPerLine, int minValue, int maxValue);
    
    void loadNumbers();
    
    long long calculateMult(int k);
    
    void printFile();
    void printNumbers(int k);
};