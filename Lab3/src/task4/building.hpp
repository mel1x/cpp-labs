#pragma once

#include <string>

using namespace std;

class Building {
private:
    const int floors;

public:
    Building(int floors);

    wstring toString() const;
    void print() const;
    int getFloors() const;
};
