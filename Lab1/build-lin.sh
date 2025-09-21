#!/bin/bash

echo "Building all taskN.cpp files for Linux..."
echo

# Create lin-builds folder if it doesn't exist
if [ ! -d "lin-builds" ]; then
    echo "Creating lin-builds folder..."
    mkdir -p "lin-builds"
fi

# Compile all task*.cpp files from their respective folders
for dir in task*/; do
    if [ -d "$dir" ]; then
        taskname=$(basename "$dir")
        if [ -f "$dir/${taskname}.cpp" ]; then
            echo "Compiling $dir${taskname}.cpp..."
            g++ -std=c++23 "$dir${taskname}.cpp" -o "lin-builds/${taskname}.out"
            
            if [ $? -eq 0 ]; then
                echo "SUCCESS: $dir${taskname}.cpp compiled to lin-builds/${taskname}.out"
            else
                echo "ERROR: Failed to compile $dir${taskname}.cpp"
            fi
            echo
        fi
    fi
done

echo "Build completed!"
echo "Results are in lin-builds/ folder"

# Make all .out files executable
chmod +x lin-builds/*.out 2>/dev/null

echo "All executables have been made executable"