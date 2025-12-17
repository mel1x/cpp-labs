#include "task6.hpp"
#include "../utils.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

Task6::Task6(std::wstring inFilename, std::wstring outFilename) 
    : inFilename(inFilename), outFilename(outFilename) {
}

bool Task6::isRuLetter(wchar_t ch) {
    return (ch >= 0x0410 && ch <= 0x044F) ||
           ch == 0x0401 ||
           ch == 0x0451;
}

bool Task6::containsRuLetters(const std::wstring& line) {
    for (wchar_t ch : line) {
        if (isRuLetter(ch)) {
            return true;
        }
    }
    return false;
}

void Task6::createFile() {
    fs::path path(inFilename);
    
    if (fs::exists(path)) {
        fs::remove(path);
        print(L"Старый файл", inFilename, L"удалён");
    }
    
    wofstream file(path);
    
    if (!file.is_open()) {
        print(L"Ошибка: не удалось создать файл", inFilename);
        return;
    }
    
    file.imbue(locale(""));
    
    print(L"Создан новый файл", inFilename);
    print(L"Добавление примеров строк:");
    print();
    
    std::vector<std::wstring> sampleLines = {
        L"Hello World",
        L"Привет мир",
        L"123456789",
        L"Dota2 good game",
        L"Смешанный englesh текст",
        L"Numbers 100",
        L"спец символы *!@#%^&",
        L"Это полностью русская строка",
        L"Ещё одна строка с буквой ё",
        L"again eng line",
        L"",
        L"CPP LABA NOVAYA"
    };
    
    for (const auto& line : sampleLines) {
        file << line << endl;
        wcout << L"  " << line << endl;
    }
    
    file.close();
    
    print();
    print(L"Файл успешно заполнен!");
    print(L"Всего строк:", sampleLines.size());
}

void Task6::addFileLine(const std::wstring& line) {
    fs::path path(inFilename);
    
    wofstream file(path, ios::app);
    
    if (!file.is_open()) {
        print(L"Ошибка: не удалось открыть файл", inFilename);
        return;
    }
    
    file.imbue(locale(""));
    
    file << line << endl;
    file.close();
    
    print(L"Строка добавлена в файл");
}

void Task6::copyLines() {
    fs::path pathIn(inFilename);
    fs::path pathOut(outFilename);
    
    wifstream inputFile(pathIn);
    
    if (!inputFile.is_open()) {
        print(L"Ошибка: не удалось открыть файл", inFilename);
        return;
    }
    
    inputFile.imbue(locale(""));
    
    wofstream outputFile(pathOut);
    
    if (!outputFile.is_open()) {
        print(L"Ошибка: не удалось создать файл", outFilename);
        inputFile.close();
        return;
    }
    
    outputFile.imbue(locale(""));
    
    print(L"\nКопирование строк без русских букв...");
    print();
    
    std::wstring line;
    int totalLines = 0;
    int copiedLines = 0;
    
    while (getline(inputFile, line)) {
        totalLines++;

        if (!containsRuLetters(line)) {
            outputFile << line << endl;
            copiedLines++;
            print(L" Скопировано:", line);
        } else {
            print(L" Пропущено:", line);
        }
    }
    
    inputFile.close();
    outputFile.close();
    
    print();
    print(L"Обработка завершена");
    print(L"Скопировано строк:", copiedLines);
    print(L"Пропущено строк:", totalLines - copiedLines);
    print(L"Результат сохранён в файл", outFilename);
}

void Task6::printFile(const std::wstring& filename) {
    fs::path path(filename);
    
    wifstream file(path);
    
    if (!file.is_open()) {
        print(L"Ошибка: не удалось открыть файл", filename);
        return;
    }
    
    file.imbue(locale(""));
    
    print();
    print(L"Содержимое файла", filename);
    print();
    
    std::wstring line;
    int lineNumber = 1;
    
    while (getline(file, line)) {
        print(lineNumber, L"-", line);
        lineNumber++;
    }
    
    file.close();
    
    if (lineNumber == 1) {
        print(L"Файл пуст!");
    } else {
        print();
        print(L"Всего строк:", lineNumber - 1);
    }
}