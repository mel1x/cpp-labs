#include "time.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

Time::Time(int seconds) {
    totalSeconds = seconds % 86400;
    
    if (totalSeconds < 0) {
        totalSeconds += 86400;
    }
}

wstring Time::toString() const {
    int hours = totalSeconds / 3600;
    int minutes = (totalSeconds % 3600) / 60;
    int seconds = totalSeconds % 60;
    
    wostringstream oss;
    oss << hours << L":"
        << setw(2) << setfill(L'0') << minutes << L":"
        << setw(2) << setfill(L'0') << seconds;
    
    return oss.str();
}

void Time::print() const {
    wcout << toString() << endl;
}

int Time::getSeconds() const {
    return totalSeconds;
}