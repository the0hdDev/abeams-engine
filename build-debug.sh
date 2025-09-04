#!/usr/bin/bash
set -euo pipefail

ls

if [ -d "./build" ]; then
    echo "Ordner ./output existiert schon."
else
    echo "Ordner ./output existiert noch nicht, erstelle ihn..."
    mkdir ./build
fi

cd ./build

if [ -d "./output" ]; then
    echo "Ordner ./output existiert schon."
else
    echo "Ordner ./output existiert noch nicht, erstelle ihn..."
    mkdir ./output
fi

sleep 2s
cmake -DCMAKE_BUILD_TYPE=Debug ..
sleep 1s
cmake --build .
sleep 10s
find . -type f -name '*abeams*' -exec mv -v {} ./output/ \;
