#include "task1/equation.hpp"
#include "utils.hpp"
#include <map>
#include <any>
#include <vector>
#include <string>
#include <iostream>
#include <functional>

using namespace std;

struct MenuItem {
    wstring name;
    function<void()> func;
};

void showMainMenu(vector<wstring>& categories) {
    clearConsole();
    print(L"=== ГЛАВНОЕ МЕНЮ ===\n");
    
    for (int i = 0; i < categories.size(); i++) {
        print(to_wstring(i + 1) + L")", categories[i]);
    }
    print(L"0) Выйти из программы");
}

void showSubMenu(wstring categoryName, vector<MenuItem>& items) {
    clearConsole();
    print(L"=== ", categoryName, L" ===\n");
    
    for (int i = 0; i < items.size(); i++) {
        print(to_wstring(i + 1) + L")", items[i].name);
    }
    print(L"0) Назад");
}

// <Equation>
void createEquation(vector<any>& vault) {
    ushort limit = input<ushort>(L"Введите количество коэффициентов", [](int x) { return x >= 0 and x <= 3; });
    
    vector<double> coefs;
    wstring names[] = {L"a", L"b", L"c"};

    for (ushort i = 0; i < limit; i++) {
        coefs.push_back(input<double>(L"Введите коэффициент " + names[i]));
    }

    switch (coefs.size()) {
        case 0:
            vault[0] = QuadraticEquation();
            break;
        case 1:
            vault[0] = QuadraticEquation(coefs[0]);
            break;
        case 2:
            vault[0] = QuadraticEquation(coefs[0], coefs[1]);
            break;
        case 3:
            vault[0] = QuadraticEquation(coefs[0], coefs[1], coefs[2]);
            break;
    }
}

void getCoefs(vector<any>& vault) {
    if (vault.size() <= 0 || vault[0].type() != typeid(QuadraticEquation)) {
        print(L"Ошибка! Создайте объект уравнения");
        return;
    }
    QuadraticEquation eq = any_cast<QuadraticEquation>(vault[0]);
    print(L"a:", eq.getA(), L"b:", eq.getB(), L"c:", eq.getC());
}

void getEquation(vector<any>& vault) {
    if (vault.size() <= 0 || vault[0].type() != typeid(QuadraticEquation)) {
        print(L"Ошибка! Создайте объект уравнения");
        return;
    }
    QuadraticEquation eq = any_cast<QuadraticEquation>(vault[0]);
    print(eq.toString());
    wcout << eq;
    
    print();
}

void getDiscriminant(vector<any>& vault) {
    if (vault.size() <= 0 || vault[0].type() != typeid(QuadraticEquation)) {
        print(L"Ошибка! Создайте объект уравнения");
        return;
    }
    QuadraticEquation eq = any_cast<QuadraticEquation>(vault[0]);
    print(L"Дискременант:", eq.getDiscriminant());
}

void solve(vector<any>& vault) {
    if (vault.size() <= 0 || vault[0].type() != typeid(QuadraticEquation)) {
        print(L"Ошибка! Создайте объект уравнения");
        return;
    }
    QuadraticEquation eq = any_cast<QuadraticEquation>(vault[0]);
    vector<double> result = eq.solve();

    print(L"Решений:", result.size());
    if (result.empty()) {
        print(L"Корней нет");
    } else {
        print(L"Корни:");
        for (size_t i = 0; i < result.size(); i++) {
            print(to_wstring(i+1) + L")", result[i]);
        }
    }
}

void checkOperators(vector<any>& vault) {
    if (vault.size() <= 0 || vault[0].type() != typeid(QuadraticEquation)) {
        print(L"Ошибка! Создайте объект уравнения");
        return;
    }
    QuadraticEquation eq = any_cast<QuadraticEquation>(vault[0]);
    print(L"= Операторы ++ и -- =");
    print(L"Изначальное уравнение");
    print(eq.toString());
    print(L"После вызова префиксного ++");
    print((++eq).toString());
    print(L"После вызова префиксного --");
    print((--eq).toString());
    print();

    print(L"= Преобразования =");
    print(L"Неявное преобразование к double (дискриминант)");
    double eqd = eq;
    print(eqd);
    print(L"Явное преобразование к bool (дискриминант >= 0)");
    bool eqb = static_cast<bool>(eq);
    print(formatBool(eqb));
    print();

    print(L"= Сравнения =");
    print(L"Сравнение с собой");
    print(L"==:", formatBool(eq == eq));
    print(L"!=:", formatBool(eq != eq));
    print(L"Сравнение с 2x^2 + 2x - 3");
    QuadraticEquation eqSecond = QuadraticEquation(2.0, 2.0, 3.0);
    print(L"==:", formatBool(eq == eqSecond));
    print(L"!=:", formatBool(eq != eqSecond));

}
// </Equation>

int main() {
    setRuLocale();

    vector<any> objects_vault(32);
    map<wstring, vector<MenuItem>> menuMap;

    menuMap[L"1/2 Квадратное уравнение"] = {
        {L"Создать объект класса", [&objects_vault]() { createEquation(objects_vault); }},
        {L"Получить коэффициенты", [&objects_vault]() { getCoefs(objects_vault); }},
        {L"Получить уравнение", [&objects_vault]() { getEquation(objects_vault); }},
        {L"Получить дискременант", [&objects_vault]() { getDiscriminant(objects_vault); }},
        {L"Решить", [&objects_vault]() { solve(objects_vault); }},
        {L"Проверка перегрузки", [&objects_vault]() { checkOperators(objects_vault); }}
    };


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
    
    return 0;
}