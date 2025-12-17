#pragma once

#include <string>
#include <vector>

struct Toy {
    wchar_t name[50];
    double price;
    int minAge;
    int maxAge;
};

class Task3 {
private:
    std::wstring filename;
    std::vector<Toy> toys;

public:
    Task3(std::wstring filename);
    
    void fillFile();

    void addToy(const std::wstring& name, double price, int minAge, int maxAge);
    
    void loadToys();

    bool findMostExpensive(Toy& result);
    
    void printAllToys();
    void printToy(const Toy& toy);
};