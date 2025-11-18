#pragma once

#include <string>
#include "department.hpp"

using namespace std;

class Employee {
private:
    wstring name;
    Department* department;

public:
    Employee(wstring name, Department* department);

    wstring toString() const;
    void print() const;
    wstring getName() const;
    Department* getDepartment() const;
};
