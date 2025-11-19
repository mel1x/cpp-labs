#pragma once

#include <string>

using namespace std;

class Pistol {
private:
    int bullets;

public:
    Pistol();
    Pistol(int bullets);

    void shoot();
    void print() const;
    int getBullets() const;
};
