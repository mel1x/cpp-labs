#!/bin/bash

cd src

echo "Компиляция объектных файлов..."

# Компиляция всех cpp файлов в src/
for f in *.cpp; do
    if [ -f "$f" ]; then
        echo "  Компилирую $f..."
        g++ -std=c++23 -O2 -march=native -I. -c "$f" -o "${f%.cpp}.o"
        if [ $? -ne 0 ]; then
            echo ""
            echo "Ошибка при компиляции $f!"
            cd ..
            exit 1
        fi
    fi
done

# Компиляция всех cpp файлов в подпапках (task1, task2, и т.д.)
find . -mindepth 2 -name "*.cpp" | while read f; do
    echo "  Компилирую $f..."
    # Получаем имя файла без пути и расширения
    filename=$(basename "$f" .cpp)
    # Получаем директорию файла для -I
    filedir=$(dirname "$f")

    g++ -std=c++23 -O2 -march=native -I. -I"$filedir" -c "$f" -o "${filename}.o"
    if [ $? -ne 0 ]; then
        echo ""
        echo "Ошибка при компиляции $f!"
        cd ..
        exit 1
    fi
done

echo "Линковка..."
g++ -std=c++23 -O2 -march=native -flto -o ../main.out *.o

if [ $? -eq 0 ]; then
    echo ""
    echo "Очистка объектных файлов..."
    rm -f *.o
    echo "Сборка успешна!"
    echo "Файл: main.out"
    chmod +x ../main.out
    echo ""
else
    echo ""
    echo "Ошибка линковки!"
    rm -f *.o
    cd ..
    exit 1
fi

cd ..
