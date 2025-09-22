@echo off
echo Compiling...
gcc .\src\main.c -o .\build\out.exe -Wall -Wextra -std=c99 -I .\include\ -L .\lib\ -lraylib -lopengl32 -lgdi32 -lwinmm

if %errorlevel% equ 0 (
    echo Compilation successful.

    if "%~3"=="" (
        if "%~2"=="" (
            if "%~1"=="" (
                echo Running with default timer...
                .\build\out.exe
            ) else (
                echo Running with seconds: %1
                .\build\out.exe %1
            )
        ) else (
            echo Running with minutes: %1, seconds: %2
            .\build\out.exe %1 %2
        )
    ) else (
        echo Running with hours: %1, minutes: %2, seconds: %3
        .\build\out.exe %1 %2 %3
    )
) else (
    echo Compilation failed.
)
