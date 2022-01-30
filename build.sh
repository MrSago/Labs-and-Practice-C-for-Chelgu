
#!/bin/bash

if test $# -ne 2
then
    echo "Syntax: ./build.sh [config: release/debug] [target]"
    exit
fi

mkdir -p build

if [ "$1" = "release" ]
then
    cmake -DCMAKE_BUILD_TYPE:STRING=Release -H./ -B./build
    cmake --build build/ --config Release --target $2 -j 4
elif [ "$1" = "debug" ]
then
    cmake -DCMAKE_BUILD_TYPE:STRING=Debug -H./ -B./build
    cmake --build build/ --config Debug --target $2 -j 4
else
    echo "unknown config"
fi

