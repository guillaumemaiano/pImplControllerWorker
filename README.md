
# pImpl Worker Project

This project demonstrates a small set of **pImpl** (Pointer to Implementation) patterns in C++, designed for clean separation of implementation details.

## Features

- **pImpl Idiom**: Simplifies compilation dependencies and hides implementation details.
- **Worker Class**: Provides a task execution framework.
- Lightweight and modular design.

![Separation of implementation details](Boxes.webp)

## Requirements

- **C++17 or later**
- A compatible C++ compiler (e.g., GCC, Clang, MSVC)
- **CMake** (optional, if a CMake build system is used)

## File Structure

    .
    ├── include/       # Public headers for the pImpl classes
    ├── src/           # Implementation files
    ├── tests/         # Unit tests
    ├── CMakeLists.txt # CMake configuration (optional)
    └── README.md      # Project documentation

### Key Components

- **Worker**: A class that handles background tasks or thread execution.
- **MyClass**: Example pImpl implementation showcasing modularity.

## Usage

### Building

To compile the project using CMake:

```bash
mkdir build && cd build
cmake ..
make
```

If not using CMake, compile manually with a compatible compiler, for example:

```bash
g++ -std=c++17 -Iinclude src/*.cpp -o pimpl_project
```

### Running

Run the compiled executable:

```bash
./pimpl_project
```

## Design Overview

This project employs the **pImpl idiom** to:
- **Improve Encapsulation**: Internal details are hidden from public headers.
- **Minimize Recompilation**: Changes to the implementation do not trigger recompilation of dependent code.

The `Worker` class facilitates task execution, making it easy to integrate multithreading or asynchronous behavior.

## License

This project is licensed under the [MIT License](LICENSE).
