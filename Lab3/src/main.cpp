#include "task1/time.hpp"
#include "task1/house.hpp"
#include "task2/employee.hpp"
#include "task2/department.hpp"
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


// <House>
void createHouse(vector<any>& vault) {
    vault[1] = House(input<int>(L"Введите количество этажей", [](int x) { return x > 0; }));
    print(L"Объект House создан!");
}

void getHouse(vector<any>& vault) {
    if (vault.size() <= 1 || vault[1].type() != typeid(House)) {
        wcout << L"Ошибка! Создайте объект дома" << endl;
        return;
    }
    any_cast<House>(vault[1]).print();
}

void getFloors(vector<any>& vault) {
    if (vault.size() <= 1 || vault[1].type() != typeid(House)) {
        wcout << L"Ошибка! Создайте объект дома" << endl;
        return;
    }
    print(L"Количество этажей: ", any_cast<House>(vault[1]).getFloors());
}

void getHouseVariants() {
    print(L"1 этаж:", House(1).toString());
    print(L"5 этажей:", House(5).toString());
    print(L"23 этажа:", House(23).toString());
}
// </House>


// <Employee>
void createDepartment(vector<any>& vault) {
    wstring name = input<wstring>(L"Введите название отдела");

    if (vault.size() > 2 && vault[2].type() == typeid(Department*)) {
        Department* oldDept = any_cast<Department*>(vault[2]);
        delete oldDept;

        if (vault.size() > 3 && vault[3].type() == typeid(Employee*)) {
            Employee* oldEmp = any_cast<Employee*>(vault[3]);
            delete oldEmp;
            vault[3] = any();
            print(L"Предыдущий сотрудник удален, т.к. привязан к старому отделу.");
        }
    }

    vault[2] = new Department(name);
    print(L"Отдел создан!");
}

void createEmployee(vector<any>& vault) {
    if (vault.size() <= 2 || vault[2].type() != typeid(Department*)) {
        print(L"Ошибка! Сначала создайте отдел");
        return;
    }

    Department* dept = any_cast<Department*>(vault[2]);
    wstring name = input<wstring>(L"Введите имя сотрудника");

    if (vault.size() > 3 && vault[3].type() == typeid(Employee*)) {
        Employee* oldEmp = any_cast<Employee*>(vault[3]);

        if (dept->getManager() == oldEmp) {
            dept->setManager(nullptr);
            print(L"Предыдущий сотрудник был начальником отдела. Должность начальника освобождена.");
        }

        delete oldEmp;
    }

    vault[3] = new Employee(name, dept);
    print(L"Сотрудник создан!");
}

void setDepartmentManager(vector<any>& vault) {
    if (vault.size() <= 2 || vault[2].type() != typeid(Department*)) {
        print(L"Ошибка! Сначала создайте отдел");
        return;
    }

    if (vault.size() <= 3 || vault[3].type() != typeid(Employee*)) {
        print(L"Ошибка! Сначала создайте сотрудника");
        return;
    }

    Department* dept = any_cast<Department*>(vault[2]);
    Employee* emp = any_cast<Employee*>(vault[3]);

    dept->setManager(emp);
    print(L"Сотрудник назначен начальником отдела!");
}

void showEmployee(vector<any>& vault) {
    if (vault.size() <= 3 || vault[3].type() != typeid(Employee*)) {
        print(L"Ошибка! Сначала создайте сотрудника");
        return;
    }

    Employee* emp = any_cast<Employee*>(vault[3]);
    emp->print();
}

void showEmployeesAndDepartment() {
    Department* itDept = new Department(L"IT");

    Employee* petrov = new Employee(L"Петров", itDept);
    Employee* kozlov = new Employee(L"Козлов", itDept);
    Employee* sidorov = new Employee(L"Сидоров", itDept);

    itDept->setManager(kozlov);

    print(L"=== Информация о сотрудниках ===\n");
    petrov->print();
    kozlov->print();
    sidorov->print();

    delete petrov;
    delete kozlov;
    delete sidorov;
    delete itDept;
}
// </Employee>


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
        {L"Создать объект класса", [&objects_vault]() { createHouse(objects_vault); }},
        {L"Получить значение", [&objects_vault]() { getHouse(objects_vault); }},
        {L"Получить количество этажей", [&objects_vault]() { getFloors(objects_vault); }},
        {L"Вывести варианты по заданию (1, 5, 23 этажа)", getHouseVariants}
    };

    menuMap[L"2.1 Сотрудники и отделы"] = {
        {L"Создать отдел", [&objects_vault]() { createDepartment(objects_vault); }},
        {L"Создать сотрудника", [&objects_vault]() { createEmployee(objects_vault); }},
        {L"Назначить сотрудника начальником отдела", [&objects_vault]() { setDepartmentManager(objects_vault); }},
        {L"Показать информацию о сотруднике", [&objects_vault]() { showEmployee(objects_vault); }},
        {L"Показать демонстрацию по заданию (Петров, Козлов, Сидоров)", showEmployeesAndDepartment}
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