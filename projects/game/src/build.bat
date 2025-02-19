@echo off
setlocal

:: Navigate to project root (assuming script is in src/)
cd /d %~dp0..

:: Create build directory if it doesn't exist
mkdir build 2>nul

:: Compile all .c files from src directory
gcc src\*.c -o build\game.exe -Wall -Wextra -std=c99 ^
    -Wno-missing-braces -I include -L lib ^
    -lraylib -lopengl32 -lgdi32 -lwinmm

:: Check if compilation succeeded
if exist build\game.exe (
    echo Running the executable...
    cd build
    game.exe
    cd ..
) else (
    echo Compilation failed. Exe not found.
    exit /b 1
)

endlocal
