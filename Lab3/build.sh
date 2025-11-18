#!/bin/bash

echo "Компиляция main.cpp..."
g++ -std=c++23 -O2 -Wall -Wextra -march=native -flto -o ../main.out main.cpp

cd src

if [ $? -eq 0 ]; then
    echo ""
    echo -e "\eСборка успешна!\e"
    echo "Файл: main.out"
    chmod +x main.out
    echo ""
else
    echo ""
    echo -e "\eОшибка компиляции!\e"
    exit 1
fi

cd ..