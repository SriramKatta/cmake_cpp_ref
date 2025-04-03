# CMake with Nested Folder Structure

This repository demonstrates a basic C++ project setup using CMake with a nested folder structure. It is designed to help you understand how to organize your project and configure CMake to build it effectively with cmake.

## Project Structure

```
cmake_cpp_ref/
├── .gitignore
├── CMakeLists.txt
├── LICENSE
├── README.md
├── cmake
│   ├── CPM.cmake
│   └── eigen.cmake
├── header
│   └── header.hpp
└── src
    ├── CMakeLists.txt
    └── main
        ├── CMakeLists.txt
        └── main.cpp
```

## How It Works

1. **Root `CMakeLists.txt`**:
    - Defines the project name and version.
    - Specifies the minimum required CMake version.
    - Includes the `src` folder for further configuration.
    - Includes eigen and cpm package manger

2. **`src/CMakeLists.txt`**:
    - Adds subdirectory `main`

3. **`src/main/CMakeLists.txt`**:
    - Adds the executable target (e.g., `main.cpp`).
    - Links the library from the `Eigen` folder.


## Build Instructions

1. Clone the repository:

    ```bash
    git clone <repository-url>
    cd cmake_cpp_ref
    ```

2. Run CMake to configure the project:

    ```bash
    cmake -S . -B build
    ```

3. Build the project:

    ```bash
    cmake --build build -j
    ```

4. Run the executable:

    ```bash
    ./executable/<exe_name>
    ```

## Key Points

- The project demonstrates how to use CMake with a nested folder structure.
- Each folder has its own `CMakeLists.txt` for modular configuration.
- The `header` folder contains a simple header file that is linked to the main executable.

Feel free to explore the code and modify it to suit your needs!
