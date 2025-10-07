#include "../mixUtils/include/mixUtils.hpp"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using std::vector;
using std::set;
using mix::input;
using mix::print;

int main() {
    mix::setRuLocale();

    int size0 = input<int>(L"Введите размер вектора V0: ");
    vector<int> V0(size0);
    
    print(L"Введите элементы вектора V0:");
    for (int i = 0; i < size0; ++i) {
        V0[i] = input<int>(L"V0[" + std::to_wstring(i) + L"]: ");
    }
    
    set<int> setV0(V0.begin(), V0.end());

    
    int N = input<ushort>(L"Введите количество векторов N: ");
    int count = 0;
    
    for (int i = 1; i <= N; ++i) {
        print(L"\nВектор V" + std::to_wstring(i) + L":");
        
        int sizeI = input<int>(L"Введите размер вектора V" + std::to_wstring(i) + L": ");
        vector<int> VI(sizeI);
        
        print(L"Введите элементы вектора V" + std::to_wstring(i) + L":");
        for (int j = 0; j < sizeI; ++j) {
            VI[j] = input<int>(L"V" + std::to_wstring(i) + L"[" + std::to_wstring(j) + L"]: ");
        }

        set<int> setVI(VI.begin(), VI.end());
        
        if (std::includes(setVI.begin(), setVI.end(), 
                          setV0.begin(), setV0.end())) {
            count++;
            print(L"Вектор V" + std::to_wstring(i) + L" содержит все элементы V0");
        } else {
            print(L"Вектор V" + std::to_wstring(i) + L" НЕ содержит все элементы V0");
        }
    }
    
    print(L"\n========================================");
    print(L"Количество векторов, содержащих все элементы V0: " + std::to_wstring(count));
    
    return 0;
}