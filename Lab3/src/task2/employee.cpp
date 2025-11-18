#include "employee.hpp"
#include <iostream>

using namespace std;

Employee::Employee(wstring name, Department* department)
    : name(name), department(department) {}

wstring Employee::toString() const {
    if (department == nullptr) {
        return name + L" не работает ни в одном отделе";
    }

    if (department->getManager() == this) {
        return name + L" начальник отдела " + department->getName();
    } else {
        wstring result = name + L" работает в отделе " + department->getName();

        Employee* manager = department->getManager();
        if (manager != nullptr) {
            result += L", начальник которого " + manager->getName();
        }

        return result;
    }
}

void Employee::print() const {
    wcout << toString() << endl;
}

wstring Employee::getName() const {
    return name;
}

Department* Employee::getDepartment() const {
    return department;
}
