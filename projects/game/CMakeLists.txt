cmake_minimum_required(VERSION 3.15)
project(game C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # Critical for LSP support

# Include directories
include_directories(include)

# Find source files
file(GLOB SOURCES "src/*.c")

# Link directories
link_directories(lib)

# Create executable
add_executable(game ${SOURCES})

# Link libraries
target_link_libraries(game 
    raylib 
    opengl32 
    gdi32 
    winmm)

# Output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
