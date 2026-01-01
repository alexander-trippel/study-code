# Lab 8: Modular Playlist Manager

## Section I

### Introduction
In this lab, you will enhance your existing playlist program by making it modular.  
The goal is to **separate declarations and implementations** and use **header files** to structure your program.

You will learn:

- how to organize C code into multiple files
- how to use `struct` and `typedef` in a modular program
- how to use **header guards** to avoid multiple inclusions
- how to maintain and extend code more easily

### Requirements

1. Create three files:
   - `playlist.h` → declarations of structs and functions
   - `playlist.c` → implementation of playlist functions
   - `main.c` → main program that uses the playlist API

2.  Use the following folder structure:
    
```text
project/
├── main.c
├── src/
│   └── playlist.c
└── include/
    └── playlist.h
```

3. Use **header guards** in `playlist.h`.

4. Introduce a **preprocessor macro `MAX_SONGS`** in `playlist.h`:
   - Defines the **maximum number of songs allowed in a playlist**
   - `add_song` must **check this limit** before adding a new song
   - If the limit is reached, print an error message and do not add the song

### Hints

- The `playlist.h` file should only contain **declarations**, not function definitions
- Use the following command in the terminal to build the app: gcc -I./include main.c src/playlist.c -o playlist_app
- Use the following command to run the build app via terminal: .\playlist_app.exe
- Not: The command above needs to be adjusted on other operating systems (usually without .exe)

## Section II: Building the Project with CMake

This section explains how to build the project using **CMake** on all major operating systems.  
CMake is a cross-platform build system generator that creates platform-specific build files.

### Requirements

1. Check if cmake is already installed by using: cmake --version
2. If not: Install cmake

   - Windows: Download the installer (.msi) from [cmake.org](https://cmake.org/download/). Check the box "Add CMake to Path" in installer
   - Linux: sudo apt install cmake
   - macOS: brew install cmake

3. Navigate into your project of section I and create a file called CMakeLists.txt
4. Copy the following content into it:

```C
cmake_minimum_required(VERSION 3.10)

project(playlist_app C)

# C-Standard festlegen
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Include-Verzeichnis
include_directories(include)

# Executable definieren
add_executable(playlist_app
    main.c
    src/playlist.c
)

```
5. Create a folder called build in the project and navigate into it
6. Run the command:
```c
cmake -G "MinGW Makefiles" ..
```
7. Then build the project with:
```c
cmake --build .
```
8. Now you can run the created playlist_app.exe in the build folder
