#include "house.hpp"
#include <iostream>

using namespace std;

House::House(int floors) : floors(floors) {}

wstring House::toString() const {
    wstring result = L"Дом с " + to_wstring(floors) + L" ";

    int lastDigit = floors % 10;
    int lastTwoDigits = floors % 100;

    if (lastTwoDigits >= 11 && lastTwoDigits <= 14) {
        result += L"этажами";
    }
    else if (lastDigit == 1) {
        result += L"этажом";
    }
    else if (lastDigit >= 2 && lastDigit <= 4) {
        result += L"этажами";
    }
    else {
        result += L"этажами";
    }

    return result;
}

void House::print() const {
    wcout << toString() << endl;
}

int House::getFloors() const {
    return floors;
}
