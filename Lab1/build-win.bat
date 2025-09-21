@echo off
chcp 65001 >nul
echo Building all taskN.cpp files...
echo.

REM Create win-builds folder if it doesn't exist
if not exist "win-builds" (
    echo Creating win-builds folder...
    mkdir "win-builds"
)

REM Compile all task*.cpp files from their respective folders
for /d %%d in (task*) do (
    if exist "%%d\%%d.cpp" (
        echo Compiling %%d\%%d.cpp...
        g++ -std=c++23 "%%d\%%d.cpp" -o "win-builds\%%d.exe"
        if errorlevel 1 (
            echo ERROR: Failed to compile %%d\%%d.cpp
        ) else (
            echo SUCCESS: %%d\%%d.cpp compiled to win-builds\%%d.exe
        )
        echo.
    )
)

echo Build completed!
echo Results are in win-builds folder
pause