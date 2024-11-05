#!/bin/bash

[ -d "build" ] || mkdir build
cmake -S . -B build
cmake --build build

./build/game.out