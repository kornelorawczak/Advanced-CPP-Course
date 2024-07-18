@echo off

g++ main.cpp

if %errorlevel% equ 0 (
    .\a.exe
) else (
    echo Compilation failed.
)

