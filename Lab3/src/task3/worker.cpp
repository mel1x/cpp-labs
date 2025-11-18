#include "worker.hpp"
#include <iostream>

using namespace std;

Worker::Worker(wstring name, Division* division)
    : name(name), division(division) {
    if (division != nullptr) {
        division->addWorker(this);
    }
}

Worker::~Worker() {
    if (division != nullptr) {
        division->removeWorker(this);
    }
}

wstring Worker::toString() const {
    if (division == nullptr) {
        return name + L" не работает ни в одном подразделении";
    }

    if (division->getManager() == this) {
        return name + L" начальник подразделения " + division->getName();
    } else {
        wstring result = name + L" работает в подразделении " + division->getName();

        Worker* manager = division->getManager();
        if (manager != nullptr) {
            result += L", начальник которого " + manager->getName();
        }

        return result;
    }
}

void Worker::print() const {
    wcout << toString() << endl;
}

wstring Worker::getName() const {
    return name;
}

Division* Worker::getDivision() const {
    return division;
}

vector<Worker*> Worker::getAllColleagues() const {
    if (division == nullptr) {
        return vector<Worker*>();
    }

    vector<Worker*> allWorkers = division->getAllWorkers();
    vector<Worker*> colleagues;

    for (Worker* w : allWorkers) {
        if (w != this) {
            colleagues.push_back(w);
        }
    }

    return colleagues;
}
