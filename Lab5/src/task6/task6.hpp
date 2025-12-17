#pragma once

#include <string>

class Task6 {
private:
    std::wstring inFilename;
    std::wstring outFilename;

    bool isRuLetter(wchar_t ch);
    bool containsRuLetters(const std::wstring& line);

public:
    Task6(std::wstring inFilename, std::wstring outFilename);

    void createFile();

    void addFileLine(const std::wstring& line);
    
    void copyLines();
    
    void printFile(const std::wstring& filename);
};