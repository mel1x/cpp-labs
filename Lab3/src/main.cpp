#include "task1/time.hpp"
#include "task1/house.hpp"
#include "task2/employee.hpp"
#include "task2/department.hpp"
#include "task3/worker.hpp"
#include "task3/division.hpp"
#include "task4/building.hpp"
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

        if (vault.size() > 3 && vault[3].type() == typeid(vector<Employee*>)) {
            vector<Employee*> oldEmployees = any_cast<vector<Employee*>>(vault[3]);
            for (Employee* e : oldEmployees) {
                delete e;
            }
            vault[3] = vector<Employee*>();
            print(L"Предыдущие сотрудники удалены, т.к. привязаны к старому отделу.");
        }
    }

    vault[2] = new Department(name);
    vault[3] = vector<Employee*>();
    print(L"Отдел создан!");
}

void createEmployee(vector<any>& vault) {
    if (vault.size() <= 2 || vault[2].type() != typeid(Department*)) {
        print(L"Ошибка! Сначала создайте отдел");
        return;
    }

    Department* dept = any_cast<Department*>(vault[2]);
    wstring name = input<wstring>(L"Введите имя сотрудника");

    Employee* employee = new Employee(name, dept);

    if (vault.size() <= 3 || vault[3].type() != typeid(vector<Employee*>)) {
        vault[3] = vector<Employee*>();
    }

    vector<Employee*>& employees = any_cast<vector<Employee*>&>(vault[3]);
    employees.push_back(employee);

    print(L"Сотрудник создан и добавлен в отдел!");
}

void setDepartmentManager(vector<any>& vault) {
    if (vault.size() <= 2 || vault[2].type() != typeid(Department*)) {
        print(L"Ошибка! Сначала создайте отдел");
        return;
    }

    if (vault.size() <= 3 || vault[3].type() != typeid(vector<Employee*>)) {
        print(L"Ошибка! Сначала создайте сотрудников");
        return;
    }

    Department* dept = any_cast<Department*>(vault[2]);
    vector<Employee*>& employees = any_cast<vector<Employee*>&>(vault[3]);

    if (employees.empty()) {
        print(L"Ошибка! Нет сотрудников для назначения");
        return;
    }

    print(L"Выберите сотрудника для назначения начальником:");
    for (size_t i = 0; i < employees.size(); i++) {
        print(to_wstring(i + 1) + L")", employees[i]->getName());
    }

    int choice = input<int>(L"Введите номер сотрудника",
                           [&](int x) { return x > 0 && x <= employees.size(); },
                           L"Ошибка! Введите число от 1 до " + to_wstring(employees.size()));

    dept->setManager(employees[choice - 1]);
    print(L"Сотрудник назначен начальником отдела!");
}

