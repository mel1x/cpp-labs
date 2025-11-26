chcp 65001
@echo off
setlocal enabledelayedexpansion

cd src

echo Компиляция объектных файлов...

REM Компиляция всех cpp файлов в src/
for %%f in (*.cpp) do (
    echo   Компилирую %%f...
    g++ -std=c++23 -O2 -march=native -I. -c %%f -o %%~nf.o
    if !ERRORLEVEL! NEQ 0 (
        echo.
        echo Ошибка при компиляции %%f!
        cd ..
        exit /b 1
    )
)

REM Компиляция всех cpp файлов в подпапках (task1, task2, и т.д.)
for /R %%f in (*.cpp) do (
    REM Пропускаем файлы, которые уже скомпилированы выше
    if not "%%~dpf"=="%CD%\" (
        echo   Компилирую %%f...
        g++ -std=c++23 -O2 -march=native -I. -I%%~dpf -c %%f -o %%~nf.o
        if !ERRORLEVEL! NEQ 0 (
            echo.
            echo Ошибка при компиляции %%f!
            cd ..
            exit /b 1
        )
    )
)

echo Линковка...
g++ -std=c++23 -O2 -march=native -flto -o ../main.exe *.o

if !ERRORLEVEL! EQU 0 (
    echo.
    echo Очистка объектных файлов...
    del *.o
    echo Сборка успешна!
    echo Файл: main.exe
    echo.
) else (
    echo.
    echo Ошибка линковки!
    del *.o
    cd ..
    exit /b 1
)
cd ..