#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <locale>
#include <sstream>
#include <cstdlib>
#include <map>
#include <vector>
#include <functional>

#ifdef _WIN32
    #include <io.h>
    #include <fcntl.h>
#endif

using namespace std;

inline void setRuLocale() {
    #ifdef _WIN32
        setlocale(LC_ALL, "Russian");
        _setmode(_fileno(stdout), _O_U16TEXT);
        _setmode(_fileno(stdin), _O_U16TEXT);
    #else
        try {
            setlocale(LC_ALL, "ru_RU.UTF-8");
            wcin.imbue(std::locale("ru_RU.UTF-8"));
            wcout.imbue(std::locale("ru_RU.UTF-8"));
        } catch (const std::exception&) {
            try {
                setlocale(LC_ALL, "");
                wcin.imbue(std::locale(""));
                wcout.imbue(std::locale(""));
            } catch (const std::exception&) {
                wcin.imbue(std::locale::classic());
                wcout.imbue(std::locale::classic());
            }
        }
    #endif
}

inline void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

inline wstring formatBool(bool value) {
    return value ? L"true" : L"false";
}



// <Input>
// Input с проверкой типа и условия.
// Пример использования:
// int num = input<int>(L"Введите число");
// int num = input<int>(L"Введите число", L"Неверное число!");
template<typename T>
T input(wstring prompt, wstring errorPrompt = L"Ошибка! Некорректный ввод") {
    T value;
    wstring line;
    
    while (true) {
        wcout << prompt << L": ";
        getline(wcin, line);
        
        wstringstream ss(line);
        
        if (ss >> value) {
            wstring remaining;
            ss >> remaining;
            
            if (remaining.empty()) {
                return value;
            } else {
                wcout << errorPrompt << endl;
            }
        } else {
            wcout << errorPrompt << endl;
        }
    }
}


template<typename T, typename Func>
T input(wstring prompt, Func condition, wstring errorPrompt = L"Ошибка! Некорректный ввод") {
    T value;
    wstring line;
    
    while (true) {
        wcout << prompt << L": ";
        getline(wcin, line);
        
        wstringstream ss(line);
        
        if (ss >> value) {
            wstring remaining;
            ss >> remaining;
            
            if (remaining.empty()) {
                if (condition(value)) {
                    return value;
                } else {
                    wcout << errorPrompt << endl;
                }
            } else {
                wcout << errorPrompt << endl;
            }
        } else {
            wcout << errorPrompt << endl;
        }
    }
}
// </Input>



// <Input>
// Input для строк с проверкой типа и кастомного условия.
// Пример использования:
// wstring name = input<wstring>(L"Введите имя");
// wstring name = input<wstring>(L"Введите имя", L"Имя некорректно!");
template<>
inline wstring input<wstring>(wstring prompt, wstring errorPrompt) {
    wstring value;
    wcout << prompt << L": ";
    getline(wcin, value);
    return value;
}


template<typename Func>
wstring input(wstring prompt, Func condition, wstring errorPrompt = L"Ошибка! Некорректный ввод") {
    wstring value;
    
    while (true) {
        wcout << prompt << L": ";
        getline(wcin, value);
        
        if (condition(value)) {
            return value;
        } else {
            wcout << errorPrompt << endl;
        }
    }
}
// </Input>



// <Print>
// Print как в python, но bool как 1 и 0.
// Пример использования:
// print(L"Число:", num);
template<typename T>
void printHelper(const T& value) {
    wcout << value;
}


template<typename... Args>
void print(const Args&... args) {
    bool first = true;
    
    ((first ? (printHelper(args), first = false, 0) 
        : (wcout << L" ", printHelper(args), 0)), ...);
    
    wcout << endl;
}


inline void print() {
    wcout << endl;
}
// </Print>



// <Menu>
// Структура для элементов меню
struct MenuItem {
    wstring name;
    function<void()> func;
};

// Показать главное меню
inline void showMainMenu(vector<wstring>& categories) {
    clearConsole();
    print(L"=== ГЛАВНОЕ МЕНЮ ===\n");
    
    for (int i = 0; i < categories.size(); i++) {
        print(to_wstring(i + 1) + L")", categories[i]);
    }
    print(L"0) Выйти из программы");
}

// Показать подменю
inline void showSubMenu(wstring categoryName, vector<MenuItem>& items) {
    clearConsole();
    print(L"=== ", categoryName, L" ===\n");
    
    for (int i = 0; i < items.size(); i++) {
        print(to_wstring(i + 1) + L")", items[i].name);
    }
    print(L"0) Назад");
}

// Создать и запустить меню
inline void createMenu(map<wstring, vector<MenuItem>>& menuMap) {
    vector<wstring> categories;
    for (auto& pair : menuMap) {
        categories.push_back(pair.first);
    }

    while (true) {
        showMainMenu(categories);
        
        int choice = input<int>(L"\nВыберите пункт меню", 
                                [&](int x) { return x >= 0 && x <= categories.size(); },
                                L"Ошибка! Введите число от 0 до " + to_wstring(categories.size()));
        
        if (choice == 0) {
            break;
        }
        
        wstring selectedCategory = categories[choice - 1];
        vector<MenuItem>& items = menuMap[selectedCategory];
        
        while (true) {
            showSubMenu(selectedCategory, items);
            
            int subChoice = input<int>(L"\nВыберите действие",
                                       [&](int x) { return x >= 0 && x <= items.size(); },
                                       L"Ошибка! Введите число от 0 до " + to_wstring(items.size()));
            
            if (subChoice == 0) {
                break;
            }
            
            clearConsole();
            print(L"=== ", items[subChoice - 1].name, L" ===\n");
            items[subChoice - 1].func();
            
            print(L"\nНажмите Enter для продолжения...");
            wcin.get();
        }
    }
}
// </Menu>