#pragma once

#include <string>

using namespace std;

class Time {
private:
    int totalSeconds;

public:
    Time(int seconds = 0);
    
    wstring toString() const;
    
    void print() const;
    
    int getSeconds() const;
};