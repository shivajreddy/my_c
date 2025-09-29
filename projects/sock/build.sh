#!/bin/bash

# build.sh - Build script for C socket server

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Project configuration
PROJECT_NAME="sock"
CC=gcc
CFLAGS="-Wall -Wextra -std=c11 -D_POSIX_C_SOURCE=200809L"
LDFLAGS="-lpthread" # For multi-threaded servers

# Directories
SRC_DIR="src"
BUILD_DIR="build"
BIN_DIR="bin"

# Source files (adjust these to your project structure)
# SOURCES="${SRC_DIR}/server.c ${SRC_DIR}/utils.c"
# Or auto-detect all .c files:
SOURCES=$(find ${SRC_DIR} -name "*.c")

OUTPUT="${BIN_DIR}/${PROJECT_NAME}"

# Functions
print_info() {
    echo -e "${GREEN}[INFO]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

create_directories() {
    mkdir -p ${BUILD_DIR}
    mkdir -p ${BIN_DIR}
}

clean() {
    print_info "Cleaning build artifacts..."
    rm -rf ${BUILD_DIR}
    rm -rf ${BIN_DIR}
    print_info "Clean complete"
}

build() {
    print_info "Building ${PROJECT_NAME}..."

    # Create necessary directories
    create_directories

    # Compile
    ${CC} ${CFLAGS} ${SOURCES} -o ${OUTPUT} ${LDFLAGS}

    if [ $? -eq 0 ]; then
        print_info "Build successful!"
        print_info "Executable: ${OUTPUT}"
    else
        print_error "Build failed!"
        exit 1
    fi
}

build_debug() {
    print_info "Building ${PROJECT_NAME} (Debug mode)..."
    CFLAGS="${CFLAGS} -g -O0 -DDEBUG"
    build
}

build_release() {
    print_info "Building ${PROJECT_NAME} (Release mode)..."
    CFLAGS="${CFLAGS} -O2 -DNDEBUG"
    build
}

run() {
    if [ ! -f ${OUTPUT} ]; then
        print_error "Executable not found. Building first..."
        build
    fi

    print_info "Running ${PROJECT_NAME}..."
    ${OUTPUT} "$@"
}

# Main script logic
case "$1" in
clean)
    clean
    ;;
debug)
    build_debug
    ;;
release)
    build_release
    ;;
run)
    shift
    run "$@"
    ;;
buildrun)
    build
    run
    ;;
rebuild)
    clean
    build
    ;;
*)
    echo "Usage: $0 {build|debug|release|clean|rebuild|run}"
    echo ""
    echo "Commands:"
    echo "  build     - Build with default flags"
    echo "  debug     - Build with debug symbols"
    echo "  release   - Build with optimizations"
    echo "  clean     - Remove build artifacts"
    echo "  rebuild   - Clean and build"
    echo "  run       - Build (if needed) and run the server"
    echo "  buildrun  - Build and run the server"
    echo ""

    if [ -z "$1" ]; then
        build
    else
        print_error "Unknown command: $1"
        exit 1
    fi
    ;;
esac
