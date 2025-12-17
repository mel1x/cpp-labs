#pragma once

#include <string>

class Task1 {
private:
    std::wstring inFilename;
    std::wstring outFilename;

public:
    Task1(std::wstring inFilename, std::wstring outFilename);
    
    void fillFile(int count, int minValue, int maxValue);

    void copyMultiplesOfK(int k);
    
    void printFile(const std::wstring& filename);
};