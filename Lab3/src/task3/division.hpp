#pragma once

#include <string>
#include <vector>

using namespace std;

class Worker;

class Division {
private:
    wstring name;
    Worker* manager;
    vector<Worker*> workers;

public:
    Division(wstring name);

    void addWorker(Worker* worker);
    void removeWorker(Worker* worker);
    void setManager(Worker* manager);
    Worker* getManager() const;
    wstring getName() const;
    vector<Worker*> getAllWorkers() const;
};
