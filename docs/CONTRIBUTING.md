# Contributing to the Project

Thank you for considering contributing to this project! Please follow these guidelines to ensure that your contribution aligns with the project’s coding style and standards.

## Code Style

### Naming Conventions
Follow these naming conventions for consistency throughout the project:

- **Functions**: `PascalCase`
- **Members**: `PascalCase`
- **Classes/Structs**: `PascalCase`
- **Namespaces**: `PascalCase`
- **Folders**: `snake_case`
- **File Names**: `snake_case`
- **Variables**: `camelCase`
- **Constants**: `MACRO_CASE`
- **Static Variables**: `PascalCase`
- **Instance Members/Attributes/Fields**: `camelCase`
- **Class Members/Attributes/Fields**: `PascalCase`
- **Template Parameters**: `PascalCase`
- **Function Parameters**: `camelCase`
- **Lambda**: `camelCase`
- **Aliases**: `PascalCase`
- **Guards**: `MACRO_CASE` (e.g., `HEADER_H`)
- **Enum Types**: `PascalCase`
- **Enum Values**: `MACRO_CASE`

### Example:
```cpp
namespace MyNamespace {
    class MyClass {
    public:
        static int StaticMember;
        int instanceField;

        MyClass(int param);

        void MyFunction(int someValue);
    };

    enum MyEnum {
        VALUE_ONE,
        VALUE_TWO
    };
}
```

### File and Folder Naming:
- Folders and file names should follow `snake_case`. Example:
  - Folder: `game_engine`
  - File: `game_engine.cpp`

---

## Documentation Standards

We use **Doxygen** for documentation. Please ensure that all new classes, functions, and important code elements are well-documented according to the following guidelines:

### File Header
Each file should start with a comment that explains its purpose:
```cpp
/**
 * @file file_name.h
 * @brief Brief description of the file.
 */
```

### Class and Struct Documentation
```cpp
/**
 * @class MyClass
 * @brief Brief description of the class.
 */
```

### Function Documentation
Document each function with `@param` and `@return` tags:
```cpp
/**
 * @brief Brief description of the function.
 * @param paramName Description of the parameter.
 * @return Description of the return value.
 */
```

### Enum Documentation
```cpp
/**
 * @enum MyEnum
 * @brief Brief description of the enum.
 */
```

For more detailed documentation standards, refer to our [documentation guide](./Documentation.md).

---

## Pull Requests

Please ensure your contributions:
- Follow the naming conventions and documentation standards mentioned above.
- Include tests where applicable.
- Are well-formatted and easy to read.
- Have commit messages that explain the purpose of the changes.

---

## Setting Up the Project

### Prerequisites
- Ensure you have the necessary build tools installed, including `CMake`,  `vcpkg` and any required libraries.
- Follow the instructions in the `README.md` for setting up the development environment.

### Building the Project
To build the project:
```bash
cmake .
make
```

For more detailed build instructions, refer to the [build guide](./Building.md).

---

## Thank You!

We appreciate your contribution to improving the project!
