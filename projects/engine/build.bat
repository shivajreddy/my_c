@echo off
setlocal enabledelayedexpansion

:: Project Details
set PROJECT_NAME=engine

:: Source, build, and output directories
set SRC_DIR=src
set BUILD_DIR=build
set BIN_DIR=bin
set OUT=%PROJECT_NAME%.exe

:: Clean old build artifacts
echo Cleaning build directory...
if exist "%BUILD_DIR%" rmdir /s /q "%BUILD_DIR%"
if exist "%BIN_DIR%\%OUT%" del /q "%BIN_DIR%\%OUT%"

:: Ensure build/ and bin/ exist
if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"
if not exist "%BIN_DIR%" mkdir "%BIN_DIR%"

:: Setup MSVC environment
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
cls

:: Collect all .cpp files in src/
set FILES=
for %%f in (%SRC_DIR%\*.cpp) do (
    set FILES=!FILES! %%f
)

echo Compiling sources from %SRC_DIR% ...
cl /nologo /std:c++20 /EHsc /W4 /O2 ^
   /Fo%BUILD_DIR%\ ^
   /Fe%BIN_DIR%\%OUT% ^
   %FILES%

if errorlevel 1 (
    echo Compilation failed.
    exit /b 1
)

cls
REM echo Running %BIN_DIR%\%OUT% ...
%BIN_DIR%\%OUT%

endlocal
