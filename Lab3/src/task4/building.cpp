#include "building.hpp"
#include <iostream>

using namespace std;

Building::Building(int floors) : floors(floors) {}

wstring Building::toString() const {
    int lastDigit = floors % 10;
    int lastTwoDigits = floors % 100;
    wstring ending;

    if (lastTwoDigits >= 11 && lastTwoDigits <= 14) {
        ending = L"этажами";
    } else if (lastDigit == 1) {
        ending = L"этажом";
    } else {
        ending = L"этажами";
    }

    return L"Здание с " + to_wstring(floors) + L" " + ending;
}

void Building::print() const {
    wcout << toString() << endl;
}

int Building::getFloors() const {
    return floors;
}
