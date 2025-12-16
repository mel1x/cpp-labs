#pragma once

#include <string>
#include <vector>

using namespace std;

struct Toy {
    wchar_t name[50];
    double price;
    int minAge;
    int maxAge;
};

class Task3 {
private:
    wstring filename;
    vector<Toy> toys;

public:
    Task3(wstring filename);
    
    void fillFile();

    void addToy(const wstring& name, double price, int minAge, int maxAge);
    
    void loadToys();

    bool findMostExpensive(Toy& result);
    
    void printAllToys();
    void printToy(const Toy& toy);
};