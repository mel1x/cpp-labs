#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'


OUTPUT="main"

BUILD_DIR="build"

CXX="g++"

CXXFLAGS="-O2 -std=c++23"


echo -e "${BLUE}================================${NC}"
echo -e "${BLUE}  Сборка проекта${NC}"
echo -e "${BLUE}================================${NC}"

if [ ! -d "$BUILD_DIR" ]; then
    echo -e "${YELLOW}Создаём папку $BUILD_DIR...${NC}"
    mkdir -p "$BUILD_DIR"
fi


echo -e "${YELLOW}Поиск исходных файлов...${NC}"
SOURCE_FILES=$(find src -name "*.cpp")


if [ -z "$SOURCE_FILES" ]; then
    echo -e "${RED}Ошибка: не найдено ни одного .cpp файла!${NC}"
    exit 1
fi

echo -e "${GREEN}Найдены файлы:${NC}"
for file in $SOURCE_FILES; do
    echo -e "  - $file"
done


echo -e "${YELLOW}Компиляция...${NC}"
$CXX $CXXFLAGS $SOURCE_FILES -o "$BUILD_DIR/$OUTPUT"

if [ $? -eq 0 ]; then
    echo -e "${GREEN}================================${NC}"
    echo -e "${GREEN}  Сборка успешна!${NC}"
    echo -e "${GREEN}================================${NC}"
    echo -e "${GREEN}Исполняемый файл: $BUILD_DIR/$OUTPUT${NC}"
    echo -e ""
    echo -e "Для запуска используйте:"
    echo -e "${BLUE}  ./$BUILD_DIR/$OUTPUT${NC}"
    echo -e "или"
    echo -e "${BLUE}  cd $BUILD_DIR && ./$OUTPUT${NC}"
else
    echo -e "${RED}================================${NC}"
    echo -e "${RED}  Ошибка компиляции!${NC}"
    echo -e "${RED}================================${NC}"
    exit 1
fi