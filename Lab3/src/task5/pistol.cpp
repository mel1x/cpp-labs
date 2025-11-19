#include "pistol.hpp"
#include <iostream>

using namespace std;

Pistol::Pistol() : bullets(5) {}

Pistol::Pistol(int bullets) : bullets(bullets) {}

void Pistol::shoot() {
    if (bullets > 0) {
        wcout << L"Бах!" << endl;
        bullets--;
    } else {
        wcout << L"Клац!" << endl;
    }
}

void Pistol::print() const {
    wcout << L"Пистолет с магазином: " << bullets;
    wcout << endl;
}

int Pistol::getBullets() const {
    return bullets;
}
