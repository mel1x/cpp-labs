#include "department.hpp"

using namespace std;

Department::Department(wstring name) : name(name), manager(nullptr) {}

void Department::setManager(Employee* manager) {
    this->manager = manager;
}

Employee* Department::getManager() const {
    return manager;
}

wstring Department::getName() const {
    return name;
}
