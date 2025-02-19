Write-Output "Compiling..."
gcc ./src/main.c -o ./build/out.exe -Wall -Wextra -std=c99 -I .\include\ -L .\libs\ -lraylib -lopengl32 -lgdi32 -lwinmm

Write-Output "successfully written to ./build/out.exe"
