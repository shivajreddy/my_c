# Create and go to build directory (sibling of src)
$buildDir = Join-Path $PSScriptRoot "..\build"
New-Item -Path $buildDir -ItemType Directory -Force | Out-Null
Push-Location $buildDir

# Compile all .c files from src directory
$srcDir = $PSScriptRoot  # Since script is in src directory
Write-Host "Compiling..."
gcc (Join-Path $srcDir "*.c") -o game.exe -Wall -Wextra -std=c99 `
    -Wno-missing-braces -I "..\include" -L "..\lib" `
    -lraylib -lopengl32 -lgdi32 -lwinmm

# Check if compilation succeeded
if (Test-Path game.exe) {
    Write-Host "Running the executable..."
    .\game.exe
}
else {
    Write-Host "Compilation failed. Exe not found." -ForegroundColor Red
}

Pop-Location
