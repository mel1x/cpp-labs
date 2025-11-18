#pragma once

#include <string>
#include <vector>

using namespace std;

class Employee;

class Department {
private:
    wstring name;
    Employee* manager;

public:
    Department(wstring name);

    void setManager(Employee* manager);
    Employee* getManager() const;
    wstring getName() const;
};