void showEmployee(vector<any>& vault) {
    if (vault.size() <= 3 || vault[3].type() != typeid(vector<Employee*>)) {
        print(L"Ошибка! Сначала создайте сотрудников");
        return;
    }

    vector<Employee*>& employees = any_cast<vector<Employee*>&>(vault[3]);

    if (employees.empty()) {
        print(L"Ошибка! Нет сотрудников для отображения");
        return;
    }

    print(L"Выберите сотрудника для отображения:");
    for (size_t i = 0; i < employees.size(); i++) {
        print(to_wstring(i + 1) + L")", employees[i]->getName());
    }

    int choice = input<int>(L"Введите номер сотрудника",
                           [&](int x) { return x > 0 && x <= employees.size(); },
                           L"Ошибка! Введите число от 1 до " + to_wstring(employees.size()));

    employees[choice - 1]->print();
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


// <Worker>
void createDivision(vector<any>& vault) {
    wstring name = input<wstring>(L"Введите название подразделения");

    if (vault.size() > 4 && vault[4].type() == typeid(Division*)) {
        Division* oldDiv = any_cast<Division*>(vault[4]);
        delete oldDiv;

        if (vault.size() > 5 && vault[5].type() == typeid(vector<Worker*>)) {
            vector<Worker*> oldWorkers = any_cast<vector<Worker*>>(vault[5]);
            for (Worker* w : oldWorkers) {
                delete w;
            }
            vault[5] = vector<Worker*>();
            print(L"Предыдущие работники удалены, т.к. привязаны к старому подразделению.");
        }
    }

    vault[4] = new Division(name);
    vault[5] = vector<Worker*>();
    print(L"Подразделение создано!");
}

void createWorker(vector<any>& vault) {
    if (vault.size() <= 4 || vault[4].type() != typeid(Division*)) {
        print(L"Ошибка! Сначала создайте подразделение");
        return;
    }

    Division* div = any_cast<Division*>(vault[4]);
    wstring name = input<wstring>(L"Введите имя работника");

    Worker* worker = new Worker(name, div);

    if (vault.size() <= 5 || vault[5].type() != typeid(vector<Worker*>)) {
        vault[5] = vector<Worker*>();
    }

    vector<Worker*>& workers = any_cast<vector<Worker*>&>(vault[5]);
    workers.push_back(worker);

    print(L"Работник создан и добавлен в подразделение!");
}

void setDivisionManager(vector<any>& vault) {
    if (vault.size() <= 4 || vault[4].type() != typeid(Division*)) {
        print(L"Ошибка! Сначала создайте подразделение");
        return;
    }

    if (vault.size() <= 5 || vault[5].type() != typeid(vector<Worker*>)) {
        print(L"Ошибка! Сначала создайте работников");
        return;
    }

    Division* div = any_cast<Division*>(vault[4]);
    vector<Worker*>& workers = any_cast<vector<Worker*>&>(vault[5]);

    if (workers.empty()) {
        print(L"Ошибка! Нет работников для назначения");
        return;
    }

    print(L"Выберите работника для назначения начальником:");
    for (size_t i = 0; i < workers.size(); i++) {
        print(to_wstring(i + 1) + L")", workers[i]->getName());
    }

    int choice = input<int>(L"Введите номер работника",
                           [&](int x) { return x > 0 && x <= workers.size(); },
                           L"Ошибка! Введите число от 1 до " + to_wstring(workers.size()));

    div->setManager(workers[choice - 1]);
    print(L"Работник назначен начальником подразделения!");
}

void showWorker(vector<any>& vault) {
    if (vault.size() <= 5 || vault[5].type() != typeid(vector<Worker*>)) {
        print(L"Ошибка! Сначала создайте работников");
        return;
    }

    vector<Worker*>& workers = any_cast<vector<Worker*>&>(vault[5]);

    if (workers.empty()) {
        print(L"Ошибка! Нет работников для отображения");
        return;
    }

    print(L"Выберите работника для отображения:");
    for (size_t i = 0; i < workers.size(); i++) {
        print(to_wstring(i + 1) + L")", workers[i]->getName());
    }

    int choice = input<int>(L"Введите номер работника",
                           [&](int x) { return x > 0 && x <= workers.size(); },
                           L"Ошибка! Введите число от 1 до " + to_wstring(workers.size()));

    workers[choice - 1]->print();
}

void showAllColleagues(vector<any>& vault) {
    if (vault.size() <= 5 || vault[5].type() != typeid(vector<Worker*>)) {
        print(L"Ошибка! Сначала создайте работников");
        return;
    }

    vector<Worker*>& workers = any_cast<vector<Worker*>&>(vault[5]);

    if (workers.empty()) {
        print(L"Ошибка! Нет работников для отображения");
        return;
    }

    print(L"Выберите работника, чтобы увидеть всех его коллег:");
    for (size_t i = 0; i < workers.size(); i++) {
        print(to_wstring(i + 1) + L")", workers[i]->getName());
    }

    int choice = input<int>(L"Введите номер работника",
                           [&](int x) { return x > 0 && x <= workers.size(); },
                           L"Ошибка! Введите число от 1 до " + to_wstring(workers.size()));

    Worker* selectedWorker = workers[choice - 1];
    vector<Worker*> colleagues = selectedWorker->getAllColleagues();

    print(L"\n=== Все работники подразделения '", selectedWorker->getDivision()->getName(), L"' ===");
    for (Worker* w : colleagues) {
        wcout << L"  - " << w->getName() << endl;
    }
    print(L"Всего работников: ", colleagues.size());
}

void showWorkersAndDivisionDemo() {
    Division* itDiv = new Division(L"IT");

    Worker* petrov = new Worker(L"Петров", itDiv);
    Worker* kozlov = new Worker(L"Козлов", itDiv);
    Worker* sidorov = new Worker(L"Сидоров", itDiv);
    Worker* ivanov = new Worker(L"Иванов", itDiv);

    itDiv->setManager(kozlov);

    print(L"=== Информация о работниках ===\n");
    petrov->print();
    kozlov->print();
    sidorov->print();
    ivanov->print();

    print(L"\n=== Демонстрация: получение списка коллег через работника ===");
    print(L"Получаем всех коллег через Петрова:");
    vector<Worker*> colleagues = petrov->getAllColleagues();
    for (Worker* w : colleagues) {
        wcout << L"  - " << w->getName() << endl;
    }

    delete petrov;
    delete kozlov;
    delete sidorov;
    delete ivanov;
    delete itDiv;
}
// </Worker>


// <Building>
void createBuilding(vector<any>& vault) {
    vault[6] = Building(input<int>(L"Введите количество этажей", [](int x) { return x > 0; }));
    print(L"Объект Building создан!");
}

void getBuilding(vector<any>& vault) {
    if (vault.size() <= 6 || vault[6].type() != typeid(Building)) {
        wcout << L"Ошибка! Создайте объект здания" << endl;
        return;
    }
    any_cast<Building>(vault[6]).print();
}

void getBuildingFloors(vector<any>& vault) {
    if (vault.size() <= 6 || vault[6].type() != typeid(Building)) {
        wcout << L"Ошибка! Создайте объект здания" << endl;
        return;
    }
    print(L"Количество этажей: ", any_cast<Building>(vault[6]).getFloors());
}

void showBuildingVariants() {
    print(L"2 этажа:", Building(2).toString());
    print(L"35 этажей:", Building(35).toString());
    print(L"91 этаж:", Building(91).toString());
}

void demonstrateImmutability() {
    print(L"=== Демонстрация неизменяемости количества этажей ===\n");

    Building building(10);
    print(L"Создано здание:");
    building.print();

    print(L"\n--- Попытка изменить количество этажей ---");

    print(L"\nСоздаем новое здание с 20 этажами:");
    Building newBuilding(20);
    newBuilding.print();

    print(L"\nПервое здание осталось неизменным:");
    building.print();
}
// </Building>


int main() {
    setRuLocale();
    
    vector<any> objects_vault(32);
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

    menuMap[L"2.4 Сотрудники и отделы"] = {
        {L"Создать отдел", [&objects_vault]() { createDepartment(objects_vault); }},
        {L"Создать сотрудника", [&objects_vault]() { createEmployee(objects_vault); }},
        {L"Назначить сотрудника начальником отдела", [&objects_vault]() { setDepartmentManager(objects_vault); }},
        {L"Показать информацию о сотруднике", [&objects_vault]() { showEmployee(objects_vault); }},
        {L"Показать демонстрацию по заданию (Петров, Козлов, Сидоров)", showEmployeesAndDepartment}
    };

    menuMap[L"3.4 Работники и подразделения"] = {
        {L"Создать подразделение", [&objects_vault]() { createDivision(objects_vault); }},
        {L"Создать работника", [&objects_vault]() { createWorker(objects_vault); }},
        {L"Назначить работника начальником подразделения", [&objects_vault]() { setDivisionManager(objects_vault); }},
        {L"Показать информацию о работнике", [&objects_vault]() { showWorker(objects_vault); }},
        {L"Показать всех коллег работника (по отделу)", [&objects_vault]() { showAllColleagues(objects_vault); }},
        {L"Показать демонстрацию по заданию", showWorkersAndDivisionDemo}
    };

    menuMap[L"4.3 Здание"] = {
        {L"Создать объект класса", [&objects_vault]() { createBuilding(objects_vault); }},
        {L"Получить значение", [&objects_vault]() { getBuilding(objects_vault); }},
        {L"Получить количество этажей", [&objects_vault]() { getBuildingFloors(objects_vault); }},
        {L"Вывести варианты по заданию (2, 35, 91 этаж)", showBuildingVariants},
        {L"Демонстрация неизменяемости этажей", demonstrateImmutability}
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