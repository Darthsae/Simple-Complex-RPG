# Contributing to the Project

Thank you for considering contributing to this project! Please follow these guidelines to ensure that your contribution aligns with the project’s coding style and standards.

## Design Goals
[Design Goals](./DESIGN_GOALS.md)

## Code Quality
[Code Quality](./CODE_QUALITY.md)

## Testing
[Testing](./TESTING.md)

## Architecture
[Architecture](./ARCHITECTURE.md)

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
// File: my_project/game_engine.h

#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

namespace GameEngine {

    // Constant definition
    #define MAX_ENTITIES 1000

    // Template type with PascalCase naming
    template <typename EntityType>
    class EntityManager {
    public:
        static int DefaultCapacity; // Static variable in PascalCase

        EntityManager();

        // Function in PascalCase with function parameters in camelCase
        void AddEntity(EntityType entity);
        
        // Getter using PascalCase for functions
        EntityType GetEntity(int entityId) const;

    private:
        int entityCount; // Instance field in camelCase
    };

    // Enum type in PascalCase, values in MACRO_CASE
    enum EntityState {
        ACTIVE,
        INACTIVE,
        DESTROYED
    };

    class Renderer {
    public:
        static constexpr int MaxRenderDistance = 500; // Static constant with PascalCase
        int renderDistance; // Instance member in camelCase

        Renderer();
        void RenderScene(int sceneId);
    };

    // Inline function using PascalCase and lambda with camelCase
    inline auto FindEntity = [](int entityId) { return entityId >= 0; };
}

// Guards following MACRO_CASE
#endif // GAME_ENGINE_H
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

For more detailed documentation standards, refer to our [documentation guide](./DOCUMENTATION.md).

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

For more detailed build instructions, refer to the [build guide](./BUILDING.md).

---

## Thank You!

We appreciate your contribution to improving the project!
