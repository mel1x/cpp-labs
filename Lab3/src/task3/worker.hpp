#pragma once

#include <string>
#include <vector>
#include "division.hpp"

using namespace std;

class Worker {
private:
    wstring name;
    Division* division;

public:
    Worker(wstring name, Division* division);
    ~Worker();

    wstring toString() const;
    void print() const;
    wstring getName() const;
    Division* getDivision() const;
    vector<Worker*> getAllColleagues() const;
};
