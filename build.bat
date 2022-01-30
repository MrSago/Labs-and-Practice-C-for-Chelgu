
@echo off

if ["%~2"] == [""] (
    echo "Syntax: . \build.bat [config: release\debug] [target]"
    exit
)

mkdir build 2>nul

if ["%~1"] == ["release"] (
    cmake -DCMAKE_BUILD_TYPE:STRING=Release -H.\ -B.\build -G "MinGW Makefiles"
    cmake --build build\ --config Release --target %~2 -j 4
    exit
)

if ["%~1"] == ["debug"] (
    cmake -DCMAKE_BUILD_TYPE:STRING=Debug -H.\ -B.\build -G "MinGW Makefiles"
    cmake --build build\ --config Debug --target %~2 -j 4
    exit
)

echo "unknown config"

