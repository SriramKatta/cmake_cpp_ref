# CMake with Nested Folder Structure

This repository demonstrates a very basic C++ project setup using CMake with a nested folder structure. It is designed to help you understand how to organize your project and configure CMake to build it effectively.

## Project Structure

Here is a simple flow chart:

```
cmake_cpp_ref/
├── header
│   └── header.hpp
├── src
│   ├── main
│   │   ├── CMakeLists.txt
│   │   └── main.cpp
│   └── CMakeLists.txt
├── CMakeLists.txt
├── LICENSE
└── README.md
```

## How It Works

1. **Root `CMakeLists.txt`**:
    - Defines the project name and version.
    - Specifies the minimum required CMake version.
    - Includes the `src` folder for further configuration.

2. **`src/CMakeLists.txt`**:
    - Adds the executable target (e.g., `main.cpp`).
    - Links the library from the `lib` folder.

3. **`src/lib/CMakeLists.txt`**:
    - Defines the library target (e.g., `mylib`).
    - Specifies the source files for the library.

## Build Instructions

1. Clone the repository:

    ```bash
    git clone <repository-url>
    cd cmake_cpp_ref
    ```

2. Create a build directory and navigate to it:

    ```bash
    mkdir build
    cd build
    ```

3. Run CMake to configure the project:

    ```bash
    cmake ..
    ```

4. Build the project:

    ```bash
    cmake --build .
    ```

5. Run the executable:

    ```bash
    ./<executable-name>
    ```

## Key Points

- The project demonstrates how to use CMake with a nested folder structure.
- Each folder has its own `CMakeLists.txt` for modular configuration.
- The `lib` folder contains a simple library that is linked to the main executable.

Feel free to explore the code and modify it to suit your needs!
