#pragma once

#include <string>

using namespace std;

class Task1 {
private:
    wstring inFilename;
    wstring outFilename;

public:
    Task1(wstring inFilename, wstring outFilename);
    
    void fillFile(int count, int minValue, int maxValue);

    void copyMultiplesOfK(int k);
    
    void printFile(const wstring& filename);
};