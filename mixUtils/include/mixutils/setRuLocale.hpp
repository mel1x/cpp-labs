#pragma once
#include <iostream>
#include <locale>
#include <clocale>

#ifdef _WIN32
    #include <windows.h>
#endif

namespace mix {

    inline void setRuLocale() {
    #ifdef _WIN32
        SetConsoleCP(65001);
        SetConsoleOutputCP(65001);

        const char* candidates[] = {
            ".UTF-8",
            "ru-RU",
            "Russian_Russia.1251",
            ""
        };

        for (const char* name : candidates) {
            try {
                std::locale loc{ name };
                std::locale::global(loc);
                std::wcin.imbue(loc);
                std::wcout.imbue(loc);
                std::wcerr.imbue(loc);
                std::setlocale(LC_ALL, name);
                return;
            }
            catch (...) {
                // пробуем следующий вариант
            }
        }
    #else
        std::setlocale(LC_ALL, "ru_RU.UTF-8");
        std::locale loc{ "ru_RU.UTF-8" };
        std::locale::global(loc);
        std::wcin.imbue(loc);
        std::wcout.imbue(loc);
        std::wcerr.imbue(loc);
    #endif
    }

}