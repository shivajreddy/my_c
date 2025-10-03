cls
@echo off
setlocal enabledelayedexpansion

:: Change this to your source file if needed
set SRC=main.cpp
set OUT=engine.exe

:: Detect the Visual Studio environment (this sets up cl.exe in PATH)
:: Adjust the path below if you use a different VS edition or version
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
cls

echo Compiling %SRC% ...
cl /nologo /std:c++20 /EHsc /W4 /O2 %SRC% /Fe:%OUT%
if errorlevel 1 (
    echo Compilation failed.
    exit /b 1
)
cls

REM echo Running %OUT% ...
%OUT%

endlocal
