#include "task1/time.hpp"
#include "utils.hpp"
#include <map>
#include <any>
#include <vector>
#include <string>
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


// <Time>
void createTime(vector<any>& vault) { 
    vault[0] = Time(input<int>(L"Введите время в секундах", [](int x) { return x >= 0; }));
    print(L"Объект Time создан!");
}

void getTime(vector<any>& vault) {
    if (vault.size() <= 0 || vault[0].type() != typeid(Time)) {
        wcout << L"Ошибка! Создайте объект времени" << endl;
        return;
    }
    any_cast<Time>(vault[0]).print();
}

void getSeconds(vector<any>& vault) {
    if (vault.size() <= 0 || vault[0].type() != typeid(Time)) {
        wcout << L"Ошибка! Создайте объект времени" << endl;
        return;
    }
    print(L"Количество секунд: ", any_cast<Time>(vault[0]).getSeconds());
}

void getTimeVariants() { 
    print(L"10 секунд:", Time(10).toString());
    print(L"10000 секунд:", Time(10000).toString());
    print(L"100000 секунд:", Time(100000).toString());
}
// </Time>


int main() {
    setRuLocale();
    
    vector<any> objects_vault(10);
    map<wstring, vector<MenuItem>> menuMap;


    menuMap[L"1.4 Время"] = {
        {L"Создать объект класса", [&objects_vault]() { createTime(objects_vault); }},
        {L"Получить значение", [&objects_vault]() { getTime(objects_vault); }},
        {L"Получить значение в секундах", [&objects_vault]() { getSeconds(objects_vault); }},
        {L"Вывести варианты по заданию", getTimeVariants}
    };
    
    menuMap[L"1.5 Дом"] = {
        {L"Тестовая функция", getTimeVariants}
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