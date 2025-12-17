#include "task1/task1.hpp"
#include "task2/task2.hpp"
#include "task3/task3.hpp"
#include "task4/task4.hpp"
#include "task5/task5.hpp"
#include "task6/task6.hpp"
#include "utils.hpp"
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <functional>


// <Task1>
void getOutFile(Task1 &taskSlot) {
    int k = input<int>(L"Введите k", [](int x) { return x >= 0; });
    taskSlot.copyMultiplesOfK(k);
}
// </Task1>

int main() {
    setRuLocale();

    Task1 task1Slot = Task1(L"task1.bin", L"task1_out.bin");
    Task2 task2Slot = Task2(L"task2.bin", 5);
    Task3 task3Slot = Task3(L"task3.bin");
    Task4 task4Slot = Task4(L"task4.txt");
    Task5 task5Slot = Task5(L"task5.txt");
    Task6 task6Slot = Task6(L"task6.txt", L"task6_out.txt");
    
    map<std::wstring, std::vector<MenuItem>> menuMap;

    menuMap[L"1.6 Элементы кратные k"] = {
        {L"Создать бинарный файл", [&task1Slot]() { 
            task1Slot.fillFile(10, 0, 10); 
        }},
        {L"Вынести элементы кратные k", [&task1Slot]() { 
            getOutFile(task1Slot); 
        }},
        {L"Прочесть первый файл", [&task1Slot]() { 
            task1Slot.printFile(L"task1.bin"); 
        }},
        {L"Прочесть второй файл", [&task1Slot]() { 
            task1Slot.printFile(L"task1_out.bin"); 
        }}
    };

    menuMap[L"2.6 Матрица из элементов"] = {
        {L"Создать бинарный файл", [&task2Slot]() { 
            task2Slot.fillFile(22, 0, 10); 
        }},
        {L"Создать матрицу", [&task2Slot]() { 
            task2Slot.loadMatrix(); 
        }},
        {L"Заменить столбцы матрицы", [&task2Slot]() { 
            task2Slot.replaceColumns(); 
        }},
        {L"Прочесть первый файл", [&task2Slot]() { 
            task2Slot.printFile(); 
        }},
        {L"Прочесть матрицу", [&task2Slot]() { 
            task2Slot.printMatrix(); 
        }}
    };

    menuMap[L"3.6 Структуры в файле"] = {
        {L"Создать бинарный файл", [&task3Slot]() { 
            task3Slot.fillFile();
        }},
        {L"Добавить игрушку в файл", [&task3Slot]() { 
            std::wstring toyName = input<std::wstring>(L"Введите название игрушки", [](std::wstring x) { return x.length() > 0; });
            double toyPrice = input<double>(L"Введите цену", [](double x) { return x > 0; });
            int toyMinAge = input<int>(L"Введите мин.возраст", [](int x) { return x >= 0; });
            int toyMaxAge = input<int>(L"Введите макс.возраст", [&toyMinAge](int x) { return x >= 0 and x >= toyMinAge; });

            task3Slot.addToy(toyName, toyPrice, toyMinAge, toyMaxAge);
        }},
        {L"Поиск самого дорогого конструктора", [&task3Slot]() { 
            Toy mostExpensive;

            if (task3Slot.findMostExpensive(mostExpensive)) {
                print();
                print(L"Найден самый дорогой конструктор:");
                print();
                task3Slot.printToy(mostExpensive);
            } else {
                print(L"Конструкторы не найдены в файле!");
            }
        }},
        {L"Вывод всех игрушек", [&task3Slot]() { 
            task3Slot.printAllToys();
        }},
    };

    menuMap[L"4.6 Сумма по индексам"] = {
        {L"Создать текстовый файл", [&task4Slot]() { 
            task4Slot.fillFile(20, 0, 10); 
        }},
        {L"Найти сумму элементов по своим индексам", [&task4Slot]() { 
            task4Slot.findSum(); 
        }},
        {L"Вывести файл", [&task4Slot]() { 
            task4Slot.printFile();
        }},
        {L"Вывести элементы по индексам", [&task4Slot]() { 
            task4Slot.printIndexes();
        }},
    };

    menuMap[L"5.6 Произведение кратных k"] = {
        {L"Создать текстовый файл", [&task5Slot]() { 
            task5Slot.fillFile(10, 3, 0, 10); 
        }},
        {L"Найти сумму элементов кратных k", [&task5Slot]() { 
            int k = input<int>(L"Введите k", [](int x) { return x >= 0; });
            task5Slot.calculateMult(k); 
        }},
        {L"Вывести файл", [&task5Slot]() { 
            task5Slot.printFile();
        }},
        {L"Вывести элементы кратные k", [&task5Slot]() { 
            int k = input<int>(L"Введите k", [](int x) { return x >= 0; });
            task5Slot.printNumbers(k);
        }},
    };

    menuMap[L"6.6 Копирование текста"] = {
        {L"Создать текстовый файл", [&task6Slot]() { 
            task6Slot.createFile();
        }},
        {L"Добавить строчку в файл", [&task6Slot]() { 
            std::wstring newLine = input<std::wstring>(L"Введите строку");
            task6Slot.addFileLine(newLine); 
        }},
        {L"Скопировать строки без en символов", [&task6Slot]() { 
            task6Slot.copyLines();
        }},
        {L"Вывести первый файл", [&task6Slot]() { 
            task6Slot.printFile(L"task6.txt");
        }},
        {L"Вывести второй файл", [&task6Slot]() { 
            task6Slot.printFile(L"task6_out.txt");
        }},
    };

    createMenu(menuMap);
}