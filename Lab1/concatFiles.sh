#!/usr/bin/env bash

echo "Concat one readme file"

if [ -f "$output_file" ]; then
    rm "$output_file"
fi

for dir in task*/; do
    if [ -f "$dir/README.md" ]; then
        echo "Добавляем $dir"
        echo -e "\n# $dir" >> "./README.md"
        cat "$dir/README.md" >> "./README.md"
        echo -e "\n\n" >> "./README.md"
    fi
done