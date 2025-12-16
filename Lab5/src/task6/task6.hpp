#pragma once

#include <string>
#include <vector>

using namespace std;

class Task6 {
private:
    wstring inFilename;
    wstring outFilename;

    bool isRuLetter(wchar_t ch);
    bool containsRuLetters(const wstring& line);

public:
    Task6(wstring inFilename, wstring outFilename);

    void createFile();

    void addFileLine(const wstring& line);
    
    void copyLines();
    
    void printFile(const wstring& filename);
};