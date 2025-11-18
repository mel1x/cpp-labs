#pragma once

#include <string>

using namespace std;

class House {
private:
    int floors;

public:
    House(int floors = 1);

    wstring toString() const;

    void print() const;

    int getFloors() const;
};
