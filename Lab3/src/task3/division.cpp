#include "division.hpp"
#include <algorithm>

using namespace std;

Division::Division(wstring name) : name(name), manager(nullptr) {}

void Division::addWorker(Worker* worker) {
    auto it = find(workers.begin(), workers.end(), worker);
    if (it == workers.end()) {
        workers.push_back(worker);
    }
}

void Division::removeWorker(Worker* worker) {
    auto it = find(workers.begin(), workers.end(), worker);
    if (it != workers.end()) {
        workers.erase(it);
    }
}

void Division::setManager(Worker* manager) {
    this->manager = manager;
}

Worker* Division::getManager() const {
    return manager;
}

wstring Division::getName() const {
    return name;
}

vector<Worker*> Division::getAllWorkers() const {
    return workers;
}
