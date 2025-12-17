#pragma once

#include <string>
#include <vector>

class Task4 {
private:
    std::wstring filename;
    std::vector<int> numbers;

public:
    Task4(std::wstring filename);
    
    void fillFile(int count, int minValue, int maxValue);
    
    void loadNumbers();

    int findSum();
    
    void printFile();
    void printIndexes();
};