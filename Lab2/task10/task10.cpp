#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

using std::wcin;
using std::wcout;
using std::string;
using std::vector;
using std::map;
using mix::input;
using mix::print;

bool isValidWord(const string& word) {
    if (word.empty()) return false;
    
    return std::all_of(word.begin(), word.end(), [](char c) {
        return c >= 'A' && c <= 'Z';
    });
}

void processWords(const vector<string>& V) {
    map<char, size_t> M;
    for (auto it = V.begin(); it != V.end(); ++it) {
        M[(*it)[0]] += (*it).size();
    }
    
    print(L"\nРезультаты:");
    for (auto it = M.begin(); it != M.end(); ++it) {
        print(it->first, L"-", it->second);
    }
}

int main() {
    mix::setRuLocale();
    
    ulong N = input<ulong>(L"Введите количество слов (N > 0)");
    while (N < 1) {
        print(L"Ошибка! N должно быть > 0 !!!");
        N = input<ulong>(L"Введите количество слов (N > 0)");
    }
    
    vector<string> V;
    print(L"Введите слова заглавными английскими буквами:");
    
    for (ulong i = 0; i < N; ++i) {
        string word = input<string>(L"Слово " + std::to_wstring(i + 1));
        while (!isValidWord(word)) {
            print(L"Ошибка! Слово должно содержать только заглавные английские буквы (A-Z) !!!");
            word = input<string>(L"Слово " + std::to_wstring(i + 1));
        }

        V.push_back(word);
    }
    
    processWords(V);
}